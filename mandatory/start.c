/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:59:12 by bbento-e          #+#    #+#             */
/*   Updated: 2024/06/06 19:27:41 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = cub()->bg->addr + (y * cub()->bg->llen + x * (cub()->bg->bpp / 8));
	*(unsigned int *)dst = color;
}

void draw_bkgnd(int ceil, int flr)
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

int	start()
{

	return (draw_textures());
}

int	draw_textures()
{
	cub()->bg->img = mlx_new_image(cub()->mlx, WIDTH, HEIGHT);
	cub()->no->img = mlx_xpm_file_to_image(cub()->mlx,
		cub()->north, &cub()->no->width, &cub()->no->height);
	cub()->so->img = mlx_xpm_file_to_image(cub()->mlx,
		cub()->south, &cub()->so->width, &cub()->so->height);
	cub()->ea->img = mlx_xpm_file_to_image(cub()->mlx,
		cub()->east, &cub()->ea->width, &cub()->ea->height);
	cub()->ws->img = mlx_xpm_file_to_image(cub()->mlx,
		cub()->west, &cub()->ws->width, &cub()->ws->height);

	if (!cub()->no->img || !cub()->so->img || !cub()->ea->img || !cub()->ws->img)
		return (file_err_msg('T', 0));
	return (0);
}