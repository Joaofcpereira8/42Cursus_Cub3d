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
	cub()->map_dup = ft_calloc(cub()->lin_cnt + 1, sizeof(char *));
	while (y >= 0)
	{
		temp = cub()->map[i];
		mem_temp = ft_strtrim(temp, "\n");
		cub()->map_dup[y] = ft_strdup(mem_temp);
		if (!cub()->map_dup[y])
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

int	plr_pos_verif(int x, int y)
{
	if (cub()->map_dup[y][x] == 'N')
	{
		cub()->posi = 'N';
		cub()->plx = x;
		cub()->ply = y;
		cub()->plr_cnt++;
	}
	if (cub()->map_dup[y][x] == 'S')
	{
		cub()->posi = 'S';
		cub()->plx = x;
		cub()->ply = y;
		cub()->plr_cnt++;
	}
	if (cub()->map_dup[y][x] == 'E')
	{
		cub()->posi = 'E';
		cub()->plx = x;
		cub()->ply = y;
		cub()->plr_cnt++;
	}
	if (cub()->map_dup[y][x] == 'W')
	{
		cub()->posi = 'W';
		cub()->plx = x;
		cub()->ply = y;
		cub()->plr_cnt++;
	}
	if (cub()->plr_cnt > 1)
	{
		printf("Error\nMore than one player in map\n");
		return (-1);
	}
	return (0);
}

int	verifs(void)
{
	int	temp;
	int	x;
	int	y;
	int	z;

	y = 0;
	cub()->plr_cnt = 0;
	while (y < cub()->y)
	{
		x = 0;
		if (cub()->map_dup[y][x] == ' ')
		{
			while (cub()->map_dup[y][x] == ' ')
				x++;
		}
		temp = ft_strlen(cub()->map_dup[y]) - 1;
		if ((cub()->map_dup[y][x] != '1' && cub()->map_dup[y][x] != ' ')
			&& (cub()->map_dup[y][temp] != ' ' && cub()->map_dup[y][temp] != '1'))
		{
			printf("ERRRRROOOOO\n");
			return -1;
		}
		z = x;
		while (cub()->map_dup[y][z])
		{
			while (cub()->map_dup[y][z] != '\0')
			{
				if (plr_pos_verif(z, y) == -1)
					return (-1);
				if ((cub()->map_dup[y][z] == '0' && !cub()->map_dup[y + 1]) || (cub()->map_dup[y][z] == '0' && cub()->map_dup[y + 1][z] == ' '))
				{
					printf("Error\nMap is not valid\n");
					return (-1);
				}
				while (cub()->map_dup[y][z] == ' ')
					z++;
				if (cub()->map_dup[y][z] == '0' || cub()->map_dup[y][z] == '1' || cub()->map_dup[y][z] == 'N'
					|| cub()->map_dup[y][z] == 'E' || cub()->map_dup[y][z] == 'S' || cub()->map_dup[y][z] == 'W')
					z++;
				else
				{
					printf("Error\nMap is not valid\n");
					return (-1);
				}
			}
			if (cub()->map_dup[y][z - 1] == '0' && cub()->map_dup[y][z] == '\0')
			{
				printf("Error\nMap is not valid\n");
				return (-1);
			}
		}
		y++;
	}
	if (cub()->plr_cnt < 1)
	{
		printf("Error\nPlayer does not exist in map\n");
		return (-1);
	}
	return (0);
}

int	map_verif(void)
{
	if (height_y() == -1)
		return (file_err_msg('y', 0));
	if (width_x() == -1)
		return (file_err_msg('x', 0));
	int j = -1;
	if (!cub()->map_dup)
		return -1;
	else
	{
		while (cub()->map_dup[++j])
			printf("%s\n", cub()->map_dup[j]);
	}
	if (verifs() == -1)
		return (-1);
	printf("%c\n", cub()->posi);
	if (wall_check() == -1)
		return (file_err_msg('d', 0));
	j = -1;
	if (!cub()->map_dup)
		return -1;
	else
	{
		while (cub()->map_dup[++j])
			printf("%s\n", cub()->map_dup[j]);
	}
	return (0);
}
