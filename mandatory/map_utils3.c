/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:25:11 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/25 13:25:12 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_frst_wall(int x)
{
	while (cub()->mp_dp[0][x])
	{
		if (ft_isalnum(cub()->mp_dp[0][x]) == 1)
		{
			if (cub()->mp_dp[0][x] != '1')
				return (file_err_msg('d', 0));
			else
			{
				x++;
				continue ;
			}
		}
		x++;
	}
	return (0);
}

int	jmp_and_verif(int y, int x)
{
	int	temp;

	x = 0;
	if (cub()->mp_dp[y][x] == ' ')
	{
		while (cub()->mp_dp[y][x] == ' ')
			x++;
	}
	temp = ft_strlen(cub()->mp_dp[y]) - 1;
	if ((cub()->mp_dp[y][x] != '1' && cub()->mp_dp[y][x] != ' ')
		&& (cub()->mp_dp[y][temp] != ' ' && cub()->mp_dp[y][temp] != '1'))
		return (file_err_msg('w', 0));
	return (x);
}

int	verif_inside_map(int y, int z)
{
	while (cub()->mp_dp[y][z] != '\0')
	{
		if (plr_pos_verif(z, y) == -1)
			return (-1);
		if ((cub()->mp_dp[y][z] == '0' && !cub()->mp_dp[y + 1])
			|| (cub()->mp_dp[y][z] == '0'
				&& (cub()->mp_dp[y + 1][z] == ' '
					|| cub()->mp_dp[y + 1][z] == '\0')))
			return (file_err_msg('d', 0));
		while (cub()->mp_dp[y][z] == ' ')
			z++;
		if (cub()->mp_dp[y][z] == '0' || cub()->mp_dp[y][z] == '1'
			|| cub()->mp_dp[y][z] == 'N' || cub()->mp_dp[y][z] == 'E'
			|| cub()->mp_dp[y][z] == 'S' || cub()->mp_dp[y][z] == 'W')
			z++;
		else
			return (file_err_msg('d', 0));
	}
	if (cub()->mp_dp[y][z - 1] == '0' && cub()->mp_dp[y][z] == '\0')
		return (file_err_msg('d', 0));
	return (0);
}

int	count_all_lines(char *file)
{
	char	*temp;
	int		total;
	int		fd;

	total = 0;
	fd = open(file, O_RDONLY);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		if (*temp)
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
