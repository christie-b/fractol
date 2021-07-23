/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:42:09 by cboutier          #+#    #+#             */
/*   Updated: 2021/07/22 12:05:55 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_zoom
{
	double	x;
	double	y;
}	t_zoom;

typedef struct s_args
{
	int		ac;
	char	**av;
}	t_args;

typedef struct s_imgn
{
	double	i;
	double	r;
}	t_imgn;

typedef struct s_fig
{
	t_imgn	z;
	t_imgn	c;
}	t_fig;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	data;
	t_zoom	zoom;
	t_pos	pos;
	int		set;
	t_fig	fig;
	int		tab[256];
}	t_vars;

#endif