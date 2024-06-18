/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:31:13 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/18 19:50:51 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(void)
{
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
	mlx_put_image_to_window(cub()->mlx, cub()->win, cub()->cr->img, 0, 0);
}

int	cub_loop(void)
{
	// verif n moves ?
	mlx_destroy_image(cub()->mlx, cub()->bg->img);
	(cub()->bg->img) = mlx_new_image(cub()->mlx, WIDTH, HEIGHT);
	//draw_bkgnd(create_trgb(cub()->cei, 255), create_trgb(cub()->flo, 255));

	// drawing current image
/*	mlx_destroy_image(cub()->mlx, cub()->cr->img);
	cub()->cr->img = mlx_new_image(cub()->mlx, WIDTH, HEIGHT);*/

	dda();
	// mlx_put_image_to_window(cub()->mlx, cub()->win, cub()->bg->img, 0, 0);
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
		draw_bkgnd(create_trgb(cub()->cei, 255), create_trgb(cub()->flo, 255));
		plyr_dir();
		/*mlx_hook(cub()->win, DestroyNotify,
		 * StructureNotifyMask, free_mlx, &cub);*/
		mlx_key_hook(cub()->win, key_hook, &cub);
		//mlx_hook(cub()->win, KeyRelease, KeyReleaseMask, key_release, cub);
		mlx_loop_hook(cub()->mlx, cub_loop, NULL);
		mlx_loop(cub()->mlx);
		free_mlx();
		free_struct();
	}
	else
		args_error(-1);
	return (0);
}
