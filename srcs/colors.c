/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:09:21 by cboutier          #+#    #+#             */
/*   Updated: 2021/07/23 10:18:16 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	colors(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		vars->tab[i] = create_trgb(0, i << 1, i << 3, i << 4);
		i++;
	}
}

void	color_shift(t_vars *vars)
{
	int	tmp;

	tmp = vars->tab[255];
	ft_memmove((int *)vars->tab + 1, (int *)vars->tab, 255 * sizeof(int));
	vars->tab[0] = tmp;
}
