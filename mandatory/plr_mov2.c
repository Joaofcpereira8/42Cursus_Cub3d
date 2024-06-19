/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plr_mov2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:57:52 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/19 16:00:00 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hor_movi(int flag)
{
	if (flag)
	{
		if (cub()->mp_dp[(int)(cub()->ply + cub()->dirx * 0.2)]
			[(int) cub()->plx] != '1')
			cub()->ply += cub()->dirx * 0.2;
		if (cub()->mp_dp[(int)cub()->ply]
			[(int)(cub()->plx - cub()->diry * 0.2)] != '1')
			cub()->plx -= cub()->diry * 0.2;
	}
	else
	{
		if (cub()->mp_dp[(int)(cub()->ply - cub()->dirx * 0.2)]
			[(int) cub()->plx] != '1')
			cub()->ply -= cub()->dirx * 0.2;
		if (cub()->mp_dp[(int)cub()->ply]
			[(int)(cub()->plx + cub()->diry * 0.2)] != '1')
			cub()->plx += cub()->diry * 0.2;
	}
}

void	plr_rotate(int flag)
{
	double	angle;
	double	temp_x;
	double	temp_y;

	angle = 0.10;
	if (flag != 1)
		angle *= -1;
	temp_x = cub()->dirx * cos(angle) - cub()->diry * sin(angle);
	temp_y = cub()->dirx * sin(angle) + cub()->diry * cos(angle);
	cub()->dirx = temp_x;
	cub()->diry = temp_y;
	temp_x = cub()->pln_x * cos(angle) - cub()->pln_y * sin(angle);
	temp_y = cub()->pln_x * sin(angle) + cub()->pln_y * cos(angle);
	cub()->pln_x = temp_x;
	cub()->pln_y = temp_y;
}