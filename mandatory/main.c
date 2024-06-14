/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:31:13 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/14 15:16:06 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda()
{
	cub()->wcnt = 0;
	while (cub()->wcnt < WIDTH)
	{
		ray();
		ray_calc();
		ray_dir();
		hit_reg();
		ray_calc();
		asgn_txtr();
		cub()->wcnt++;
	}
}

int	cub_loop()
{
	mlx_destroy_image(cub()->mlx, cub()->bg->img);
	cub()->bg->img = mlx_new_image(cub()->mlx, WIDTH, HEIGHT);
	draw_bkgnd(create_trgb(cub()->cei, 255), create_trgb(cub()->flo, 255));
	//dda();
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
		if (draw_textures() == -1)
			return (-1);
		cub()->win = mlx_new_window(cub()->mlx, WIDTH, HEIGHT, "cub3d");
		draw_bkgnd(create_trgb(cub()->cei, 255), create_trgb(cub()->flo, 255));
		plyr_dir();
		mlx_key_hook(cub()->win, key_hook, &cub);
		mlx_loop_hook(cub()->mlx, cub_loop, NULL);
		mlx_loop(cub()->mlx);
		free_mlx();
		free_struct();
	}
	else
		args_error(-1);
	return (0);
}
