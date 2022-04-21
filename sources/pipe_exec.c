/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 02:50:37 by f██████           #+#    #+#             */
/*   Updated: 2022/04/08 00:43:24 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*

 * Duplicate the process (clone of him self) and create a tube which allows to \ 
exchange of inputs and outputs between programs.

! Process that was duplicated is named "child".
! Process that is not the result of this duplication is named "parent".

*/
void	pipe_exec(t_pipex *pipex)
{
	int		i;
	t_list	*cmd_lstc;

	i = 0;
	cmd_lstc = pipex->cmd_lst;
	while (i < pipex->nb_cmd)
	{
		if (pipe(((t_cmd *)cmd_lstc->content)->pipe) == -1)
			fatal_error(pipex, E_PIPE);
		((t_cmd *)cmd_lstc->content)->pid = fork();
		if (((t_cmd *)cmd_lstc->content)->pid == -1)
			fatal_error(pipex, E_FORK);
		if (((t_cmd *)cmd_lstc->content)->pid == 0)
			child_exec(i, cmd_lstc, pipex);
		else
		{
			if (close(((t_cmd *)cmd_lstc->content)->pipe[1]) == -1)
				fatal_error(pipex, E_CLOSE);
			if (cmd_lstc->next)
				cmd_lstc = cmd_lstc->next;
		}
		i++;
	}
	parent_wait(cmd_lstc, pipex);
	return ;
}

/*

* Child process will execute commands with different behavior if :
 - first command
 - last command
 - or the commands between first and last.

*/
void	child_exec(int i, t_list *cmd_lst, t_pipex *pipex)
{
	if (i == 0 && pipex->is_here_doc == 0)
		first_exec(cmd_lst, pipex);
	else if (i == 0 && pipex->is_here_doc == 1)
		first_exec_here_doc(cmd_lst, pipex);
	else if (i != 0 && i == (pipex->nb_cmd - 1))
		last_exec(cmd_lst, pipex);
	else
		middle_exec(cmd_lst, pipex);
}

/*

Parent process closes child's standard inputs, wait end of process \
and repeats these actions for each child.

*/
void	parent_wait(t_list *cmd_lst, t_pipex *pipex)
{
	int		i;
	t_list	*cmd_lstc;
	int		status;

	cmd_lstc = ft_lstfirst(cmd_lst);
	i = 0;
	while (i < pipex->nb_cmd)
	{
		if (close(((t_cmd *)cmd_lstc->content)->pipe[0]) == -1)
			fatal_error(pipex, E_CLOSE);
		waitpid(((t_cmd *)cmd_lstc->content)->pid, &status, 0);
		cmd_lstc = cmd_lstc->next;
		i++;
	}
}
