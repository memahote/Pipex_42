/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_from_envp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:38:08 by memahote          #+#    #+#             */
/*   Updated: 2023/11/14 13:53:16 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_from_envp(char **envp)
{
	int		i;
	int		j;
	char	*path_name;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		path_name = ft_substr(envp[i], 0, j);
		if (ft_strcomp("PATH", path_name) == 0)
		{
			free(path_name);
			return (envp[i]);
		}
		free(path_name);
		i++;
	}
	return (NULL);
}
