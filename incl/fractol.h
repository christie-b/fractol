/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:18:40 by cboutier          #+#    #+#             */
/*   Updated: 2021/07/23 11:08:31 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx_linux/mlx.h"
# include "defines.h"
# include "structs.h"
# include <unistd.h>
# include <stdlib.h>

/* FRACTAL SETS */
void	mandelbrot(t_data *img, t_vars *vars);
void	julia(t_data *img, t_vars *vars);
void	burning_ship(t_data *img, t_vars *vars);
void	set_julia_params(t_args *args, t_vars *vars);

/* CALCULATIONS */
double	norm_sq(t_imgn *num);
void	iter(t_imgn *z, t_imgn c);
void	abs_iter(t_imgn *z, t_imgn c);
int		calculate_fractal(t_vars *vars);

/* COLORS */
int		create_trgb(int t, int r, int g, int b);
void	colors(t_vars *vars);
void	color_shift(t_vars *vars);

/* EVENTS */
int		key_pressed(int keycode, t_vars *vars);
int		mouse_hook(int keycode, int x, int y, t_vars *vars);
int		close_win(t_vars *vars);
void	init_pos(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	px_to_im(int x, int y, t_imgn *num, t_vars *vars);
void	call_fractal(t_vars *vars, t_data *img);

/*utils*/
int		ft_isdigit(int c);
double	ft_abs(double nbr);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);
double	ft_atod(char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif