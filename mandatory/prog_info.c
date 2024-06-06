/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:20:09 by bbento-e          #+#    #+#             */
/*   Updated: 2024/06/06 18:19:46 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool check_attr(char c)
{
	if (c == 'T' && (!cub()->north || !cub()->south || !cub()->east
					 || !cub()->west))
		return (false);
	else if (c == 'C' && (!cub()->flo || !cub()->cei))
		return (false);
	else if (c == 'A' && (!cub()->north || !cub()->south || !cub()->east
						  || !cub()->west || !cub()->flo || !cub()->cei))
		return (false);
	return (true);
}

bool is_map(char *str)
{
	int i;
	static bool var;

	i = 0;
	if (!var && str)
	{
		ign_spaces(str, i);
			if (str[i] == '1' || str[i] == '0')
				var = true;
	}
	return (var);
}

void flag_change()
{
	cub()->flagfill = -1;
}