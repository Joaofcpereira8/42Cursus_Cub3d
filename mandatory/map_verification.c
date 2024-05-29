/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:15:54 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/29 17:54:54 by bbento-e         ###   ########.fr       */
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
			return (-1);
		y++;
		i++;
	}
	return (0);
}

int	height_y(void)
{
	char	*line;
	int		i;
	int		comp;

	i = 0;
	cubed()->x = (int)ft_strlen(cubed()->map[i]);
	if (cubed()->x == 0)
		return (-1);
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
	return (0);
}

/*int	check_walls()
{
	int	i;
	int	j;

	i = 0;
	while (i <= cubed()->line_no)
	{
		j = 0;
		if (i == 0 || i == cubed()->line_no)
		{
			j = ign_map_spaces(cubed()->map_dup[i], j);
			while (cubed()->map_dup[i][j])
			{
				if (cubed()->map_dup[i][j] != '1')
				{

				}
			}
		}
		else
		{

		}
		i++;
	}
}
*/

int plyr_check()
{
	return 0;
}

void	floodfill(int x, int y)
{
	if (cubed()->map_dup[y][x] == '1' || cubed()->map_dup[y][x] == 'X'
		|| cubed()->map_dup[y][x] == ' ' || !cubed()->map_dup[y][x])
		return ;
	else
	{
		if (cubed()->map_dup[y][x] == 'N')
			plyr_check();
		cubed()->map_dup[y][x] = 'X';
		floodfill((x + 1), y);
		floodfill((x - 1), y);
		floodfill(x, (y + 1));
		floodfill(x, (y - 1));
	}
}

int	map_verif(void)
{
	if (height_y() == -1)
		return (args_error('y'));
	if (width_x() == -1)
		return (args_error('x'));
/*	if (check_walls() == -1)
		return (args_error('w'));*/
	floodfill(5, 10);

	printf("\n"); // DEBUG
	int i = -1; // DEBUG
	while (++i < cubed()->line_no) // DEBUG
		printf("%s\n", cubed()->map_dup[i]); // DEBUG
	return (0);
}
