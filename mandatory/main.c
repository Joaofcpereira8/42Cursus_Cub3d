/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:31:13 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/19 17:33:42 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(void)
{
	draw_bkgnd(create_trgb(cub()->cei, 255), create_trgb(cub()->flo, 255));
	cub()->wcnt = 0;
	while (cub()->wcnt < WIDTH)
	{
		ray();
		ray_dir();
		hit_reg();
		ray_calc();
		asgn_txtr();
		wall_e();
		draw(cub()->wcnt);
		cub()->wcnt++;
	}
	mlx_put_image_to_window(cub()->mlx, cub()->win, cub()->bg->img, 0, 0);
}

int	cub_loop(void)
{
	if (!plr_movement())
		return (0);
	mlx_destroy_image(cub()->mlx, cub()->bg->img);
	(cub()->bg->img) = mlx_new_image(cub()->mlx, WIDTH, HEIGHT);
	dda();
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (file_verif(argv[1]) == -1)
			return (-1);
		if (map_par(argv[1]) == -1)
		{
			free_struct();
			return (-1);
		}
		cub_init();
		cub()->mlx = mlx_init();
		cub()->win = mlx_new_window(cub()->mlx, WIDTH, HEIGHT, "cub3d");
		if (draw_textures() == -1)
		{
			free_mlx();
			free_struct();
		}
		plyr_dir();
		dda();
		mlx_hook(cub()->win, KeyPress, KeyPressMask, key_hook, (cub()));
		mlx_hook(cub()->win, KeyRelease, KeyReleaseMask, key_dehook, (cub()));
		mlx_hook(cub()->win, DestroyNotify, ButtonPressMask, press_x, (cub()));
		mlx_loop_hook(cub()->mlx, cub_loop, (cub()));
		mlx_loop(cub()->mlx);
	}
	else
		args_error(-1);
	return (0);
}
