/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:16:09 by f██████           #+#    #+#             */
/*   Updated: 2022/04/05 17:35:35 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*

Initialization of the pipex structure and launch here_doc.

*/
void	init_s_pipex(int argc, char **argv, char **env, t_pipex *pipex)
{
	pipex->cmd_lst = NULL;
	pipex->input_fd = 0;
	pipex->output_fd = 0;
	pipex->nb_cmd = 0;
	pipex->is_error = 0;
	pipex->is_here_doc = 0;
	pipex->env = env;
	if (is_bonus())
	{
		if (argv[1] && ft_strcmp("here_doc", argv[1]) == 0)
		{
			if (argc < 6)
				usage_error(pipex, USAGE_B);
			here_doc(pipex, argv[2]);
		}
		else if (argc < 5)
			usage_error(pipex, USAGE_B);
	}
	else if (argc != 5)
		usage_error(pipex, USAGE_M);
}
