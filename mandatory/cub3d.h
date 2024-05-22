/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:31:28 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/22 18:27:46 by bbento-e         ###   ########.fr       */
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
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int 	*flo;
	int 	*cei;
}			t_cubed;

// ------- VARIABLE_STRUCT -------
t_cubed		*cubed(void);

// ------- MAP_VERIFICATION -------
int			map_verif(char *file);

// ------- ERRORS -------
int			file_err_msg(char c, int fd);
int			args_error(int c);

// ------- INIT -------
void		cub_init(void);

// ------- PARSER -------
int			map_par(char *file);
char		*get_path(char *str);
int			*get_value(char *str);
int			map_settings(char *file);

// ------- UTILS -------
int			path_len(char *str);
int			ign_spaces(char *str, int i);
int			ign_map_spaces(char *str, int i);
int			check_overflow(char *str, int target);

// ------- FREES -------
void		free_arr(char **arr);

#endif