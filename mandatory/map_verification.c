/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:15:54 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/31 14:26:52 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	floodfill(int x, int y)
{
	if (cubed()->map_dup[y][x] == '1' || cubed()->map_dup[y][x] == 'X'
		|| !cubed()->map_dup[y][x])
		return ;
	else if (cubed()->map_dup[y][x] == ' ')
		file_err_msg('d', 0);
	else
	{
		cubed()->map_dup[y][x] = 'X';
		floodfill((x + 1), y);
		floodfill((x - 1), y);
		floodfill(x, (y + 1));
		floodfill(x, (y - 1));
	}
}

void	wall_check()
{
	int	y;
	int	x;

	y = 0;
	while (cubed()->map_dup[y])
	{
		x = 0;
		while (cubed()->map_dup[y][x])
		{
			if (cubed()->map_dup[y][x] == '0' || cubed()->map_dup[y][x] == 'N' || cubed()->map_dup[y][x] == 'S'
				 || cubed()->map_dup[y][x] == 'E'|| cubed()->map_dup[y][x] == 'W')
				floodfill(x, y);
			x++;
		}
		y++;
	}
}

int	map_verif(void)
{
	if (height_y() == -1)
		return (args_error('y'));
	if (width_x() == -1)
		return (args_error('x'));
	wall_check();

	printf("\n"); // DEBUG
	int i = -1; // DEBUG
	while (++i < cubed()->line_no) // DEBUG
		printf("%s\n", cubed()->map_dup[i]); // DEBUG
	return (0);
}
