/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plr_mov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:52:27 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/18 12:07:01 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	moves_plr_flag(int key)
{
	if (key == XK_w)
		cub()->plr_up = 1;
	if (key == XK_s)
		cub()->plr_dn = 1;
	if (key == XK_a)
		cub()->plr_lf = 1;
	if (key == XK_d)
		cub()->plr_rg = 1;
	if (key == XK_Right)
		cub()->plr_lk_r = 1;
	if (key == XK_Left)
		cub()->plr_lk_l = 1;
}

int	key_dehook(int key)
{
	if (key == XK_w)
		cub()->plr_up = 0;
	if (key == XK_s)
		cub()->plr_dn = 0;
	if (key == XK_a)
		cub()->plr_lf = 0;
	if (key == XK_d)
		cub()->plr_rg = 0;
	if (key == XK_Right)
		cub()->plr_lk_r = 0;
	if (key == XK_Left)
		cub()->plr_lk_l = 0;
	return (0);
}

int	key_hook(int key)
{
	if (key == XK_Escape)
	{
		free_mlx();
		free_struct();
	}
	else if (key == XK_w || key == XK_a || key == XK_s
		|| key == XK_d || key == XK_Left || key == XK_Right)
		moves_plr_flag(key);
	else
		return (-1);
	return (0);
}

int	plr_movement(void)
{
	if (cub()->plr_up == 1)
		ver_movi(1);
	if (cub()->plr_dn == 1)
		ver_movi(0);
	if (cub()->plr_lf == 1)
		hor_movi(0);
	if (cub()->plr_rg == 1)
		hor_movi(1);
	if (cub()->plr_lk_l == 1)
		plr_rotate(-1);
	if (cub()->plr_lk_r == 1)
		plr_rotate(1);
	if (cub()->plr_up || cub()->plr_dn || cub()->plr_lf || cub()->plr_rg
		|| cub()->plr_lk_l || cub()->plr_lk_r)
		return (-1);
	return (0);
}

void	ver_movi(int flag)
{
	if (flag)
	{
		if (cub()->mp_dp[(int)(cub()->ply + cub()->diry * 0.2)]
			[(int) cub()->plx] != '1')
			cub()->ply += cub()->diry * 0.2;
		if (cub()->mp_dp[(int)cub()->ply]
			[(int)(cub()->plx + cub()->dirx * 0.2)] != '1')
			cub()->plx += cub()->dirx * 0.2;
	}
	else
	{
		if (cub()->mp_dp[(int)(cub()->ply - cub()->diry * 0.2)]
			[(int) cub()->plx] != '1')
			cub()->ply -= cub()->diry * 0.2;
		if (cub()->mp_dp[(int)cub()->ply]
			[(int)(cub()->plx - cub()->dirx * 0.2)] != '1')
			cub()->plx -= cub()->dirx * 0.2;
	}
}
