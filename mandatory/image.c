/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:46:09 by bbento-e          #+#    #+#             */
/*   Updated: 2024/06/19 16:08:01 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	text_size(int width, int height)
{
	if (width != 128 && height != 128)
		return (-1);
	return (0);
}

int	get_address2(void)
{
	(cub()->ws->addr) = mlx_get_data_addr(cub()->ws->img, &cub()->ws->bpp,
			&cub()->ws->llen, &cub()->ws->endian);
	if (text_size(cub()->ws->width, cub()->ws->height) == -1)
	{
		printf("Error\nImages are not 128x128\n");
		return (-1);
	}
	(cub()->bg->addr) = mlx_get_data_addr(cub()->bg->img, &cub()->bg->bpp,
			&cub()->bg->llen, &cub()->bg->endian);
	if (text_size(cub()->bg->width, cub()->bg->height) == -1)
	{
		printf("Error\nImages are not 128x128\n");
		return (-1);
	}
	return (0);
}

int	get_address(void)
{
	(cub()->no->addr) = mlx_get_data_addr(cub()->no->img, &cub()->no->bpp,
			&cub()->no->llen, &cub()->no->endian);
	if (text_size(cub()->no->width, cub()->no->height) == -1)
	{
		printf("Error\nImages are not 128x128\n");
		return (-1);
	}
	(cub()->so->addr) = mlx_get_data_addr(cub()->so->img, &cub()->so->bpp,
			&cub()->so->llen, &cub()->so->endian);
	if (text_size(cub()->so->width, cub()->so->height) == -1)
	{
		printf("Error\nImages are not 128x128\n");
		return (-1);
	}
	(cub()->ea->addr) = mlx_get_data_addr(cub()->ea->img, &cub()->ea->bpp,
			&cub()->ea->llen, &cub()->ea->endian);
	if (text_size(cub()->ea->width, cub()->ea->height) == -1)
	{
		printf("Error\nImages are not 128x128\n");
		return (-1);
	}
	if (get_address2() == -1)
		return (-1);
	return (0);
}

int	draw_textures(void)
{
	(cub()->bg->img) = mlx_new_image(cub()->mlx, WIDTH, HEIGHT);
	(cub()->no->img) = mlx_xpm_file_to_image(cub()->mlx,
			cub()->north, &cub()->no->width, &cub()->no->height);
	(cub()->so->img) = mlx_xpm_file_to_image(cub()->mlx,
			cub()->south, &cub()->so->width, &cub()->so->height);
	(cub()->ea->img) = mlx_xpm_file_to_image(cub()->mlx,
			cub()->east, &cub()->ea->width, &cub()->ea->height);
	(cub()->ws->img) = mlx_xpm_file_to_image(cub()->mlx,
			cub()->west, &cub()->ws->width, &cub()->ws->height);
	if (cub()->no->img == NULL || cub()->so->img == NULL
		|| cub()->ea->img == NULL || cub()->ws->img == NULL)
		return (file_err_msg('T', 0));
	if (get_address() == -1)
		return (-1);
	return (0);
}
