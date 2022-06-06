/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:39:07 by wismith           #+#    #+#             */
/*   Updated: 2021/09/27 16:46:58 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	int	upper;
	int	lower;

	upper = 65;
	lower = 97;
	if (c >= 65 && c <= 90)
	{
		while (upper != c)
		{
			upper++;
			lower++;
		}
		return (lower);
	}
	else
		return (c);
}
