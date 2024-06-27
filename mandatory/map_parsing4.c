/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:26:31 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/25 15:27:25 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_configure2(char *line, char *trimmed, char *temp, int i)
{
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
			(cub()->map[i++]) = ft_strtrim(temp, "\n");
			free(temp);
		}
		free(line);
	}
	return (i);
}

int	map_configure(char *file)
{
	char	*line;
	char	*trimmed;
	char	*temp;
	int		i;

	line = NULL;
	trimmed = NULL;
	temp = NULL;
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
	i = map_configure2(line, trimmed, temp, i);
	close(cub()->fd);
	cub()->map[i] = NULL;
	return (0);
}
