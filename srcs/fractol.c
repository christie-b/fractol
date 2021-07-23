/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:18:43 by cboutier          #+#    #+#             */
/*   Updated: 2021/07/23 11:08:00 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	print_usage_err(void)
{
	ft_putstr_fd("Usage : ./fractol fractal_set [param 1] [param 2]\n",
		STDERR_FILENO);
	ft_putstr_fd("fractal_set: \"julia\", \"mandelbrot\", or \"burning\"\n",
		STDERR_FILENO);
	ft_putstr_fd("Params are for the Julia set only and are optional.\n",
		STDERR_FILENO);
	ft_putstr_fd("[param 1] : Cx [param 2]: Cy\n",
		STDERR_FILENO);
}

int	check_args(t_args *args, t_vars *vars)
{
	if (args->ac != 2 && args->ac != 4)
	{
		print_usage_err();
		close_win(NULL);
	}
	if (args->ac == 2 || args->ac == 4)
	{
		if (ft_strcmp(args->av[1], "mandelbrot") == 0)
			vars->set = MANDELBROT;
		else if (ft_strcmp(args->av[1], "julia") == 0)
			vars->set = JULIA;
		else if (ft_strcmp(args->av[1], "burning") == 0)
			vars->set = BURNING_SHIP;
		else
		{
			ft_putstr_fd(args->av[1], 2);
			ft_putstr_fd(": incorrect fractal set\n", STDERR_FILENO);
			ft_putstr_fd("Must be \"julia\", \"mandelbrot\", or \"burning\"\n",
				STDERR_FILENO);
			close_win(NULL);
		}
	}
	set_julia_params(args, vars);
	return (0);
}

int	calculate_fractal(t_vars *vars)
{
	if (vars->set == MANDELBROT)
		mandelbrot(&vars->data, vars);
	else if (vars->set == JULIA)
		julia(&vars->data, vars);
	else if (vars->set == BURNING_SHIP)
		burning_ship(&vars->data, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}

void	call_fractal(t_vars *vars, t_data *img)
{
	if (vars->set == MANDELBROT)
		mandelbrot(img, vars);
	else if (vars->set == JULIA)
		julia(img, vars);
	else if (vars->set == BURNING_SHIP)
		burning_ship(img, vars);
}

int	main(int ac, char **av)
{
	t_data	img;
	t_vars	vars;
	t_args	args;

	args.ac = ac;
	args.av = av;
	check_args(&args, &vars);
	init_pos(&vars);
	colors(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "Fractol");
	img.img = mlx_new_image(vars.mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len,
			&img.endian);
	call_fractal(&vars, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	vars.data = img;
	mlx_hook(vars.win, 2, 1L << 0, key_pressed, &vars);
	mlx_hook(vars.win, 4, 1L << 2, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 5, close_win, &vars);
	mlx_loop_hook(vars.mlx, calculate_fractal, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
