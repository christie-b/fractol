/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:11:53 by cboutier          #+#    #+#             */
/*   Updated: 2021/07/23 10:18:02 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	px_to_im(int x, int y, t_imgn *num, t_vars *vars)
{
	num->r = (double)x / (double)WIN_W * vars->zoom.x + vars->pos.x;
	num->i = (double)y / (double)WIN_H * vars->zoom.y + vars->pos.y;
}

double	norm_sq(t_imgn *num)
{
	double	norm;

	norm = num->i * num->i + num->r * num->r;
	return (norm);
}

void	iter(t_imgn *z, t_imgn c)
{
	double	tmp;

	tmp = z->r * z->r - z->i * z->i;
	z->i = 2 * z->r * z->i + c.i;
	z->r = tmp + c.r;
}

void	abs_iter(t_imgn *z, t_imgn c)
{
	double	tmp;

	tmp = z->r * z->r - z->i * z->i;
	z->i = 2 * ft_abs(z->r) * ft_abs(z->i) + c.i;
	z->r = tmp + c.r;
}
