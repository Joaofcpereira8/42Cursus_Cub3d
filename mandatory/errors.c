/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:13:46 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/29 16:36:46 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file_err_msg(char c, int fd)
{
	if (c == 'a')
		ft_putstr_fd("Error\nMap format is wrong. Use [executable]"
			" maps/[map_name].cub!\n", 2);
	else if (c == 'b')
		ft_putstr_fd("Error\nFile not found. Use [path]/[mapname].cub\n", 2);
	else if (c == 'c')
		ft_putstr_fd("Error\nWrong color attribution.\n", 2);
	else if (c == 'd')
		ft_putstr_fd("Error\nThe map you've designed is wrong.\n", 2);
	else if (c == 't')
		ft_putstr_fd("Error\nWrong texture attribution.\n", 2);
	else if (c == 'p')
		ft_putstr_fd("Error\nPlayer does not exist in map\n", 2);
	else if (c == 'w')
		ft_putstr_fd("Error\nWalls not closed\n", 2);
	else if (c == 'T')
		ft_putstr_fd("Error\nTexture file not found.\n", 2);
	else if (c == 'A')
		ft_putstr_fd("Error\nThe attribution of values failed."
			"Please check your file.\n", 2);
	if (fd)
		close(fd);
	return (-1);
}

int	args_error(int c)
{
	ft_putstr_fd("Invalid arguments! Use ./cub3D maps/[usable_map]", 2);
	return (c);
}
