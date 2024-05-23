/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:59:12 by bbento-e          #+#    #+#             */
/*   Updated: 2024/05/22 19:09:36 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start()
{
	return (draw_textures());
}

int	draw_textures()
{
	cubed()->fd = open(cubed()->north, O_RDONLY);
	if (cubed()->fd < 0)
		return (file_err_msg('T', 0));
	else
		close(cubed()->fd);
	cubed()->fd = open(cubed()->south, O_RDONLY);
	if (cubed()->fd < 0)
		return (file_err_msg('T', 0));
	else
		close(cubed()->fd);
	cubed()->fd = open(cubed()->east, O_RDONLY);
	if (cubed()->fd < 0)
		return (file_err_msg('T', 0));
	else
		close(cubed()->fd);
	cubed()->fd = open(cubed()->west, O_RDONLY);
	if (cubed()->fd < 0)
		return (file_err_msg('T', 0));
	else
		close(cubed()->fd);
	return (1);
}