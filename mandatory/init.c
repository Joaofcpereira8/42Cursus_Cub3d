/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:02:03 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/19 16:43:36 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_init(void)
{
	cub()->mlx = 0;
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
	cub()->bg->width = IMG_W;
	cub()->bg->width = IMG_H;
	cub()->no->addr = NULL;
	cub()->no->img = NULL;
	cub()->no->bpp = 0;
	cub()->no->llen = 0;
	cub()->no->endian = 0;
	cub()->no->width = IMG_W;
	cub_init2();
	cub_init3();
}

void	cub_init2(void)
{
	cub()->rleft = 0;
	cub()->imgx = 0;
	cub()->imgy = 0;
	cub()->imgstp = 0;
	cub()->imgpos = 0;
	cub()->ori = 'V';
	cub()->mapx = 0;
	cub()->mapy = 0;
	cub()->line_h = 0;
	cub()->wallx = 0;
	cub()->dirx = 0;
	cub()->diry = 0;
	cub()->begn_draw = 0;
	cub()->end_draw = 0;
	cub()->wcnt = 0;
	cub()->pln_x = 0;
	cub()->pln_y = 0;
	cub()->camx = 0;
	cub()->rayx = 0;
	cub()->rayy = 0;
	cub()->dst_rght = 0;
	cub()->dst_left = 0;
	cub()->delta_x = 0;
	cub()->delta_y = 0;
	cub()->perpend_wl = 0;
}

void	cub_init3(void)
{
	cub()->no->width = IMG_H;
	cub()->so->addr = NULL;
	cub()->so->img = NULL;
	cub()->so->bpp = 0;
	cub()->so->llen = 0;
	cub()->so->endian = 0;
	cub()->so->width = IMG_W;
	cub()->so->width = IMG_H;
	cub()->ea->addr = NULL;
	cub()->ea->img = NULL;
	cub()->ea->bpp = 0;
	cub()->ea->llen = 0;
	cub()->ea->endian = 0;
	cub()->ea->width = IMG_W;
	cub()->ea->width = IMG_H;
	cub()->ws->addr = NULL;
	cub()->ws->img = NULL;
	cub()->ws->bpp = 0;
	cub()->ws->llen = 0;
	cub()->ws->endian = 0;
	cub()->ws->width = IMG_W;
	cub()->ws->height = IMG_H;
	cub()->hit = 0;
	cub()->rright = 0;
}
