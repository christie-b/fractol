/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 09:14:19 by cboutier          #+#    #+#             */
/*   Updated: 2021/07/23 11:08:14 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	x;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		x = write(fd, &s[i], 1);
		i++;
	}
	x++;
}

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
	{
		return (1);
	}
	else
		return (0);
}

double	ft_abs(double nbr)
{
	double	abs_nbr;

	abs_nbr = 0.0;
	if (nbr < 0.0)
		abs_nbr = nbr * -1;
	else
		abs_nbr = nbr;
	return (abs_nbr);
}
