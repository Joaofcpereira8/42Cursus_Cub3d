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

int	map_configure(char *file)
{
	char	*line;
	char	*trimmed;
	char	*temp;
	int		i;

	i = 0;
	cub()->lin_cnt = count_lines(file) - 6;
	if (cub()->lin_cnt < 3)
	{
		printf("Error\nInvalid map\n");
		return (-1);
	}
	cub()->line_no = count_lines(file);
	cub()->map = malloc(sizeof(char *) * (cub()->line_no + 1));
	if (!cub()->map)
		return (-1);
	cub()->fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(cub()->fd);
		if (!line)
		{
			free(line);
			break ;
		}
		trimmed = line;
		if (*trimmed == '\n')
		{
			free(trimmed);
			continue ;
		}
		while (*trimmed == ' ' || *trimmed == '\t')
			trimmed++;
		if (ft_isascii(*trimmed) == 1)
		{
			temp = ft_strdup(line);
			(cub()->map[i]) = ft_strtrim(temp, "\n");
			i++;
			free(temp);
		}
		free(line);
	}
	close(cub()->fd);
	cub()->map[i] = NULL;
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
