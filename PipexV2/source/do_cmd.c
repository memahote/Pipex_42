/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:41:04 by memahote          #+#    #+#             */
/*   Updated: 2023/11/14 13:56:37 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	no_path(char	*path, char **command, t_struct *data)
{
	ft_putstr_fd(command[0], 2);
	ft_putendl_fd(": command not found", 2);
	ft_free_tab(command);
	if (path)
		free(path);
	ft_close_all(data);
	exit(127);
}

void	do_cmd(char *cmd, char **envp, t_struct *data)
{
	char	*path;
	char	**command;

	path = get_path(cmd, envp);
	command = ft_split(cmd, ' ');
	if (!path)
		no_path(path, command, data);
	if (execve(path, command, envp) < 0)
	{
		ft_putstr_fd(command[0], 2);
		ft_putendl_fd(": command not found", 2);
		ft_free_tab(command);
		if (path)
			free(path);
		ft_close_all(data);
	}
	if (path)
		free(path);
	ft_close_all(data);
}
