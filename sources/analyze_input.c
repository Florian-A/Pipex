/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:50:11 by f██████           #+#    #+#             */
/*   Updated: 2022/03/29 17:08:07 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*

Opening the input file in read only and copy file descriptor in pipex struct.

*/
void	analyze_input(char *path, t_pipex *pipex)
{
	if (pipex->is_here_doc == 0)
	{
		pipex->input_fd = open(path, O_RDONLY);
		if (pipex->input_fd < 0)
		{
			pipex->input_fd = open("/dev/null", O_RDONLY);
			input_error(INPUT);
		}
	}
}
