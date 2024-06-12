/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:46:09 by bbento-e          #+#    #+#             */
/*   Updated: 2024/06/12 15:46:47 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_textures()
{
	cub()->bg->img = mlx_new_image(cub()->mlx, WIDTH, HEIGHT);
	cub()->no->img = mlx_xpm_file_to_image(cub()->mlx,
										   cub()->north, &cub()->no->width, &cub()->no->height);
	cub()->no->addr = mlx_get_data_addr(cub()->no->img, &cub()->no->bpp,
										&cub()->no->llen, &cub()->no->endian);
	cub()->so->img = mlx_xpm_file_to_image(cub()->mlx,
										   cub()->south, &cub()->so->width, &cub()->so->height);
	cub()->so->addr = mlx_get_data_addr(cub()->so->img, &cub()->so->bpp,
										&cub()->so->llen, &cub()->so->endian);
	cub()->ea->img = mlx_xpm_file_to_image(cub()->mlx,
										   cub()->east, &cub()->ea->width, &cub()->ea->height);
	cub()->ea->addr = mlx_get_data_addr(cub()->ea->img, &cub()->ea->bpp,
										&cub()->ea->llen, &cub()->ea->endian);
	cub()->ws->img = mlx_xpm_file_to_image(cub()->mlx,
										   cub()->west, &cub()->ws->width, &cub()->ws->height);
	cub()->ws->addr = mlx_get_data_addr(cub()->ws->img, &cub()->ws->bpp,
										&cub()->ws->llen, &cub()->ws->endian);
	if (!cub()->no->img || !cub()->so->img || !cub()->ea->img || !cub()->ws->img)
		return (file_err_msg('T', 0));
	return (0);
}
