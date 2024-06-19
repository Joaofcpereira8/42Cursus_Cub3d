/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:59:12 by bbento-e          #+#    #+#             */
/*   Updated: 2024/06/19 18:07:32 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = cub()->bg->addr + (y * cub()->bg->llen + x * (cub()->bg->bpp / 8));
	*(int *)dst = color;
}

void	draw_bkgnd(int ceil, int flr)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y <= (HEIGHT / 2))
				my_mlx_pixel_put(x, y, ceil);
			if (y > (HEIGHT / 2))
				my_mlx_pixel_put(x, y, flr);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(cub()->mlx, cub()->win, cub()->bg->img, 0, 0);
}
