/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:18:11 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/19 19:18:11 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	textures_verif2(void)
{
	int	i;

	i = ft_strlen(cub()->south);
	while (i >= 0 && cub()->south[i] != '.')
		i--;
	if (i <= 0)
	{
		printf("Error\nSouth texture does not have file type\n");
		return (-1);
	}
	if (ft_strncmp(cub()->south + i, ".xpm", 5) != 0)
	{
		printf("Error\nSouth texture does not exist\n");
		return (-1);
	}
	return (0);
}

int	textures_verif3(void)
{
	int	i;

	i = ft_strlen(cub()->east);
	while (i >= 0 && cub()->east[i] != '.')
		i--;
	if (i <= 0)
	{
		printf("Error\nEast texture does not have file type\n");
		return (-1);
	}
	if (ft_strncmp(cub()->east + i, ".xpm", 5) != 0)
	{
		printf("Error\nEast texture does not exist\n");
		return (-1);
	}
	return (0);
}

int	textures_verif4(void)
{
	int	i;

	i = ft_strlen(cub()->west);
	while (i >= 0 && cub()->west[i] != '.')
		i--;
	if (i <= 0)
	{
		printf("Error\nWest texture does not have file type\n");
		return (-1);
	}
	if (ft_strncmp(cub()->west + i, ".xpm", 5) != 0)
	{
		printf("Error\nWest texture does not exist\n");
		return (-1);
	}
	return (0);
}

int	textures_verif(void)
{
	int	i;

	i = ft_strlen(cub()->north);
	while (i >= 0 && cub()->north[i] != '.')
		i--;
	if (i <= 0)
	{
		printf("Error\nNorth texture does not have file type\n");
		return (-1);
	}
	if (ft_strncmp(cub()->north + i, ".xpm", 5) != 0)
	{
		printf("Error\nNorth texture does not exist\n");
		return (-1);
	}
	if (textures_verif2() == -1)
		return (-1);
	if (textures_verif3() == -1)
		return (-1);
	if (textures_verif4() == -1)
		return (-1);
	return (0);
}
