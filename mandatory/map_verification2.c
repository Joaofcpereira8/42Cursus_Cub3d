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
	int	temp;
	int	x;
	int	y;
	int	z;

	y = 0;
	x = 0;
	cub()->plr_cnt = 0;
	while (cub()->mp_dp[0][x])
	{
		if (ft_isalnum(cub()->mp_dp[0][x]) == 1)
		{
			if (cub()->mp_dp[0][x] != '1')
				return (file_err_msg('d', 0));
			else
			{
				x++;
				continue ;
			}
		}
		x++;
	}
	while (y < cub()->y)
	{
		x = 0;
		if (cub()->mp_dp[y][x] == ' ')
		{
			while (cub()->mp_dp[y][x] == ' ')
				x++;
		}
		temp = ft_strlen(cub()->mp_dp[y]) - 1;
		if ((cub()->mp_dp[y][x] != '1' && cub()->mp_dp[y][x] != ' ')
			&& (cub()->mp_dp[y][temp] != ' ' && cub()->mp_dp[y][temp] != '1'))
			return (file_err_msg('w', 0));
		z = x;
		while (cub()->mp_dp[y][z])
		{
			while (cub()->mp_dp[y][z] != '\0')
			{
				if (plr_pos_verif(z, y) == -1)
					return (-1);
				if ((cub()->mp_dp[y][z] == '0' && !cub()->mp_dp[y + 1])
					|| (cub()->mp_dp[y][z] == '0'
					&& (cub()->mp_dp[y + 1][z] == ' '
					|| cub()->mp_dp[y + 1][z] == '\0')))
					return (file_err_msg('d', 0));
				while (cub()->mp_dp[y][z] == ' ')
					z++;
				if (cub()->mp_dp[y][z] == '0' || cub()->mp_dp[y][z] == '1'
					|| cub()->mp_dp[y][z] == 'N' || cub()->mp_dp[y][z] == 'E'
					|| cub()->mp_dp[y][z] == 'S' || cub()->mp_dp[y][z] == 'W')
					z++;
				else
					return (file_err_msg('d', 0));
			}
			if (cub()->mp_dp[y][z - 1] == '0' && cub()->mp_dp[y][z] == '\0')
				return (file_err_msg('d', 0));
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
