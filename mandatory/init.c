/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:02:03 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/18 18:33:34 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_init(void)
{
	cub()->win = 0;
	cub()->bg = malloc(sizeof(t_img));
	cub()->no = malloc(sizeof(t_img));
	cub()->so = malloc(sizeof(t_img));
	cub()->ea = malloc(sizeof(t_img));
	cub()->ws = malloc(sizeof(t_img));
	cub()->bg->addr = NULL;
	cub()->bg->img = NULL;
	cub()->bg->bpp = 0;
	cub()->bg->llen = 0;
	cub()->bg->endian = 0;
	cub()->bg->width = 0;
	cub()->bg->height = 0;
	cub()->hit = 0;
	cub()->rright = 0;
	cub()->rleft = 0;
	cub()->imgx = 0;
	cub()->imgy = 0;
	cub()->imgstp = 0;
	cub()->imgpos = 0;
/*	cub()->mapx = 0;
	cub()->mapy = 0;
	cub()->line_h = 0;
	cub()->wallx = 0;
	cub()->dirx = 0;
	cub()->diry = 0;
	cub()->begn_draw = 0;
	cub()->end_draw = 0;
	cub()->fd = 0;
	cub()->wcnt = 0;
	cub()->lin_cnt = 0;
	cub()->plr_cnt = 0;
	cub()->flagfill = 0;
	cub()->line_no = 0;
	cub()->plx = 0;
	cub(	)->ply = 0;
 */
}
