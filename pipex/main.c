/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-15 12:42:12 by akuchmam          #+#    #+#             */
/*   Updated: 2025-08-15 12:42:12 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static pid_t	first_child(int pipefd[2], char *infile, char *cmd1,
	char *envp[])
{
	char *const	args[4] = {"sh", "-c", cmd1, NULL};
	const pid_t	pid1 = fork();
	int			fdin;

	if (pid1 == 0)
	{
		fdin = open(infile, O_RDONLY);
		if (fdin < 0)
		{
			perror("open infile");
			exit(1);
		}
		dup2(fdin, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(fdin);
		close(pipefd[0]);
		close(pipefd[1]);
		execve("/bin/sh", args, envp);
		perror("execve cmd1");
		exit(1);
	}
	return (pid1);
}

static pid_t	second_child(int pipefd[2], char *outfile, char *cmd2,
	char *envp[])
{
	char *const	args[4] = {"sh", "-c", cmd2, NULL};
	const pid_t	pid2 = fork();
	int			fdout;

	if (pid2 == 0)
	{
		fdout = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fdout < 0)
		{
			perror("open outfile");
			exit(1);
		}
		dup2(pipefd[0], STDIN_FILENO);
		dup2(fdout, STDOUT_FILENO);
		close(fdout);
		close(pipefd[0]);
		close(pipefd[1]);
		execve("/bin/sh", args, envp);
		perror("execve cmd2");
		exit(1);
	}
	return (pid2);
}

static void	print_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

static int	check_argv(int argc, char *argv[])
{
	if (argc != 5)
	{
		print_error("Invalid number of arguments\n");
		return (1);
	}
	if (argv[2] == 0 || argv[3] == 0)
	{
		print_error("Empty command\n");
		return (1);
	}
	if ((ft_strlen(argv[2]) == 1 && ft_strncmp(argv[2], " ", 1) == 0)
		|| (ft_strlen(argv[3]) == 1 && ft_strncmp(argv[3], " ", 1) == 0))
	{
		print_error("Invalid command\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

	if (check_argv(argc, argv) != 0)
		return (1);
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid1 = first_child(pipefd, argv[1], argv[2], envp);
	pid2 = second_child(pipefd, argv[4], argv[3], envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	return (WEXITSTATUS(status2));
}
