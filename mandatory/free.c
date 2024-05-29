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
	if (cubed()->north)
		free(cubed()->north);
	if (cubed()->south)
		free(cubed()->south);
	if (cubed()->east)
		free(cubed()->east);
	if (cubed()->west)
		free(cubed()->west);
	if (cubed()->cei)
		free(cubed()->cei);
	if (cubed()->flo)
		free(cubed()->flo);
	free_arr(cubed()->map);
	free_arr(cubed()->map_dup);
}