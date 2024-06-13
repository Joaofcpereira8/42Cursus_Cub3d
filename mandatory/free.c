/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:41:55 by bbento-e          #+#    #+#             */
/*   Updated: 2024/05/29 15:53:12 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_arr(char **arr)
{
	int i;

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
	if (cub()->map_dup)
		free_arr(cub()->map_dup);
	exit(0);
}