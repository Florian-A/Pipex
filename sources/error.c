/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:16:09 by f██████           #+#    #+#             */
/*   Updated: 2022/03/29 17:13:08 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*

Display errors with "ft_printf" function when improper use "input_error" and  \
"fatal_error" function when it is a system problem.

*/
void	usage_error(t_pipex *pipex, char *msg)
{
	cleaning(pipex);
	ft_printf("%s", msg);
	exit(EXIT_FAILURE);
}

void	input_error(char *msg)
{
	perror(msg);
}

void	fatal_error(t_pipex *pipex, char *msg)
{
	if (pipex->is_error == 0)
		ft_dprintf(2, "%s", msg);
	pipex->is_error = 1;
	cleaning(pipex);
	exit(EXIT_FAILURE);
}
