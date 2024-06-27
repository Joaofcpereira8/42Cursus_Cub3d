/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:09:33 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/25 15:27:20 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to initialize and read the first line
char	*init_and_read_first_line(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	return (get_next_line(*fd));
}

// Function to process a single line
int	process_line(char *temp, int fd)
{
	char	*help;

	help = temp;
	while (*help == ' ')
		help++;
	if (ft_strncmp(help, "NO", 2) == 0)
		return (north_text(temp));
	if (ft_strncmp(help, "SO", 2) == 0)
		return (south_text(temp));
	if (ft_strncmp(help, "EA", 2) == 0)
		return (east_text(temp));
	if (ft_strncmp(help, "WE", 2) == 0)
		return (west_text(temp));
	if (ft_strncmp(help, "F", 1) == 0)
		return (floor_text(temp));
	if (ft_strncmp(help, "C", 1) == 0)
		return (ceiling_text(temp));
	if (ign_spaces(temp, 0) <= 0)
		return (file_err_msg('A', fd));
	return (0); // Success
}

// Function for final checks and cleanup
int	final_checks_and_cleanup(char *temp, int fd)
{
	if (!check_attr('A') && is_map(NULL))
	{
		free(temp);
		return (file_err_msg('A', fd));
	}
	free(temp);
	close(fd);
	return (0); // Success
}

// Refactored map_settings function
int	map_settings(char *file)
{
	int		fd;
	char	*temp;

	temp = init_and_read_first_line(file, &fd);
	while ((temp != NULL) && !is_map(temp))
	{
		if (process_line(temp, fd) == -1)
		{
			close(fd);
			return (-1);
		}
		free(temp);
		temp = get_next_line(fd);
	}
	return (final_checks_and_cleanup(temp, fd));
}
