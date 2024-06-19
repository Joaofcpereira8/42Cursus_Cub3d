/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:41:55 by bbento-e          #+#    #+#             */
/*   Updated: 2024/06/14 14:49:12 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_struct(void)
{
	if (cub()->north)
		free(cub()->north);
	if (cub()->south)
		free(cub()->south);
	if (cub()->east)
		free(cub()->east);
	if (cub()->west)
		free(cub()->west);
	if (cub()->cei)
		free(cub()->cei);
	if (cub()->flo)
		free(cub()->flo);
	if (cub()->map)
		free_arr(cub()->map);
	if (cub()->mp_dp)
		free_arr(cub()->mp_dp);
	exit(0);
}

void	free_mlx(void)
{
	if (cub()->no->img)
	{
		mlx_destroy_image(cub()->mlx, cub()->no->img);
	}
	free(cub()->no);
	if (cub()->so->img)
	{
		mlx_destroy_image(cub()->mlx, cub()->so->img);
	}
	free(cub()->so);
	if (cub()->ea->img)
	{
		mlx_destroy_image(cub()->mlx, cub()->ea->img);
	}
	free(cub()->ea);
	if (cub()->ws->img)
	{
		mlx_destroy_image(cub()->mlx, cub()->ws->img);
	}
	free(cub()->ws);
	free_mlx2();
}

void	free_mlx2(void)
{
	if (cub()->bg->img)
	{
		mlx_destroy_image(cub()->mlx, cub()->bg->img);
	}
	free(cub()->bg);
	mlx_destroy_window(cub()->mlx, cub()->win);
	mlx_destroy_display(cub()->mlx);
	free(cub()->mlx);
}
