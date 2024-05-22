/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:31:28 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/20 18:31:28 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_cubed
{
	int		x;
	int		y;
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
}			t_cubed;

//VARIABLE_STRUCT
t_cubed		*cubed(void);

//MAP_VERIFICATION
int			map_verif(char *file);

//ERRORS
int			file_err_msg(char c, int fd);
int			args_error(int c);

//INIT
void		cub_init(void);

//PARSER
int			map_par(char *file);
int			map_settings(char *file);

#endif