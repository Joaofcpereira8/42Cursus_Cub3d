/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:31:25 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/19 17:23:25 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	asgn_txtr(void)
{
	if (cub()->ori == 'H')
	{
		if (cub()->rayy >= 0)
			(cub()->cr = cub()->no);
		else
			(cub()->cr = cub()->so);
	}
	else
	{
		if (cub()->rayx < 0)
			(cub()->cr = cub()->ea);
		else
			(cub()->cr = cub()->ws);
	}
}

void	wall_e(void)
{
	if (cub()->ori == 'V')
	{
		cub()->wallx = cub()->ply + cub()->perpend_wl * cub()->rayy;
		cub()->wallx -= floor(cub()->wallx);
	}
	if (cub()->ori == 'H')
	{
		cub()->wallx = cub()->plx + cub()->perpend_wl * cub()->rayx;
		cub()->wallx -= floor(cub()->wallx);
	}
}

int ft_get_pickle(int x, int y)
{
	return (*(int *)((cub()->cr->addr + (y * cub()->cr->llen) + (x * cub()->cr->bpp / DIVB))));
}


void	draw(int x)
{
	int	y;
	int	color;

	cub()->imgx = (int)(cub()->wallx * (double)IMG_W);
	cub()->imgx = IMG_W - cub()->imgx - 1;
	cub()->imgstp = 1.0 * IMG_W / cub()->line_h;
	cub()->imgpos = (cub()->begn_draw - HEIGHT / 2
		+ cub()->line_h / 2) * cub()->imgstp;
	y = cub()->begn_draw;
	while (y < cub()->end_draw)
	{
		cub()->imgy = (int)cub()->imgpos & (IMG_H - 1);
		cub()->imgpos += cub()->imgstp;
		if (x >= 0 && y >= 0 && cub()->imgx >= 0 && cub()->imgy >= 0)
		{
			color = ft_get_pickle(cub()->imgx, cub()->imgy);
			my_mlx_pixel_put(x, y, color);
		}
		y++;
	}
}
