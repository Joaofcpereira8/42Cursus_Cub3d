/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:54:24 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/21 12:54:24 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_verif(char *file)
{
	int	i;

	cubed()->fd = open(file, O_RDONLY);
	i = ft_strlen(file) - 1;
	while (file[i] != '.')
		i--;
	if (ft_strncmp(file + i, ".cub", 5) != 0)
		return (file_err_msg('a', cubed()->fd));
	if (cubed()->fd < 0)
		return (file_err_msg('b', cubed()->fd));
	close(cubed()->fd);
	return (0);
}