/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:59:12 by bbento-e          #+#    #+#             */
/*   Updated: 2024/06/06 15:00:04 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = cub()->bg.addr + (y * cub()->bg.llen + x * (cub()->bg.bpp / 8));
	*(unsigned int *)dst = color;
}

void draw_bkgnd(int ceil, int flr)
{
	int	x;
	int	y;

	x = 0;
	while (x <= HEIGHT / 2)
	{
		y = 0;
		while (y < WIDTH)
		{
			my_mlx_pixel_put(x, y, ceil);
			y++;
		}
		x++;
	}
	while (x <= HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			my_mlx_pixel_put(x, y, flr);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(cub()->mlx_ptr, cub()->win_ptr, cub()->img->img_bg,0, 0);
}

int	start()
{
	draw_bkgnd(create_trgb(cub()->cei, 255), create_trgb(cub()->flo, 255));
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