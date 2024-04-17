/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:38:07 by memahote          #+#    #+#             */
/*   Updated: 2023/11/14 11:14:02 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_struct
{
	int	fd_in;
	int	fd_out;
	int	p_fd[2];
	int	first_child_pid;
	int	second_child_pid;
	int	exitstatus;

}		t_struct;

char	*get_path_from_envp(char **envp);
void	ft_free_tab(char **tab);
void	ft_close_all(t_struct *data);
void	exit_fork(t_struct *data);
void	exit_pipe(t_struct *data);
char	*get_path(char *cmd, char **envp);
void	do_cmd(char *cmd, char **envp, t_struct *data);
void	child_process(char **argv, t_struct *data, char **envp);
void	second_child_process(char **argv, t_struct *data, char **envp);
char	*check_absolut_path(char **command);
void	if_no_outfile(t_struct *data);
void	check_dup(int fd, int input);
void	do_cmd_bonus(char *cmd, char **envp, t_struct *data);
#endif
