/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:55:14 by f██████           #+#    #+#             */
/*   Updated: 2022/04/10 00:39:13 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*

Transforms commands with their arguments to executables paths and copy this \
in pipex struct.

*/
void	analyse_cmds(int argc, char **argv, t_pipex *pipex)
{
	int	i;
	int	j;

	if (pipex->is_here_doc == 1)
	{
		pipex->nb_cmd = argc - 4;
		j = 3;
	}
	else
	{
		pipex->nb_cmd = argc - 3;
		j = 2;
	}
	i = 0;
	while (i < pipex->nb_cmd)
	{
		if (!transform_argv_to_cmd(i, argv[j], pipex))
			fatal_error(pipex, E_MALLOC);
		i++;
		j++;
	}
}

/*

Test if the argument is executable otherwise will search path of this command \
and add the executable path in linked list.

*/
int	transform_argv_to_cmd(int i, char *argv, t_pipex *pipex)
{
	char	*cmd1;
	t_cmd	*scmd;

	scmd = ft_calloc(1, sizeof(t_cmd));
	if (!scmd)
		return (0);
	cmd1 = ft_strtrim(argv, " ");
	if (!cmd1)
		return (0);
	scmd->path_args = ft_split(cmd1, ' ');
	free(cmd1);
	if (!scmd->path_args)
		return (0);
	if (access(scmd->path_args[0], X_OK) != 0)
		if (!replace_cmd_to_path(scmd, pipex))
			return (0);
	add_scmd_to_lst(i, scmd, pipex);
	return (1);
}

void	add_scmd_to_lst(int i, t_cmd *scmd, t_pipex *pipex)
{
	if (i == 0)
		pipex->cmd_lst = ft_lstnew(scmd);
	else
		ft_lstadd_back(&pipex->cmd_lst, ft_lstnew(scmd));
}
