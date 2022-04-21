/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:50:11 by f██████           #+#    #+#             */
/*   Updated: 2022/03/29 17:07:28 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*

Opening the output file or if the file does not exist, it will be created and \
copy file descriptor in pipex struct.

*/
void	analyze_output(char *path, t_pipex *pipex)
{
	if (pipex->is_here_doc)
		pipex->output_fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0000644);
	else
		pipex->output_fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (pipex->output_fd < 0)
		input_error(OUTPUT);
}
