/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:20:09 by bbento-e          #+#    #+#             */
/*   Updated: 2024/05/29 16:28:11 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool check_attr(char c)
{
	if (c == 'T' && (!cubed()->north || !cubed()->south || !cubed()->east
		|| !cubed()->west))
		return (false);
	else if (c == 'C' && (!cubed()->flo || !cubed()->cei))
		return (false);
	else if (c == 'A' && (!cubed()->north || !cubed()->south || !cubed()->east
			|| !cubed()->west || !cubed()->flo || !cubed()->cei))
		return (false);
	return (true);
}