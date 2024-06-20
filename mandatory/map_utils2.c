/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:20:43 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/19 18:20:43 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	floor_text(char *temp)
{
	if (cub()->flo)
	{
		free(temp);
		return (file_err_msg('c', cub()->fd));
	}
	cub()->flo = get_value(temp);
	if (!cub()->flo)
	{
		free(temp);
		return (file_err_msg('c', cub()->fd));
	}
	return (0);
}

int	ceiling_text(char *temp)
{
	if (cub()->cei)
	{
		free(temp);
		return (file_err_msg('c', cub()->fd));
	}
	cub()->cei = get_value(temp);
	if (!cub()->cei)
	{
		free(temp);
		return (file_err_msg('c', cub()->fd));
	}
	return (0);
}

int	walls_verif(int y)
{
	while (cub()->mp_dp[y])
	{
		if (cub()->mp_dp[y][0])
		{
			if (cub()->mp_dp[y][0] == '1' || cub()->mp_dp[y][0] == ' ')
				y++;
			else
				return (-1);
		}
	}
	return (0);
}

void	plr_pos_verif2(int x, int y)
{
	if (cub()->mp_dp[y][x] == 'E')
	{
		cub()->posi = 'E';
		cub()->plx = x + 0.5;
		cub()->ply = y + 0.5;
		cub()->plr_cnt++;
	}
	if (cub()->mp_dp[y][x] == 'W')
	{
		cub()->posi = 'W';
		cub()->plx = x + 0.5;
		cub()->ply = y + 0.5;
		cub()->plr_cnt++;
	}
}
