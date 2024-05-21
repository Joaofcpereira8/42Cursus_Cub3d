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

int file_err_msg(char c, int fd)
{
	if (c == 'a')
		ft_putstr_fd("Error\nMap format is wrong. Use [executable] maps/[map_name].cub!\n", 2);
	if (c == 'b')
	{
		ft_putstr_fd("Error\nFile not found. Use [path]/[mapname].cub\n", 2);
		close(fd);
	}
	exit(0);
}

int	args_error(int c)
{
	ft_putstr_fd("Invalid arguments! Use ./cub3D maps/[usable_map]", 2);
	return (c);
}