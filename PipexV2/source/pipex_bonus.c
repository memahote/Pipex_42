/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:41:04 by memahote          #+#    #+#             */
/*   Updated: 2023/10/26 16:28:11 by memahote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0644);
	return (file);
}

void	do_pipe(char *argv, char **envp, t_struct *data)
{
	int	pid;

	if (pipe(data->p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		close(data->p_fd[0]);
		dup2(data->p_fd[1], 1);
		do_cmd_bonus(argv, envp, data);
	}
	else
	{
		close(data->p_fd[1]);
		dup2(data->p_fd[0], 0);
	}
}

void	here_doc(char *limiter, int argc, t_struct *data)
{
	int		pid;
	char	*line;

	if (argc < 6)
		exit(1);
	if (pipe(data->p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == 0)
	{
		close(data->p_fd[0]);
		line = get_next_line(0);
		while (line)
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(data->p_fd[1], line, ft_strlen(line));
			line = get_next_line(0);
		}
	}
	else
	{
		close(data->p_fd[1]);
		dup2(data->p_fd[0], 0);
	}
}

void	execute_last_cmd(char *cmd, char **envp, t_struct *data)
{
	pid_t	child;

	child = fork();
	if (child > 0)
		waitpid(child, NULL, 0);
	else
		do_cmd_bonus(cmd, envp, data);
}

int	main(int argc, char **argv, char **envp)
{
	int			i;
	t_struct	data;

	if (argc < 5)
		exit(1);
	ft_bzero(&data, sizeof(t_struct));
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		data.fd_out = open_file(argv[argc - 1], 0);
		here_doc(argv[2], argc, &data);
	}
	else
	{
		i = 2;
		data.fd_out = open_file(argv[argc - 1], 1);
		data.fd_in = open_file(argv[1], 2);
		dup2(data.fd_in, 0);
	}
	while (i < argc - 2)
		do_pipe(argv[i++], envp, &data);
	dup2(data.fd_out, 1);
	execute_last_cmd(argv[argc - 2], envp, &data);
	return (0);
}
