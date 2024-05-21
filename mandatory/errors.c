/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:13:46 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/21 14:13:46 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_msg(char c)
{
	if (c == 'a')
		ft_putstr_fd("Error\nMap format is wrong. Use [executable] maps/[map_name].cub!\n", 2);
	return (-1);
}