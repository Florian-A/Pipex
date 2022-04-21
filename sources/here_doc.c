/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:16:09 by f██████           #+#    #+#             */
/*   Updated: 2022/04/09 19:25:59 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*

Copy the standard input to the default file descriptor that will be read when \
executing commands.

*/
void	here_doc(t_pipex *pipex, char *limiter)
{
	char	*s1;

	pipex->is_here_doc = 1;
	s1 = get_here_doc_input(pipex, limiter);
	if (!s1)
		fatal_error(pipex, E_MALLOC);
	pipex->here_doc_fd = open("/tmp/.pipex_here_doc", O_WRONLY \
	| O_CREAT | O_TRUNC | O_CLOEXEC, 0644);
	if (pipex->here_doc_fd < 0)
		fatal_error(pipex, E_HERE_DOC);
	ft_putstr_fd(s1, pipex->here_doc_fd);
	free(s1);
	close(pipex->here_doc_fd);
	pipex->here_doc_fd = open("/tmp/.pipex_here_doc", O_RDONLY);
	if (pipex->here_doc_fd < 0)
		fatal_error(pipex, E_HERE_DOC);
	if (dup2(pipex->here_doc_fd, 0) == -1)
		fatal_error(pipex, E_DUP2);
	if (close(pipex->here_doc_fd) == -1)
		fatal_error(pipex, E_CLOSE);
	if (unlink("/tmp/.pipex_here_doc") == -1)
		fatal_error(pipex, E_HERE_DOC);
}

/*

Return the text which in of standard input.

*/
char	*get_here_doc_input(t_pipex *pipex, char *limiter)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s2 = ft_calloc(1, sizeof(char *));
	while (1)
	{
		write(1, "> ", 2);
		s1 = get_next_line(0);
		if (!s1 || (ft_strncmp(limiter, s1, ft_strlen(s1) - 1) == 0 && \
		ft_strncmp("\n", s1, 1) != 0 && ft_strlen(limiter) == ft_strlen(s1) - 1) \
		|| (!limiter[0] && s1[0] == '\n' ))
			break ;
		s3 = ft_strdup(s2);
		if (!s3)
			fatal_error(pipex, E_MALLOC);
		free(s2);
		s2 = ft_strjoin(s3, s1);
		if (!s2)
			fatal_error(pipex, E_MALLOC);
		ft_free_m(2, s1, s3);
	}
	free(s1);
	return (s2);
}

/*

Use here_doc input to send it to the first command and send the result \
in the first pipe.

*/
void	first_exec_here_doc(t_list *cmd_lst, t_pipex *pipex)
{
	if (dup2(((t_cmd *)cmd_lst->content)->pipe[1], 1) == -1)
		fatal_error(pipex, E_DUP2);
	if (close(((t_cmd *)cmd_lst->content)->pipe[0]) == -1)
		fatal_error(pipex, E_CLOSE);
	exec_cmd(((t_cmd *)cmd_lst->content), pipex);
}
