/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:15:54 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/12 15:45:04 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	width_x(void)
{
	char	*temp;
	char	*mem_temp;
	int		y;
	int		i;

	y = cub()->lin_cnt - 1;
	i = cub()->lin_cnt + 5;
	cub()->mp_dp = ft_calloc(cub()->lin_cnt + 1, sizeof(char *));
	while (y >= 0)
	{
		temp = cub()->map[i];
		mem_temp = ft_strtrim(temp, "\n");
		cub()->mp_dp[y] = ft_strdup(mem_temp);
		if (!cub()->mp_dp[y])
			return (-1);
		free(mem_temp);
		y--;
		i--;
	}
	return (0);
}

int	height_y(void)
{
	char	*line;
	int		i;
	int		comp;

	i = 6;
	cub()->y = 0;
	cub()->x = (int)ft_strlen(cub()->map[i]);
	if (cub()->x == 0)
		return (-1);
	while (cub()->map[i])
	{
		line = cub()->map[i];
		comp = ft_strlen(line);
		if (comp > cub()->x)
			cub()->x = comp;
		cub()->y++;
		i++;
	}
	if (cub()->y != cub()->lin_cnt)
	{
		printf("Error\nLines do not match\n");
		return (-1);
	}
	return (0);
}

void	floodfill(int x, int y)
{
	if (x < 0 || x >= cub()->x || y < 0 || y >= cub()->y)
		return ;
	if (!cub()->mp_dp[y][x])
		return ;
	if (cub()->mp_dp[y][x] == '1' || cub()->mp_dp[y][x] == 'X')
		return ;
	if (cub()->mp_dp[y][x] == ' ')
		return (flag_change());
	else
	{
		cub()->mp_dp[y][x] = 'X';
		floodfill((x + 1), y);
		floodfill((x - 1), y);
		floodfill(x, (y + 1));
		floodfill(x, (y - 1));
	}
}

int	wall_check(void)
{
	int	y;
	int	x;

	y = 0;
	while (cub()->mp_dp[y])
	{
		x = 0;
		if (y == 0)
		{
			if (walls_verif(x) == -1)
				return (-1);
		}
		x = 0;
		while (cub()->mp_dp[y][x])
		{
			if (cub()->mp_dp[y][x] == '0' || cub()->mp_dp[y][x] == 'N'
				|| cub()->mp_dp[y][x] == 'S' || cub()->mp_dp[y][x] == 'E'
				|| cub()->mp_dp[y][x] == 'W')
				floodfill(x, y);
			x++;
		}
		y++;
	}
	return (cub()->flagfill);
}

int	plr_pos_verif(int x, int y)
{
	if (cub()->mp_dp[y][x] == 'N')
	{
		cub()->posi = 'N';
		cub()->plx = x + 0.5;
		cub()->ply = y + 0.5;
		cub()->plr_cnt++;
	}
	if (cub()->mp_dp[y][x] == 'S')
	{
		cub()->posi = 'S';
		cub()->plx = x + 0.5;
		cub()->ply = y + 0.5;
		cub()->plr_cnt++;
	}
	plr_pos_verif2(x, y);
	if (cub()->plr_cnt > 1)
	{
		printf("Error\nMore than one player in map\n");
		return (-1);
	}
	return (0);
}
