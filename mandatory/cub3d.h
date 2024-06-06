/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:31:28 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/06 14:59:37 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <X11/X.h>
# include <stdbool.h>
# include <X11/keysym.h>

# define HEIGHT 1080
# define WIDTH 1920

typedef struct s_img
{
	char	*addr;
	void	*img;
	int		bpp;
	int		llen;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_cubed
{
	int		x;
	int		y;
	int		fd;
	int		temp_fd;
	int		flagfill;
	int 	line_no;
	int 	*flo;
	int 	*cei;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	**map;
	char	**map_dup;
	t_img 	bg;
	t_img 	no;
	t_img 	so;
	t_img 	ea;
	t_img 	ws;
}			t_cubed;
// ------- VARIABLE_STRUCT -------
t_cubed		*cub(void);

// ------- START GAME -------
int	start();
int	draw_textures();

// ------- FILE_VERIFICATION -------
int			file_verif(char *file);

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
int			count_map_lines(char *file);
void		read_map_lines(char *frst_line, int line_count);
int			map_configure(char *file);

// ------- MAP_VERIFICATION -------
int			map_verif(void);

// ------- PROGRAM INFO -------
bool		check_attr(char c);
void		flag_change();

// ------- UTILS -------
int			path_len(char *str);
int			create_trgb(int *rgb, int t);
int			ign_spaces(char *str, int i);
int			ign_map_spaces(char *str, int i);
int			check_overflow(char *str, int target);

// ------- FREES -------
void		free_arr(char **arr);
void		free_struct(void);

#endif