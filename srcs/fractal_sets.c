/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:13:53 by cboutier          #+#    #+#             */
/*   Updated: 2021/07/23 11:21:22 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	mandelbrot(t_data *img, t_vars *vars)
{
	int		x;
	int		y;
	int		i;
	t_fig	fig;
	int		color;

	x = -1;
	while (++x < WIN_W)
	{
		y = -1;
		while (++y < WIN_H)
		{
			i = 0;
			fig.z.r = 0.0;
			fig.z.i = 0.0;
			px_to_im(x, y, &fig.c, vars);
			while (i < MAX_ITER && norm_sq(&fig.z) < 4.0)
			{
				iter(&fig.z, fig.c);
				i++;
			}
			color = vars->tab[i % 256];
			my_mlx_pixel_put(img, x, y, color);
		}
	}
}

void	julia(t_data *img, t_vars *vars)
{
	int		x;
	int		y;
	int		i;
	int		color;

	x = -1;
	while (++x < WIN_W)
	{
		y = -1;
		while (++y < WIN_H)
		{
			i = 0;
			px_to_im(x, y, &vars->fig.z, vars);
			while (i < MAX_ITER && (norm_sq(&vars->fig.z)) < 4.0)
			{
				iter(&vars->fig.z, vars->fig.c);
				i++;
			}
			color = vars->tab[i % 256];
			my_mlx_pixel_put(img, x, y, color);
		}
	}
}

void	burning_ship(t_data *img, t_vars *vars)
{
	int		x;
	int		y;
	int		i;
	t_fig	fig;
	int		color;

	x = -1;
	while (++x < WIN_W)
	{
		y = -1;
		while (++y < WIN_H)
		{
			i = 0;
			fig.z.r = 0.0;
			fig.z.i = 0.0;
			px_to_im(x, y, &fig.c, vars);
			while (i < MAX_ITER && norm_sq(&fig.z) < 4.0)
			{
				abs_iter(&fig.z, fig.c);
				i++;
			}
			color = vars->tab[i % 256];
			my_mlx_pixel_put(img, x, y, color);
		}
	}
}

void	check_julia_params(char *str)
{
	int	i;

	i = 0;
	if (!(*str))
	{
		ft_putstr_fd(": invalid parameter\n", STDERR_FILENO);
		exit(0);
	}
	while (*str)
	{
		if (!(ft_isdigit(*str)) && *str != '.'
			&& *str != '-' && *str != '+')
		{
			while (i)
			{
				str--;
				i--;
			}
			ft_putstr_fd(str, STDERR_FILENO);
			ft_putstr_fd(": invalid parameter\n", STDERR_FILENO);
			exit(0);
		}
		str++;
		i++;
	}
}

void	set_julia_params(t_args *args, t_vars *vars)
{
	if (args->ac == 4 && vars->set == JULIA)
	{
		check_julia_params(args->av[2]);
		check_julia_params(args->av[3]);
		vars->fig.c.r = ft_atod(args->av[2]);
		vars->fig.c.i = ft_atod(args->av[3]);
	}
	if (args->ac == 2 && vars->set == JULIA)
	{
		vars->fig.c.r = -0.7;
		vars->fig.c.i = 0.27015;
	}
}
