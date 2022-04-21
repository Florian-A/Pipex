/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree_pnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:09:35 by f██████           #+#    #+#             */
/*   Updated: 2022/03/10 17:13:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_arrfree_pnt(void **arr)
{
	int	arr_len;
	int	i;

	arr_len = ft_arrlen_pnt((void **)arr);
	i = 0;
	while (i < arr_len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
