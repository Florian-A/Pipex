/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:16:09 by f██████           #+#    #+#             */
/*   Updated: 2022/03/29 17:12:05 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*

Iterates through all the properties of the structure to free them, then at end \
free the structure.

*/
void	cleaning(t_pipex *pipex)
{
	if (pipex->cmd_lst != NULL)
		cleaning_lst(pipex);
}

void	cleaning_lst(t_pipex *pipex)
{
	int		i;
	int		len;
	t_list	*lst1;
	t_list	*lst2;

	lst1 = pipex->cmd_lst;
	while (lst1)
	{
		lst2 = lst1->next;
		len = ft_arrlen_pnt((void **)((t_cmd *)lst1->content)->path_args);
		i = 0;
		while (i <= len)
		{
			if (((t_cmd *)lst1->content)->path_args[i])
				free(((t_cmd *)lst1->content)->path_args[i]);
			i++;
		}
		if (((t_cmd *)lst1->content)->path_args)
			free(((t_cmd *)lst1->content)->path_args);
		if (lst1->content)
			free(lst1->content);
		free(lst1);
		lst1 = lst2;
	}
}
