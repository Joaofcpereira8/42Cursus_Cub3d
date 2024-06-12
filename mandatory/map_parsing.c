/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:50:20 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/07 17:53:06 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_settings(char *file)
{
	char	*temp;

	cub()->fd = open(file, O_RDONLY);
	while (((temp = get_next_line(cub()->fd)) != NULL) && !is_map(temp))
	{
		if (ft_strncmp(temp, "NO", 2) == 0)
		{
			if (cub()->north)
				return (file_err_msg('t', cub()->fd));
			cub()->north = get_path(temp);
			if (!cub()->north)
			{
				free(temp);
				return (file_err_msg('t', cub()->fd));
			}
			printf("North: %s\n", cub()->north); // DEBUG
		}
		else if (ft_strncmp(temp, "SO", 2) == 0)
		{
			if (cub()->south)
				return (file_err_msg('t', cub()->fd));
			cub()->south = get_path(temp);
			if (!cub()->south)
			{
				free(temp);
				return (file_err_msg('t', cub()->fd));
			}
			printf("South: %s\n", cub()->south); // DEBUG
		}
		else if (ft_strncmp(temp, "EA", 2) == 0)
		{
			if (cub()->east)
				return (file_err_msg('t', cub()->fd));
			cub()->east = get_path(temp);
			if (!cub()->east)
			{
				free(temp);
				return (file_err_msg('t', cub()->fd));
			}
			printf("East : %s\n", cub()->east); // DEBUG
		}
		else if (ft_strncmp(temp, "WE", 2) == 0)
		{
			if (cub()->west)
				return (file_err_msg('t', cub()->fd));
			cub()->west = get_path(temp);
			if (!cub()->west)
			{
				free(temp);
				return (file_err_msg('t', cub()->fd));
			}
			printf("West : %s\n", cub()->west); // DEBUG
		}
		else if (ft_strncmp(temp, "F", 1) == 0)
		{
			if (cub()->flo)
				return (file_err_msg('c', cub()->fd));
			cub()->flo = get_value(temp);
			if (!cub()->flo)
			{
				free(temp);
				return (file_err_msg('c', cub()->fd));
			}
			printf("Floor: "); // DEBUG
			printf("%i ", cub()->flo[0]); // DEBUG
			printf("%i ", cub()->flo[1]); // DEBUG
			printf("%i\n", cub()->flo[2]); // DEBUG
		}
		else if (ft_strncmp(temp, "C", 1) == 0)
		{
			if (cub()->cei)
				return (file_err_msg('c', cub()->fd));
			cub()->cei = get_value(temp);
			if (!cub()->cei)
			{
				free(temp);
				return (file_err_msg('c', cub()->fd));
			}
			printf("Ceiling: "); // DEBUG
			printf("%i ", cub()->cei[0]); // DEBUG
			printf("%i ", cub()->cei[1]); // DEBUG
			printf("%i\n", cub()->cei[2]); // DEBUG
		}
		else
			if (ign_spaces(temp, 0) <= 0)
			{
				free(temp);
				return (file_err_msg('A', cub()->fd));
			}
		free(temp);
	}
	if (!check_attr('A') && is_map(NULL))
	{
		free(temp);
		return (file_err_msg('A', cub()->fd));
	}
	free(temp);
	close(cub()->fd);
	return (0);
}

int	*get_value(char *str)
{
	int		i;
	int		*res;
	char	*temp;
	char	**aux;

	aux = NULL;
	i = ign_spaces(str, 0) + 1;
	i = ign_spaces(str, i);
	if (check_overflow(str + i, 11) == -1)
		return (0);
	res = malloc(sizeof(int) * 3);
	temp = ft_strtrim(str + i, "\n");
	aux = ft_split(temp, ',');
	i = 0;
	while (aux && aux[i])
	{
		res[i] = ft_atoi(aux[i]);
		while (res[i] == ' ')
			i++;
		if (i > 2 || res[i] > 255 || res[i] < 0)
		{
			free(res);
			free(temp);
			free_arr(aux);
			return (NULL);
		}
		i++;
	}
	free(temp);
	free_arr(aux);
	return (res);
}

char	*get_path(char *str)
{
	int			i;
	int			len;
	char	*res;
	char	*aux;

	res = NULL;
	if (!str)
		return (NULL);
	i = (ign_spaces(str, 0)) + 2;
	if (str[i] && (str[i] != ' ' && str[i] != '\t'))
		return (0);
	i = ign_spaces(str, i);
	len = path_len(str + i);
	if (len == -1)
		return (0);
	aux = ft_substr(str, i, len + 1);
	res = ft_strtrim(aux, "\n");
	free(aux);
	return (res);
}

int	count_lines(char *file)
{
	char	*temp;
	int		total;
	int		fd;

	total = 0;
	fd = open(file, O_RDONLY);
	while ((temp = get_next_line(fd)) != NULL)
	{
		if (temp[0] != '\n' && temp[0] != '\0' && temp[0] != '\t')
			total++;
		free(temp);
	}
	close(fd);
	return (total);
}

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
	cub()->map = malloc(sizeof(char*) * (cub()->line_no + 1));
	if (!cub()->map)
		return (-1);
	cub()->fd = open(file, O_RDONLY);
	while ((line = get_next_line(cub()->fd)) != NULL)
	{
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
			cub()->map[i] = ft_strtrim(temp, "\n");
			i++;
			free(temp);
		}
		free(line);
	}
	close(cub()->fd);
	cub()->map[i] = NULL;
	return (0);
}

int	map_par(char *file)
{
	int j = -1;
	if (map_configure(file) == -1)
		return (-1);
	if (!cub()->map)
		return -1;
	else
	{
		while (cub()->map[++j])
			printf("%s\n", cub()->map[j]);
	}
	if (map_settings(file) == -1)
		return (-1);
	if (map_verif() == -1)
		return (-1);
	return (0);
}