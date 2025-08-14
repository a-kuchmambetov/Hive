/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <akuchmam@student.hive.fi>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-05 14:35:05 by Artem             #+#    #+#             */
/*   Updated: 2025-08-05 14:35:05 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int first_child(int pipefd[2], char *infile, char *cmd1) {
    const char *args[] = {"sh", "-c", cmd1, NULL};
    const pid_t pid1 = fork();
    int fdin;

    if (pid1 == 0) {
        // First child: cmd1, stdin=infile, stdout=pipe
        fdin = open(infile, O_RDONLY);
        if (fdin < 0) {
            perror("open infile");
            exit(1);
        }
        dup2(fdin, STDIN_FILENO);       // stdin = infile
        dup2(pipefd[1], STDOUT_FILENO); // stdout = pipe write end
        close(fdin);
        close(pipefd[0]); // close unused read end
        close(pipefd[1]);
        execve("/bin/sh", args, NULL);
        perror("execve cmd1"); 
    }
    return pid1;
}

static int second_child(int pipefd[2], char *outfile, char *cmd2) {
    const char *args[] = {"sh", "-c", cmd2, NULL};
    const pid_t pid2 = fork();
    int fdout;

    if (pid2 == 0) {
        fdout = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fdout < 0) {
            perror("open outfile");
            exit(1);
        }
        dup2(pipefd[0], STDIN_FILENO);  // stdin = pipe read end
        dup2(fdout, STDOUT_FILENO);     // stdout = outfile
        close(fdout);
        close(pipefd[0]);
        close(pipefd[1]); // close unused write end
        execve("/bin/sh", args, NULL);
        perror("execve cmd2");
    }
    return pid2;
}

int main(int argc, char *argv[]) {
    int pipefd[2];
    int pid1;
    int pid2;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
        return (1);
    }
    if (pipe(pipefd) == -1) { 
        perror("pipe"); 
        return 1; 
    }
    pid1 = first_child(pipefd, argv[1], argv[2]);
    pid2 = second_child(pipefd, argv[4], argv[3]);
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}
