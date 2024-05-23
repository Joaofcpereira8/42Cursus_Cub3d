/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:50:20 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/23 11:23:02 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_settings(char *file)
{
	char	*temp;

	cubed()->fd = open(file, O_RDONLY);
	while (cubed()->fd)
	{
		temp = get_next_line(cubed()->fd);
		if (!temp)
			break ;
		else if (ft_strncmp(temp, "NO", 2) == 0)
		{
			cubed()->north = get_path(temp);
			if (!cubed()->north)
				return (file_err_msg('t', cubed()->fd));
			printf("North: %s\n", cubed()->north);
		}
		else if (ft_strncmp(temp, "SO", 2) == 0)
		{
			cubed()->south = get_path(temp);
			if (!cubed()->south)
				return (file_err_msg('t', cubed()->fd));
			printf("South: %s\n", cubed()->south);
		}
		else if (ft_strncmp(temp, "EA", 2) == 0)
		{
			cubed()->east = get_path(temp);
			if (!cubed()->east)
				return (file_err_msg('t', cubed()->fd));
			printf("East : %s\n", cubed()->east);
		}
		else if (ft_strncmp(temp, "WE", 2) == 0)
		{
			cubed()->west = get_path(temp);
			if (!cubed()->west)
				return (file_err_msg('t', cubed()->fd));
			printf("West : %s\n", cubed()->west);
		}
		else if (ft_strncmp(temp, "F", 1) == 0)
		{
			cubed()->flo = get_value(temp);
			if (!cubed()->flo)
				return (file_err_msg('c', cubed()->fd));
			printf("Floor: ");
			printf("%i ", cubed()->flo[0]);
			printf("%i ", cubed()->flo[1]);
			printf("%i\n", cubed()->flo[2]);
		}
		else if (ft_strncmp(temp, "C", 1) == 0)
		{
			cubed()->cei = get_value(temp);
			if (!cubed()->cei)
				return (file_err_msg('c', cubed()->fd));
			printf("Ceiling: ");
			printf("%i ", cubed()->cei[0]);
			printf("%i ", cubed()->cei[1]);
			printf("%i\n", cubed()->cei[2]);
		}
		free(temp);
	}
	close(cubed()->fd);
	return (0);
}

int	*get_value(char *str)
{
	int		i;
	int		*res;
	char	**aux;

	aux = NULL;
	i = ign_spaces(str, 0) + 1;
	i = ign_spaces(str, i);
	if (check_overflow(str + i, 11) == -1)
		return 0;
	res = malloc(sizeof(int) * 3);
	aux = ft_split(ft_strtrim(str + i, "\n"), ',');
	i = 0;
	while (aux && aux[i])
	{
		res[i] = ft_atoi(aux[i]);
		if (i > 2 || res[i] > 255 || res[i] < 0)
		{
			free(res);
			free_arr(aux);
			return 0;
		}
		i++;
	}
	free_arr(aux);
	return (res);
}

char	*get_path(char *str)
{
	int		i;
	int		len;
	char	*res;

	res = NULL;
	i = ign_spaces(str, 0) + 2;
	if (str && str[i] && (str[i] != ' ' && str[i] != '\t'))
		return 0;
	i = ign_spaces(str, i);
	len = path_len(str + i);
	if (len == -1)
		return (0);
	//res = malloc(sizeof(char) * (len + 1));
	res = ft_substr(str, i, len);
	if (!res)
		return (0);
	res[len + 1] = '\0';
	return (res);
}

int	map_configure(char *file)
{
	(void)file;
	return (0);
}

int	map_par(char *file)
{
	if (map_settings(file) == -1)
		return (-1);
//	if (map_configure(file) == -1)
//		return (-1);
	return (0);
}