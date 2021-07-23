/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:20:41 by cboutier          #+#    #+#             */
/*   Updated: 2021/07/23 10:19:04 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	init_pos(t_vars *vars)
{
	if (vars->set == MANDELBROT)
	{
		vars->zoom.x = 3.5;
		vars->zoom.y = 2.0;
		vars->pos.x = -2.5;
		vars->pos.y = -1.0;
	}
	else if (vars->set == JULIA)
	{
		vars->zoom.x = 3.0;
		vars->zoom.y = 2.1;
		vars->pos.x = -1.5;
		vars->pos.y = -1.0;
	}
	else if (vars->set == BURNING_SHIP)
	{
		vars->zoom.x = 4.0;
		vars->zoom.y = 2.5;
		vars->pos.x = -2.0;
		vars->pos.y = -2.0;
	}
}

int	key_pressed(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_win(vars);
	if (keycode == PLUS)
	{
		vars->zoom.x /= 1.1;
		vars->zoom.y /= 1.1;
	}
	if (keycode == MINUS)
	{
		vars->zoom.x *= 1.1;
		vars->zoom.y *= 1.1;
	}
	if (keycode == RIGHT_ARR || keycode == D_KEY)
		vars->pos.x += vars->zoom.y * 0.01;
	if (keycode == LEFT_ARR || keycode == A_KEY)
		vars->pos.x -= vars->zoom.y * 0.01;
	if (keycode == UP_ARR || keycode == W_KEY)
		vars->pos.y -= vars->zoom.y * 0.01;
	if (keycode == DWN_ARR || keycode == S_KEY)
		vars->pos.y += vars->zoom.y * 0.01;
	if (keycode == R_KEY)
		init_pos(vars);
	if (keycode == P_KEY)
		color_shift(vars);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == SCR_UP)
	{
		vars->pos.x += (vars->zoom.x - vars->zoom.x / 1.1)
			/ ((double)WIN_W / x);
		vars->pos.y += (vars->zoom.y - vars->zoom.y / 1.1)
			/ ((double)WIN_H / y);
		vars->zoom.x /= 1.1;
		vars->zoom.y /= 1.1;
	}
	if (keycode == SCR_DWN)
	{
		vars->zoom.x *= 1.1;
		vars->zoom.y *= 1.1;
		vars->pos.x -= (vars->zoom.x - vars->zoom.x / 1.1)
			/ ((double)WIN_W / x);
		vars->pos.y -= (vars->zoom.y - vars->zoom.y / 1.1)
			/ ((double)WIN_H / y);
	}
	return (0);
}
