/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:31:13 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/29 16:04:43 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	cub_init();
	if (argc == 2)
	{
		if (file_verif(argv[1]) == -1)
			return (-1);
		if (map_par(argv[1]) == -1)
			return (-1);
		//start();
		free_struct();
	}
	else
		args_error(-1);
	return (0);
}
