/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:20:43 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/19 18:20:43 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	floor_text(char *temp)
{
	if (cub()->flo)
	{
		free(temp);
		return (file_err_msg('c', cub()->fd));
	}
	cub()->flo = get_value(temp);
	if (!cub()->flo)
	{
		free(temp);
		return (file_err_msg('c', cub()->fd));
	}
	return (0);
}

int	ceiling_text(char *temp)
{
	if (cub()->cei)
	{
		free(temp);
		return (file_err_msg('c', cub()->fd));
	}
	cub()->cei = get_value(temp);
	if (!cub()->cei)
	{
		free(temp);
		return (file_err_msg('c', cub()->fd));
	}
	return (0);
}
