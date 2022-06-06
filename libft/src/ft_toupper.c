/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:08:04 by wismith           #+#    #+#             */
/*   Updated: 2021/09/27 16:36:11 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	int	lower;
	int	upper;

	lower = 97;
	upper = 65;
	if (c >= 97 && c <= 122)
	{
		while (lower != c)
		{
			lower++;
			upper++;
		}
		return (upper);
	}
	else
		return (c);
}
