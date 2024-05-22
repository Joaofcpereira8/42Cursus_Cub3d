/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:29:44 by bbento-e          #+#    #+#             */
/*   Updated: 2024/05/22 17:33:42 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ign_spaces(char *str, int i)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

int	ign_map_spaces(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int check_overflow(char *str, int target)
{
	int i;
	int n_quo;

	i = 0;
	n_quo = 0;
	while (str && str[i])
	{
		if (str[i] == ',')
			n_quo++;
		if (i > target || (!ft_isdigit(str[i]) && str[i] != ',' && str[i] != '\n'))
			return (-1);
		if (str[i] == ',' && (!ft_isdigit(str[i + 1]) || i == 0))
			return (-1);
		i++;
	}
	if (n_quo != 2)
		return (-1);
	return (i);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}