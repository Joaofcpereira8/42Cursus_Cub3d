/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:15:54 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/24 15:15:54 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//void	floodfill(void)
//{
//	if (map_dup[y][x] == '1' || map_dup[y][x] == 'X'
//		|| !map_dup[y][x])
//		return ;
//	else
//	{
//		if (map_dup[y][x] == 'E' && info->cltb_ch == info->cltb_av)
//			exit_checker(info, x, y);
//		map_dup[y][x] = 'X';
//		floodfill(map_dup, info, (x + 1), y);
//		floodfill(map_dup, info, (x - 1), y);
//		floodfill(map_dup, info, x, (y + 1));
//		floodfill(map_dup, info, x, (y - 1));
//	}
//}
//
//int	checker(void)
//{
//	int	x;
//	int	y;
//
//	y = 0;
//	while (y <= data->y)
//	{
//		x = 0;
//		while (x < data->x)
//		{
//			if ((y == 0 || y == data->y) || (x == 0 || x == data->x - 1))
//				wall_checker(info, data, x, y);
//			else if (data->map_dup[y][x] == 'C')
//				info->cltb_av++;
//			else if (data->map_dup[y][x] == 'E')
//				info->ext_av++;
//			else if (data->map_dup[y][x] == 'P')
//				player_checker(info, data, x, y);
//			else
//				char_checker(info, data->map_dup[y][x]);
//			x++;
//		}
//		y++;
//	}
//	data->to_collect = info->cltb_av;
//	return (error_print(info, data));
//}

int	width_x(void)
{
	char	*temp;
	int		y;
	int		i;

	i = 0;
	y = 0;
	cubed()->map_dup = ft_calloc(cubed()->y + 1, sizeof(char *));
	while (y <= cubed()->y)
	{
		temp = cubed()->map[i];
		cubed()->map_dup[y] = ft_strtrim(temp, "\n");
		if (!cubed()->map_dup[y])
			break ;
		if (cubed()->x <= 0)
		{
			free_arr(cubed()->map_dup);
			ft_putstr_fd("EEERRRRRRROU O X", 2);
			return (-1);
		}
		y++;
		i++;
	}
	return (0);
}

void	height_y(void)
{
	char	*line;
	int		i;
	int		comp;

	i = 0;
	cubed()->x = (int)ft_strlen(cubed()->map[i]);
	if (cubed()->x == 0)
	{
		ft_putstr_fd("errrrrrrou", 2);
		return ;
	}
	while (1)
	{
		line = cubed()->map[i];
		if (!line)
			break ;
		comp = ft_strlen(line);
		if (comp > cubed()->x)
			cubed()->x = comp;
		cubed()->y++;
		i++;
	}
}

void	map_verif(void)
{
	height_y();
	width_x();
}