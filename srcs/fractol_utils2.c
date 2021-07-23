/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:17:38 by cboutier          #+#    #+#             */
/*   Updated: 2021/07/23 10:18:58 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst > src)
	{
		while (len-- > 0)
			dest[len] = source[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}

double	ft_atod(char *str)
{
	int		sign;
	size_t	integer;
	size_t	floating;
	int		pow;

	sign = 1;
	integer = 0;
	floating = 0;
	pow = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
		integer = integer * 10 + *(str++) - '0';
	if (*str == '.')
		str++;
	while (*str && ft_isdigit(*str))
	{
		floating = floating * 10 + *(str++) - '0';
		pow *= 10;
	}
	return (sign * ((double)integer + ((double)floating / pow)));
}
