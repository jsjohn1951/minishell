/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:29:15 by wismith           #+#    #+#             */
/*   Updated: 2022/06/06 20:29:50 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

/* ft_printf.c */
int		ft_printf(const char *s, ...);

/* ft_put.c */
int		ft_putchr(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);

/* ft_put_u.c */
int		ft_putnbr_u(unsigned int n);

/* ft_put_hex.c */
int		ft_puthex(unsigned int num, char c);

/* ft_putptr.c */
int		ft_putptr(unsigned long int num);

/* ft_int_min.c */
int		ft_min(void);
#endif