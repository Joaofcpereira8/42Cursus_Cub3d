/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:06:41 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/25 15:25:37 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	north_text(char *temp)
{
	if (cub()->north)
	{
		free(temp);
		return (file_err_msg('t', cub()->fd));
	}
	cub()->north = get_path(temp);
	if (!cub()->north)
	{
		free(temp);
		return (file_err_msg('t', cub()->fd));
	}
	return (0);
}

int	south_text(char *temp)
{
	if (cub()->south)
	{
		free(temp);
		return (file_err_msg('t', cub()->fd));
	}
	cub()->south = get_path(temp);
	if (!cub()->south)
	{
		free(temp);
		return (file_err_msg('t', cub()->fd));
	}
	return (0);
}

int	east_text(char *temp)
{
	if (cub()->east)
	{
		free(temp);
		return (file_err_msg('t', cub()->fd));
	}
	cub()->east = get_path(temp);
	if (!cub()->east)
	{
		free(temp);
		return (file_err_msg('t', cub()->fd));
	}
	return (0);
}

int	west_text(char *temp)
{
	if (cub()->west)
	{
		free(temp);
		return (file_err_msg('t', cub()->fd));
	}
	cub()->west = get_path(temp);
	if (!cub()->west)
	{
		free(temp);
		return (file_err_msg('t', cub()->fd));
	}
	return (0);
}
