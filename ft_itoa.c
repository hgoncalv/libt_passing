/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoncalv <hgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:29:10 by hgoncalv          #+#    #+#             */
/*   Updated: 2021/03/04 11:30:16 by hgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			countdigits(int n)
{
	unsigned int	i;
	unsigned int	absn;

	i = 0;
	if (n <= 0)
		i++;
	absn = abs(n);
	while (absn > 0)
	{
		i++;
		absn /= 10;
	}
	return (i);
}

static unsigned int	absret(int i)
{
	if (i >= 0)
		return (i);
	else
		return (-i);
}

char				*ft_itoa(int n)
{
	int				i;
	unsigned int	absn;
	char			*buf;
	unsigned int	len;

	n = n * 1;
	len = countdigits(n);
	buf = malloc((len + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = 0;
	absn = absret(n);
	if (n < 0)
		buf[0] = '-';
	if (n == 0)
		buf[0] = '0';
	while (absn > 0)
	{
		buf[len - 1 - i++] = absn % 10 + '0';
		absn /= 10;
	}
	buf[len] = '\0';
	return (buf);
}
