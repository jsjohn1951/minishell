/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:37:47 by wismith           #+#    #+#             */
/*   Updated: 2022/02/20 22:32:59 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*start;

	if (lst == NULL)
		return ;
	start = *lst;
	while (start)
	{
		del(start->content);
		free(start);
		start = start->next;
	}
	*lst = NULL;
}
