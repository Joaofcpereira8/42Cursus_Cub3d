/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:50:20 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/21 18:50:20 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_settings(char *file)
{
	int	i;
	char	*temp;

	i = 0;
	cubed()->fd = open(file, O_RDONLY);
	while (cubed()->fd)
	{
		temp = get_next_line(cubed()->fd);
		if (!temp)
			break ;
		if (ft_strncmp(temp, "NO", 2) == 0)
		{
			printf("encontrou!\n");
		}
		if (ft_strncmp(temp, "SO", 2) == 0)
			printf("encontroU!\n");
		if (ft_strncmp(temp, "EA", 2) == 0)
			printf("encontrOU!\n");
		if (ft_strncmp(temp, "WE", 2) == 0)
			printf("encontROU!\n");
		if (ft_strncmp(temp, "F", 1) == 0)
			printf("ANOTHER!");
		if (ft_strncmp(temp, "C", 1) == 0)
			printf("ONE!");
	}
	close(cubed()->fd);
	return (0);
}

int	map_par(char *file)
{
	map_settings(file);
	return (0);
}