/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:21:05 by wismith           #+#    #+#             */
/*   Updated: 2022/06/06 20:31:43 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_strrev(void *a)
{
	char	*s1;
	char	*s2;
	char	temp;

	s1 = (char *) a;
	s2 = (char *) a + ft_strlen(s1) - 1;
	while (s2 > s1)
	{
		temp = *s1;
		*s1 = *s2;
		*s2 = temp;
		s1++;
		s2--;
	}
	return (a);
}