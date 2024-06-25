/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:33:43 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/18 19:03:37 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	verifs(void)
{
	int	x;
	int	y;
	int	z;

	y = 0;
	x = 0;
	cub()->plr_cnt = 0;
	if (check_frst_wall(x) == -1)
		return (-1);
	while (y < cub()->y)
	{
		if (jmp_and_verif(y, x) == -1)
			return (-1);
		z = x;
		if (cub()->mp_dp[y][z])
		{
			if (verif_inside_map(y, z) == -1)
				return (-1);
		}
		y++;
	}
	if (cub()->plr_cnt < 1)
		return (file_err_msg('p', 0));
	return (0);
}

int	map_verif(void)
{
	if (height_y() == -1)
		return (file_err_msg('y', 0));
	if (width_x() == -1)
		return (file_err_msg('x', 0));
	if (verifs() == -1)
		return (-1);
	if (wall_check() == -1)
		return (file_err_msg('d', 0));
	free_arr(cub()->mp_dp);
	if (height_y() == -1)
		return (file_err_msg('y', 0));
	if (width_x() == -1)
		return (file_err_msg('x', 0));
	return (0);
}
