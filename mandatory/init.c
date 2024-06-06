/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:02:03 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/06 19:09:51 by bbento-e         ###   ########.fr       */
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
}
