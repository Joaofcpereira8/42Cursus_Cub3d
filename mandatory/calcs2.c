/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:31:25 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/18 18:41:02 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*img_picker(char type)
{
	static char	img;

	if (type == 'N' || type == 'S' || type == 'E' || type == 'W')
	{
		img = type;
		if (type == 'N')
			return (cub()->no);
		else if (type == 'S')
			return (cub()->so);
		else if (type == 'E')
			return (cub()->ea);
		else
			return (cub()->ws);
	}
	return (img_picker(img));
}

void	asgn_txtr(void)
{
	if (cub()->ori == 'H')
	{
		if (cub()->rayy >= 0)
			img_picker('N');
		else
			img_picker('S');
	}
	else
	{
		if (cub()->rayx < 0)
			img_picker('E');
		else
			img_picker('W');
	}
}

void	wall_e(void)
{
	if (cub()->ori == 'V')
	{
		cub()->wallx = cub()->ply + cub()->perpend_wl * cub()->rayy;
		cub()->wallx -= floor(cub()->wallx);
	}
	else
	{
		cub()->wallx = cub()->plx + cub()->perpend_wl * cub()->rayx;
		cub()->wallx -= floor(cub()->wallx);
	}
}

int	ft_get_pickle(int x, int y)
{
	t_img	*img;
	int		aux;

	img = img_picker('P');
	aux = (*(int *)((img->addr + (y * img->llen) + (x * img->bpp / 8))));
	mlx_destroy_image(cub()->mlx, img->img);
	free(img);
	return (aux);
}

void	draw(int x)
{
	int	y;
	int	color;

	cub()->imgx = (int)(cub()->wallx * IMG_W);
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
			printf("drawing");
			color = ft_get_pickle(cub()->imgx, cub()->imgy);
			my_mlx_pixel_put(x, y, color);
		}
		y++;
	}
}
