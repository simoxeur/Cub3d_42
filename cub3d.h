/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:30:52 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/24 15:59:06 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line/get_next_line.h"
# include "utils/utils.h"
# include "parse/parse.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define TILE_SIZE 64
# define HEIGHT 720
# define WIDTH 1280

# define FOV 60
# define N_RAYS WIDTH

typedef struct s_allocate
{
	void				*ptr;
	struct s_allocate	*next;
}	t_allocate;

typedef struct s_ray_utils
{
	double	x;
	double	y;
	double	xstep;
	double	ystep;
	double	x_tocheck;
	double	y_tocheck;
	int		hitt;
	int		open_door;
}	t_ray_utils;

typedef struct s_ray
{
	double		ray_dst;
	double		wall_height;
	double		top_wall;
	double		bot_wall;
	double		ray_angle;
	double		v_hittx;
	double		v_hitty;
	double		h_hittx;
	double		h_hitty;
	double		wall_hitt_x;
	double		wall_hitt_y;
	char		element_hitt;
	char		h_element_hitt;
	char		v_element_hitt;
	int			horizontal_hitt;
	int			vertical_hitt;
	int			is_facing_up;
	int			is_facing_down;
	int			is_facing_left;
	int			is_facing_right;
	t_allocate	*allocation;
}	t_ray[N_RAYS];

typedef struct t_wind
{
	void		*mlx;
	void		*img;
	void		*inimate_img;
	int			x;
	int			y;
}	t_wind;

typedef struct s_player
{
	double	x;
	double	y;
	char	sym;
	double	step_size;
	double	turn_speed;
	int		walk_direction;
	double	angle;
}	t_player;

typedef struct s_data
{
	char			**map;
	char			**filled_map;
	int				h;
	int				w;
	int				height;
	int				width;
	char			*map_path;
	int				fd;
	char			*d_texture;
	mlx_texture_t	*door_texture;
	mlx_texture_t	*wall_texture[4];
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	mlx_image_t		*torch_img;
	mlx_texture_t	**torch_frames;
	int				*floor_color;
	int				*ceiling_color;
	int				err_no;
	int				mouse_move;
	int				lum;
	int				f_lum;
	int				c_lum;
	int				hold_lamp;
	t_player		*player;
	t_allocate		*allocation;
	t_wind			*window;
	t_ray_utils		*ray_utils;
	t_ray			ray[N_RAYS];
}	t_data;

// graphic stuff
int			init_values(t_data *data);
int			graphic_handle(t_data *data);
void		key_hook(mlx_key_data_t key, void *param);
void		ray_init(t_data *data);
void		ray_handler(t_data *data);
int			render3d(t_data *map);
void		render_minimap(t_data *data);
void		render_torch(t_data *data);
void		load_torch_frames(t_data *data);
mlx_image_t	*load_frame(t_data *data, mlx_texture_t *texture);

int			extract_color(int *color, int lum);
int			darken_color(int color, float factor);
void		move_player(t_data *data, int direction);

// ray_cast utils
void		h_wall_hitt(t_data *data, int i);
void		v_wall_hitt(t_data *data, int i);
double		fix_angle(double angle);
void		dst_cmp(t_data *data, double h_dst, double v_dst, int i);
void		ray_init(t_data *data);
int			no_wall(t_data *data, double x, double y);
double		new_pos_x(t_data *data, int direction);
double		new_pos_y(t_data *data, int direction);
void		new_position(t_data *data, int direction);
int			find_offset_x(t_data *data, int r_i);

// render
int			render(t_data *data);
void		draw(t_data *data, int r_i, double top_pix, double bot_pix);
int			wall_direction(t_data *data, int r_i);
double		scale_offset(t_data *data, double offset, int direction, char c);

// textures
int			init_texture(t_data *data);
int			texture_pixel_color(t_data *data, int x, int y, int d);
int			texture_door_pixel_color(t_data *data, int x, int y);
int			texture_valid(char *texture);

// used
void		my_puts(char *str, int fd);
void		error_mlx(t_data *data);
void		clean_close(t_data *data);

//allocation
void		*ft_malloc(t_allocate **lst_ptr, size_t size);
void		*add_address(t_allocate **lst_ptr, void *ptr);
void		clean_up(t_allocate **lst_ptr);
void		struct_init(t_data *map);

#endif
