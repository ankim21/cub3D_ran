/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:57:57 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/03/03 15:56:32 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char	**array;
	int		start;
	int		max_length;
	int		max_width;
}	t_map;

// float px, py 
// for rotations of player, sin/cos/tan and PI
// sin/cos/tan 2pi (6.28 value) - in C we go in radians so not 360 like in degrees, but radians
// define player position as px,py,playerdeltax, playerdeltay, as well as p_angle 

// look left (0.1) change bc need to be smaller

typedef struct s_player
{
	int		is_player;
	char	orientation;
	int		move_x;
	int		move_y;
}	t_player;

typedef struct s_assets // why assets east,west,north,south char?
{
	char	*east;
	char	*west;
	char	*north;
	char	*south;
	int		ceiling[3];
	int		ceiling_color;
	int		ceiling_flag;
	int		floor[3];
	int		floor_color;
	int		floor_flag;
}	t_assets;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	time; // what are these
	double	old_time; // why 
	double	cam_x;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		line_height;
	int		side;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	double	old_dir_x;
	double	old_plane_x;
	int		tex_x;
	int		tex_y;
}	t_ray;

typedef struct s_textures
{
	struct s_img	n_wall;
	struct s_img	s_wall;
	struct s_img	w_wall;
	struct s_img	e_wall;
}	t_textures;

typedef struct s_game
{
	int					fd;
	struct s_map		map;
	struct s_player		player;
	struct s_assets		assets;
	struct s_ray		ray;
	struct s_textures	textures;
	t_img				img;
	void				*mlx;
	void				*mlx_win;
}	t_game;

#endif