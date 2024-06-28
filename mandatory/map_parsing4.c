/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:26:31 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/28 18:16:29 by bbento-e         ###   ########.fr       */
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

int	nline_bet_map(void)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (cub()->map_verif[i])
	{
		j = 0;
		if (isnt_map(cub()->map_verif[i]) || flag == 1)
		{
			flag = 1;
			if (cub()->map_verif[i][j] && cub()->map_verif[i][j] == '\n')
			{
				while (cub()->map_verif[i - 1][j])
				{
					if (cub()->map_verif[i - 1][j] == '0')
						return (file_err_msg('d', 0));
					j++;
				}
			}
		}
		i++;
	}
	return (0);
}

int	map_to_var(char *file)
{
	char	*line;
	int		i;
	int		fd;
	int		lines_num;

	i = 0;
	fd = open(file, O_RDONLY);
	lines_num = count_all_lines(file);
	if (lines_num <= 0)
		return (file_err_msg('d', fd));
	cub()->map_verif = malloc(sizeof(char *) * (lines_num + 1));
	while (i < lines_num)
	{
		line = get_next_line(fd);
		cub()->map_verif[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	cub()->map_verif[i] = NULL;
	return (nline_bet_map());
}

bool	isnt_map(char *str)
{
	int		i;
	bool	var;

	i = 0;
	var = false;
	if (str)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] == '1' || str[i] == '0')
			var = true;
	}
	return (var);
}
