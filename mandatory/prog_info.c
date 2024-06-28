/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:20:09 by bbento-e          #+#    #+#             */
/*   Updated: 2024/06/28 16:15:55 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_attr(char c)
{
	if (c == 'T' && (!cub()->north || !cub()->south || !cub()->east
			|| !cub()->west))
		return (false);
	else if (c == 'C' && (!cub()->flo || !cub()->cei))
		return (false);
	else if (c == 'A' && (!cub()->north || !cub()->south || !cub()->east
			|| !cub()->west || !cub()->flo || !cub()->cei))
		return (false);
	return (true);
}

bool	is_map(char *str)
{
	int			i;
	static bool	var;

	i = 0;
	if (!var && str)
	{
		ign_spaces(str, i);
		if (str[i] == '1' || str[i] == '0')
			var = true;
	}
	return (var);
}

void	flag_change(void)
{
	cub()->flagfill = -1;
}

void	set_coords(double dx, double dy, double cx, double cy)
{
	cub()->dirx = dx;
	cub()->diry = dy;
	cub()->pln_x = cx;
	cub()->pln_y = cy;
}

void	plyr_dir(void)
{
	if (cub()->posi == 'N')
	{
		set_coords(0, -1, FOV, 0);
		return ;
	}
	else if (cub()->posi == 'S')
	{
		set_coords(0, 1, -FOV, 0);
		return ;
	}
	else if (cub()->posi == 'E')
	{
		set_coords(1, 0, 0, FOV);
		return ;
	}
	else if (cub()->posi == 'W')
	{
		set_coords(-1, 0, 0, -FOV);
		return ;
	}
}
