#include "main.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
        return (1);
    }

    char *infile = argv[1];
    char *cmd1 = argv[2];
    char *cmd2 = argv[3];
    char *outfile = argv[4];

    int pipefd[2];
    if (pipe(pipefd) == -1) { perror("pipe"); return 1; }

    pid_t pid1 = fork();
    if (pid1 == 0) {
        // First child: cmd1, stdin=infile, stdout=pipe
        int fdin = open(infile, O_RDONLY);
        if (fdin < 0) { perror("open infile"); exit(1); }

        dup2(fdin, STDIN_FILENO);       // stdin = infile
        dup2(pipefd[1], STDOUT_FILENO); // stdout = pipe write end
        close(fdin);
        close(pipefd[0]); // close unused read end
        close(pipefd[1]);

        char *args[] = {"sh", "-c", cmd1, NULL};
        execve("/bin/sh", args, NULL);
        perror("execve cmd1"); exit(1);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        // Second child: cmd2, stdin=pipe, stdout=outfile
        int fdout = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fdout < 0) { perror("open outfile"); exit(1); }

        dup2(pipefd[0], STDIN_FILENO);  // stdin = pipe read end
        dup2(fdout, STDOUT_FILENO);     // stdout = outfile
        close(fdout);
        close(pipefd[0]);
        close(pipefd[1]); // close unused write end

        char *args[] = {"sh", "-c", cmd2, NULL};
        execve("/bin/sh", args, NULL);
        perror("execve cmd2"); exit(1);
    }

    // Parent closes both ends and waits
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}
