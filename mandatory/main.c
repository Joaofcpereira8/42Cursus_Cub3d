/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:31:13 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/05 18:15:58 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		cub()->mlx_ptr = mlx_init();
		cub()->win_ptr = mlx_new_window(cub()->mlx_ptr, 1920, 1080, "cub3d");
		mlx_loop(cub()->mlx_ptr);
		if (start() == -1)
			return (-1);
		free_struct();
	}
	else
		args_error(-1);
	return (0);
}
