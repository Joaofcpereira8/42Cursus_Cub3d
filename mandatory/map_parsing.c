/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:50:20 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/28 16:53:35 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*get_value(char *str)
{
	int		i;
	int		*res;
	char	*temp;
	char	**aux;

	aux = NULL;
	i = ign_spaces(str, 0) + 1;
	i = ign_spaces(str, i);
	if (check_overflow(str + i) == -1)
		return (0);
	res = malloc(sizeof(int) * 3);
	temp = ft_strtrim(str + i, "\n");
	aux = ft_split(temp, ',');
	i = 0;
	if (get_value2(res, temp, aux, i) == -1)
		return (NULL);
	free(temp);
	free_arr(aux);
	return (res);
}

char	*get_path(char *str)
{
	int			i;
	int			len;
	char		*res;
	char		*aux;

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
	if (len <= 10)
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
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		if (temp[0] != '\n' && temp[0] != '\0')
			total++;
		if (temp[0] == '\t')
		{
			free(temp);
			return (-1);
		}
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (total);
}

int	map_par(char *file)
{
	if (map_to_var(file) == -1)
		return (-1);
	if (map_configure(file) == -1)
		return (-1);
	if (map_settings(file) == -1)
		return (-1);
	if (textures_verif() == -1)
		return (-1);
	if (map_verif() == -1)
		return (-1);
	return (0);
}
