/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plr_mov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:52:27 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/13 18:56:50 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int key)
{
	if (key == XK_Escape)
		free_struct();
	else if (key == XK_w || key == XK_a || key == XK_s || key == XK_d)
	{
		//moves_plr(key);
	}
	else
		return (-1);
	printf("ITS WORKING!!!!!\n");
	return (0);
}