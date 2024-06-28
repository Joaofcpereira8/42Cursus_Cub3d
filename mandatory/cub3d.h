/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:31:28 by jofilipe          #+#    #+#             */
/*   Updated: 2024/06/28 16:53:18 by bbento-e         ###   ########.fr       */
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

# define HEIGHT 995.0
# define WIDTH 1920.0
# define IMG_H 128
# define IMG_W 128
# define FOV 0.8

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
	int			mapx;
	int			mapy;
	int			imgx;
	int			imgy;
	int			line_h;
	int			begn_draw;
	int			end_draw;
	int			fd;
	int			wcnt;
	int			lin_cnt;
	int			plr_cnt;
	int			flagfill;
	int			line_no;
	int			*flo;
	int			*cei;
	int			plr_up;
	int			plr_dn;
	int			plr_lf;
	int			plr_rg;
	int			plr_lk_l;
	int			plr_lk_r;
	float		plx;
	float		ply;
	double		dirx;
	double		diry;
	double		wallx;
	double		pln_x;
	double		pln_y;
	double		imgstp;
	double		imgpos;
	double		rayx;
	double		rayy;
	double		dst_rght;
	double		dst_left;
	double		delta_x;
	double		delta_y;
	double		perpend_wl;
	double		camx;
	char		posi;
	char		ori;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		**map;
	char		**mp_dp;
	char		**map_verif;
	void		*mlx;
	void		*win;
	t_img		*bg;
	t_img		*cr;
	t_img		*no;
	t_img		*so;
	t_img		*ea;
	t_img		*ws;
}			t_cubed;

// ------- VARIABLE_STRUCT -------
t_cubed		*cub(void);

// ------- START GAME -------
void		ttptg(void);
int			cub_loop(void);

// ------- IMAGE -------
int			get_address(void);
int			get_address2(void);
int			draw_textures(void);
int			text_size(int width, int height);

// ------- DRAW -------
void		draw_bkgnd(int ceil, int flr);
void		my_mlx_pixel_put(int x, int y, int color);

// ------- ERRORS -------
int			args_error(int c);
int			file_err_msg(char c, int fd);

// ------- INIT -------
void		cub_init(void);
void		cub_init2(void);
void		cub_init3(void);

// ------- VERIFICATIONS -------
int			width_x(void);
int			height_y(void);
int			map_verif(void);
int			wall_check(void);
int			file_verif(char *file);
int			plr_pos_verif(int x, int y);
void		plr_pos_verif2(int x, int y);

// ------- PARSER -------
int			map_par(char *file);
char		*get_path(char *str);
int			textures_verif(void);
int			*get_value(char *str);
int			textures_verif2(void);
int			textures_verif3(void);
int			textures_verif4(void);
int			map_to_var(char *file);
int			count_lines(char *file);
int			map_settings(char *file);
int			map_configure(char *file);

// ------- MAP UTILS -------
int			east_text(char *temp);
int			west_text(char *temp);
int			floor_text(char *temp);
int			north_text(char *temp);
int			south_text(char *temp);
int			check_frst_wall(int x);
int			ceiling_text(char *temp);
int			jmp_and_verif(int y, int x);
int			verif_inside_map(int y, int z);

// ------- PLAYER -------
void		plyr_dir(void);

// ------- MOVEMENT -------
int			key_hook(int key);
void		ver_movi(int flag);
void		hor_movi(int flag);
int			plr_movement(void);
int			key_dehook(int key);
void		plr_rotate(int flag);

// ------- RAYCAST -------
void		ray(void);
void		dda(void);
void		draw(int x);
void		wall_e(void);
void		ray_dir(void);
void		hit_reg(void);
void		ray_calc(void);
void		asgn_txtr(void);

// ------- PROGRAM INFO -------
bool		is_map(char *str);
void		flag_change(void);
bool		check_attr(char c);
bool		isnt_map(char *str);

// ------- UTILS -------
int			press_x(void);
int			walls_verif(int y);
int			path_len(char *str);
int			check_overflow(char *str);
int			create_trgb(int *rgb, int t);
int			ign_spaces(char *str, int i);
int			get_value2(int *res, char *temp, char **aux, int i);

// ------- FREES -------
void		free_mlx(void);
void		free_mlx2(void);
void		free_struct(void);
void		free_arr(char **arr);
void		partial_free(int *res, char *temp, char **aux);

#endif
