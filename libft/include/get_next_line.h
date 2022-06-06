/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:29:45 by wismith           #+#    #+#             */
/*   Updated: 2022/03/15 21:35:41 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100000
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int		ft_strlen_mod(char *s);
int		ft_nlel(char *s);
char	*ft_rtnline(char *s);
char	*ft_rtnsave(char *s);
char	*get_next_line(int fd);
char	*ft_free(char *s);
#endif