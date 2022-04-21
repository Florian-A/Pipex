/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 02:50:37 by f██████           #+#    #+#             */
/*   Updated: 2022/03/29 14:39:36 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*

Use the standard input of the input file to send it to the first command and \
send the result in the first pipe.

*/
void	first_exec(t_list *cmd_lst, t_pipex *pipex)
{	
	if ((int)pipex->input_fd != -1)
	{
		if (dup2(pipex->input_fd, 0) == -1)
			fatal_error(pipex, E_DUP2);
	}
	else
		if (close(0) == -1)
			fatal_error(pipex, E_CLOSE);
	if (dup2(((t_cmd *)cmd_lst->content)->pipe[1], 1) == -1)
		fatal_error(pipex, E_DUP2);
	if (close(((t_cmd *)cmd_lst->content)->pipe[0]) == -1)
		fatal_error(pipex, E_CLOSE);
	if (close(pipex->input_fd) == -1)
		fatal_error(pipex, E_CLOSE);
	exec_cmd(((t_cmd *)cmd_lst->content), pipex);
}

/*

Use the output of the previous pipe as standard input for the command and \ 
send the result into a new pipe.

*/
void	middle_exec(t_list *cmd_lst, t_pipex *pipex)
{
	if (dup2(((t_cmd *)cmd_lst->previous->content)->pipe[0], 0) == -1)
		fatal_error(pipex, E_DUP2);
	if (dup2(((t_cmd *)cmd_lst->content)->pipe[1], 1) == -1)
		fatal_error(pipex, E_DUP2);
	if (close(((t_cmd *)cmd_lst->content)->pipe[1]) == -1)
		fatal_error(pipex, E_CLOSE);
	if (close(((t_cmd *)cmd_lst->previous->content)->pipe[0]) == -1)
		fatal_error(pipex, E_CLOSE);
	exec_cmd(((t_cmd *)cmd_lst->content), pipex);
}

/*

Use the output of the previous pipe as standard input for the command and \ 
send the result into in output file.

*/
void	last_exec(t_list *cmd_lst, t_pipex *pipex)
{
	if (close(((t_cmd *)cmd_lst->content)->pipe[1]) == -1)
		fatal_error(pipex, E_CLOSE);
	if (close(((t_cmd *)cmd_lst->content)->pipe[0]) == -1)
		fatal_error(pipex, E_CLOSE);
	if (dup2(((t_cmd *)cmd_lst->previous->content)->pipe[0], 0) == -1)
		fatal_error(pipex, E_DUP2);
	if (pipex->output_fd < 0)
	{
		if (dup2(0, 1) == -1)
			fatal_error(pipex, E_DUP2);
	}
	else
		if (dup2(pipex->output_fd, 1) == -1)
			fatal_error(pipex, E_DUP2);
	if (close(((t_cmd *)cmd_lst->previous->content)->pipe[0]) == -1)
		fatal_error(pipex, E_CLOSE);
	exec_cmd(((t_cmd *)cmd_lst->content), pipex);
}

/*

Run the command if it is executable, otherwise, show error.

*/
void	exec_cmd(t_cmd *cmd, t_pipex *pipex)
{
	char	**env;

	env = pipex->env;
	if (cmd->path_args[0] == NULL && pipex->is_error == 0)
		fatal_error(pipex, E_CMD);
	if (access(cmd->path_args[0], X_OK) == 0)
		if (execve(cmd->path_args[0], cmd->path_args, env) == -1)
			fatal_error(pipex, E_EXECVE);
}
