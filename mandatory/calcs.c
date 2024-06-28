/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:50:54 by bbento-e          #+#    #+#             */
/*   Updated: 2024/06/19 15:33:34 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray(void)
{
	cub()->camx = 2 * cub()->wcnt / (double)WIDTH - 1;
	cub()->rayx = cub()->dirx + cub()->pln_x * cub()->camx;
	cub()->rayy = cub()->diry + cub()->pln_y * cub()->camx;
	cub()->mapx = (int)cub()->plx;
	cub()->mapy = (int)cub()->ply;
	if (cub()->rayx == 0)
		cub()->delta_x = 1e30;
	else
		cub()->delta_x = fabs(1 / cub()->rayx);
	if (cub()->rayy == 0)
		cub()->delta_y = 1e30;
	else
		cub()->delta_y = fabs(1 / cub()->rayy);
	cub()->hit = 0;
}

void	ray_dir(void)
{
	if (cub()->rayx < 0)
	{
		cub()->rright = -1;
		cub()->dst_rght = (cub()->plx - cub()->mapx) * cub()->delta_x;
	}
	else
	{
		cub()->rright = 1;
		cub()->dst_rght = (cub()->mapx + 1.0 - cub()->plx) * cub()->delta_x;
	}
	if (cub()->rayy < 0)
	{
		cub()->rleft = -1;
		cub()->dst_left = (cub()->ply - cub()->mapy) * cub()->delta_y;
	}
	else
	{
		cub()->rleft = 1;
		cub()->dst_left = (cub()->mapy + 1.0 - cub()->ply) * cub()->delta_y;
	}
}

void	ray_calc(void)
{
	if (cub()->ori == 'V')
		cub()->perpend_wl = cub()->dst_rght - cub()->delta_x;
	else
		cub()->perpend_wl = cub()->dst_left - cub()->delta_y;
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

void	hit_reg(void)
{
	while (cub()->hit == 0)
	{
		if (cub()->dst_rght < cub()->dst_left)
		{
			cub()->dst_rght += cub()->delta_x;
			cub()->mapx += cub()->rright;
			cub()->ori = 'V';
		}
		else
		{
			cub()->dst_left += cub()->delta_y;
			cub()->mapy += cub()->rleft;
			cub()->ori = 'H';
		}
		if ((cub()->mp_dp[(cub()->mapy)][(cub()->mapx)]) == '1')
			cub()->hit = 1;
	}
}
