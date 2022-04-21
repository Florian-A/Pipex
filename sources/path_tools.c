/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:16:09 by f██████           #+#    #+#             */
/*   Updated: 2022/04/10 00:37:53 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*

Return the PATH variable saved in the environment.

*/
char	*get_env_paths(t_pipex *pipex)
{
	int		arr_len;
	int		line_len;
	int		i;
	char	*path;

	arr_len = ft_arrlen_pnt((void **)pipex->env);
	path = NULL;
	i = 0;
	while (i < arr_len)
	{
		line_len = ft_strlen(pipex->env[i]);
		path = ft_strnstr(pipex->env[i], "PATH=", line_len);
		if (path != NULL)
			return (&path[5]);
		i++;
	}
	return (NULL);
}

/*

Returns when possible the executable path of a command.

*/
char	*search_cmd_path(char *cmd, char **paths)
{
	char	*cmd_path1;
	char	*cmd_path2;
	int		arr_len;
	int		i;

	arr_len = ft_arrlen_pnt((void **)paths);
	i = 0;
	while (i < arr_len)
	{
		cmd_path1 = ft_strjoin(paths[i], "/");
		if (!cmd_path1)
			return (NULL);
		cmd_path2 = ft_strjoin(cmd_path1, cmd);
		if (!cmd_path2)
			return (NULL);
		free(cmd_path1);
		if (access(cmd_path2, X_OK) == 0)
		{
			ft_arrfree_pnt((void **)paths);
			return (cmd_path2);
		}
		free(cmd_path2);
		i++;
	}
	return (NULL);
}

/*

Replace command name to a executable path.

*/
int	replace_cmd_to_path(t_cmd	*scmd, t_pipex *pipex)
{
	char	*cmd;

	if (scmd->path_args[0] != NULL)
	{
		cmd = ft_strdup(scmd->path_args[0]);
		if (!cmd)
			return (0);
		free(scmd->path_args[0]);
		scmd->path_args[0] = convert_cmd_to_path(&cmd[0], pipex);
		free(cmd);
	}
	return (1);
}

/*

Convert command name to a executable path.

*/
char	*convert_cmd_to_path(char *cmd, t_pipex *pipex)
{
	char	*env_path;
	char	**paths;

	env_path = get_env_paths(pipex);
	if (env_path)
	{
		paths = ft_split(env_path, ':');
		if (!paths)
			return (NULL);
	}
	else
		return (NULL);
	return (search_cmd_path(cmd, paths));
}
