/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:31:28 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/13 17:57:09 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <stdbool.h>
# include <X11/keysym.h>

# define HEIGHT 995
# define WIDTH 1920.0
# define IMG_H 100
# define IMG_W 100
# define FOV 0.75

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
	int			x;
	int			y;
	int			hit;
	int			rright;
	int			rleft;
	double		dirx;
	double		diry;
	double		rayx;
	double		rayy;
	double		dist_right;
	double		dist_left;
	double		plx;
	double		ply;
	double		mapx;
	double		mapy;
	double		delta_x;
	double		delta_y;
	double		camx;
	double		camy;
	int			fd;
	int			wallflag;
	int			wcnt;
	int			lin_cnt;
	int			plr_cnt;
	int			flagfill;
	int 		line_no;
	int 		*flo;
	int 		*cei;
	void		*mlx;
	void		*win;
	char		posi;
	char		ori;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		**map;
	char		**map_dup;
	t_img 		*bg;
	t_img 		*no;
	t_img 		*so;
	t_img 		*ea;
	t_img 		*ws;
}			t_cubed;

// ------- VARIABLE_STRUCT -------
t_cubed		*cub(void);

// ------- START GAME -------
int	start();
int	cub_loop();
int	draw_textures();

// ------- DRAW -------
t_img		*img_picker(char type);
void		draw_bkgnd(int ceil, int flr);

// ------- ERRORS -------
int			args_error(int c);
int			file_err_msg(char c, int fd);

// ------- INIT -------
void		cub_init(void);

// ------- VERIFICATIONS -------
int			map_verif(void);
int			file_verif(char *file);

// ------- PARSER -------
int			map_par(char *file);
char		*get_path(char *str);
int			*get_value(char *str);
int			count_lines(char *file);
int			map_settings(char *file);
int			map_configure(char *file);
int			count_map_lines(char *file);
void		read_map_lines(char *frst_line, int line_count);

// ------- PLAYER -------
void		plyr_dir();

// ------- MOVEMENT -------
int       key_hook(int key);

// ------- RAYCAST -------
void		ray();
void		dda();
void		hit_reg();

// ------- PROGRAM INFO -------
void		flag_change();
bool		is_map(char *str);
bool		check_attr(char c);

// ------- UTILS -------
int			path_len(char *str);
int			create_trgb(int *rgb, int t);
int			ign_spaces(char *str, int i);
int			ign_map_spaces(char *str, int i);
int			check_overflow(char *str, int target);

// ------- FREES -------
void		free_struct(void);
void		free_arr(char **arr);

#endif