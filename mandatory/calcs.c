/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:50:54 by bbento-e          #+#    #+#             */
/*   Updated: 2024/06/13 18:49:54 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray()
{
	cub()->camx = 2 * cub()->wcnt / WIDTH - 1;
	cub()->rayx = cub()->dirx + cub()->plx * cub()->camx;
	cub()->rayy = cub()->diry + cub()->ply * cub()->camx;
	cub()->mapx = cub()->plx;
	cub()->mapy = cub()->ply;
	if (cub()->rayx == 0)
		cub()->delta_x = 1e30;
	else
		cub()->delta_x = fabs(1 / cub()->rayy);
	if (cub()->rayy == 0)
		cub()->delta_y = 1e30;
	else
		cub()->delta_y = fabs(1 / cub()->rayy);
	cub()->wallflag = 0;
}

void	ray_dir()
{
	// Determine the step direction and initial side distance for the x-axis
	if (cub()->rayx < 0)
	{
		cub()->rright = -1; // The ray is moving left
		cub()->dist_right = (cub()->plx - cub()->mapx) * cub()->dist_right;
	}
	else
	{
		cub()->rright = 1; // The ray is moving right
		cub()->dist_right = (cub()->mapx + 1.0 - cub()->plx) * cub()->dist_right;
	}

	// Determine the step direction and initial side distance for the y-axis
	if (cub()->rayy < 0)
	{
		cub()->rleft = -1; // The ray is moving up
		cub()->dist_left = (cub()->ply - cub()->mapy) * cub()->dist_left;
	}
	else
	{
		cub()->rleft = 1; // The ray is moving down
		cub()->dist_left = (cub()->mapy + 1.0 - cub()->ply) * cub()->dist_left;
	}
}

void	ray_calc()
{
	if (cub()->ori == 'V')
		cub()->perpend_wl = cub()->dist_right - cub()->delta_x;
	else
		cub()->perpend_wl = cub()->dist_left - cub()->delta_y;
	if (cub()->perpend_wl)
		cub()->line_h = (int)(HEIGHT / cub()->perpend_wl);
	else
		cub()->line_h = HEIGHT;
	cub()->begn_draw = -cub()->line_h / 2 + HEIGHT / 2;
	if (cub()->begn_draw < 0)
		cub()->begn_draw = 0;
	cub()->end_draw = cub()->line_h / 2 + HEIGHT / 2;
	if (cub()->end_draw >= HEIGHT)
		cub()->end_draw = HEIGHT - 1;
}

void	hit_reg()
{
	while (!cub()->hit)
	{
		// Compare side distances to determine which side the ray hits first
		if (cub()->dist_right < cub()->dist_left)
		{
			// The ray hits a vertical grid line first
			cub()->dist_right += cub()->dist_right;
			cub()->mapx += cub()->rright;
			cub()->ori = 'V'; // Vertical hit
		}
		else
		{
			// The ray hits a horizontal grid line first
			cub()->dist_right += cub()->dist_right;
			cub()->mapy += cub()->rleft;
			cub()->ori = 'H'; // Horizontal hit
		}
		// Check if the current grid cell is a wall
		if (cub()->map_dup[cub()->mapx][cub()->mapy] == '1')
			cub()->hit = 1;
	}
}

t_img *img_picker(char type)
{
	static char img;

	if (type == 'N' || type == 'S' || type == 'E' || type == 'W')
	{
		img = type;
		if (type == 'N')
			return (cub()->no);
		else if (type == 'S')
			return (cub()->so);
		else if (type == 'E')
			return (cub()->ea);
		else
			return (cub()->ws);
	}
	return (img_picker(img));
}

void	asgn_txtr()
{
	if (cub()->ori == 'H')
	{
		if (cub()->rayy >= 0)
			img_picker('N');
		else
			img_picker('S');
	}
	else
	{
		if (cub()->rayx < 0)
			img_picker('E');
		else
			img_picker('W');
	}
}
