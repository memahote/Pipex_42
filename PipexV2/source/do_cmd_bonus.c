/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:29:30 by memahote          #+#    #+#             */
/*   Updated: 2023/10/26 17:32:29 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_cmd_bonus(char *cmd, char **envp, t_struct *data)
{
	char	*path;
	char	**command;

	path = get_path(cmd, envp);
	command = ft_split(cmd, ' ');
	if (!path)
	{
		ft_putstr_fd(command[0], 2);
		ft_putendl_fd(": command not found", 2);
		ft_free_tab(command);
		if (path)
			free(path);
		return ;
	}
	if (execve(path, command, envp) < 0)
	{
		ft_putstr_fd(command[0], 2);
		ft_putendl_fd(": command not found", 2);
		ft_free_tab(command);
		if (path)
			free(path);
	}
	if (path)
		free(path);
	ft_close_all(data);
}
