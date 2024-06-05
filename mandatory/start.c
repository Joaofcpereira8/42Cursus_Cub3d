/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:59:12 by bbento-e          #+#    #+#             */
/*   Updated: 2024/06/05 18:54:12 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->line_length + x * (data->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void draw_bkgnd()
{
	int	x;
	int	y;

	x = 0;
	while (x <= HEIGHT / 2)
	{
		y = 0;
		while (y < WIDTH)
		{
			my_mlx_pixel_put(x, y, cub()->color);
			y++;
		}
		x++;
	}
	while (x <= HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			my_mlx_pixel_put(x, y, cub()->color);
			y++;
		}
		x++;
	}
}

int	start()
{
	draw_bkgnd();
	return (draw_textures());
}

int	draw_textures()
{
	cub()->fd = open(cub()->north, O_RDONLY);
	if (cub()->fd < 0)
		return (file_err_msg('T', 0));
	else
		close(cub()->fd);
	cub()->fd = open(cub()->south, O_RDONLY);
	if (cub()->fd < 0)
		return (file_err_msg('T', 0));
	else
		close(cub()->fd);
	cub()->fd = open(cub()->east, O_RDONLY);
	if (cub()->fd < 0)
		return (file_err_msg('T', 0));
	else
		close(cub()->fd);
	cub()->fd = open(cub()->west, O_RDONLY);
	if (cub()->fd < 0)
		return (file_err_msg('T', 0));
	else
		close(cub()->fd);
	return (1);
}