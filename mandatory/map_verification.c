/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:15:54 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/06 19:22:39 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	width_x(void)
{
	char	*temp;
	int		y;
	int		i;

	y = cub()->lin_cnt;
	i = cub()->lin_cnt;
	cub()->map_dup = ft_calloc(cub()->y + 1, sizeof(char *));
	while (y > 5)
	{
		temp = cub()->map[i];
		cub()->map_dup[y] = ft_strtrim(temp, "\n");
		if (!cub()->map_dup[y])
			break ;
		if (cub()->x <= 0)
			return (-1);
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
	cub()->x = (int)ft_strlen(cub()->map[i]);
	if (cub()->x == 0)
		return (-1);
	while (i <= cub()->lin_cnt)
	{
		line = cub()->map[i];
		if (!line)
			break ;
		comp = ft_strlen(line);
		if (comp > cub()->x)
			cub()->x = comp;
		cub()->y++;
		i++;
	}
	return (0);
}

void	floodfill(int x, int y)
{
	if (x < 0 || x >= cub()->x || y < 0 || y >= cub()->y)
		return ;
	if (!cub()->map_dup[y][x])
		return ;
	if (cub()->map_dup[y][x] == '1' || cub()->map_dup[y][x] == 'X')
		return ;
	if (cub()->map_dup[y][x] == ' ')
		return flag_change();
	else
	{
		cub()->map_dup[y][x] = 'X';
		floodfill((x + 1), y);
		floodfill((x - 1), y);
		floodfill(x, (y + 1));
		floodfill(x, (y - 1));
	}
}

int	wall_check()
{
	int	y;
	int	x;

	y = 0;
	while (cub()->map_dup[y])
	{
		x = 0;
		while (cub()->map_dup[y][x])
		{
			if (cub()->map_dup[y][x] == '0' || cub()->map_dup[y][x] == 'N' || cub()->map_dup[y][x] == 'S'
				|| cub()->map_dup[y][x] == 'E' || cub()->map_dup[y][x] == 'W')
				floodfill(x, y);
			x++;
		}
		y++;
	}
	return (cub()->flagfill);
}

int	verifs(void)
{
	int	temp;
	int	x;
	int	y;

	y = 0;
	while (y < cub()->y)
	{
		x = 0;
		if (cub()->map_dup[0][0] == ' ')
		{
			while (cub()->map_dup[y][x] == ' ')
				x++;
		}
		temp = ft_strlen(cub()->map_dup[y]) - 1;
		if ((cub()->map_dup[y][x] != '1' || cub()->map_dup[y][x] != ' ')
			&& (cub()->map_dup[y][temp] != '1'|| cub()->map_dup[y][temp] != '1'))
		{
			printf("ERRRRROOOOO\n");
			return -1;
		}
		y++;
	}
	return (0);
}

int	map_verif(void)
{
	if (height_y() == -1)
		return (file_err_msg('y', 0));
	if (width_x() == -1)
		return (file_err_msg('x', 0));
//	if (verifs() == -1)
//		return -1;
//	if (wall_check() == -1)
//		return (file_err_msg('d', 0));

	printf("\n"); // DEBUG
	int i = -1; // DEBUG
	while (++i < cub()->y) // DEBUG
		printf("%s\n", cub()->map_dup[i]); // DEBUG
	return (0);
}
