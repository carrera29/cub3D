/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:16:33 by fmarin-p          #+#    #+#             */
/*   Updated: 2023/10/17 17:46:34 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

// ERROR MESAGGES
# define RGB_ERROR "Bad syntax for RGB color(s)"
# define EXT_ERROR "Extension not valid"
# define EMPTYFILE_ERROR "Empty file"
# define MISSINGELEM_ERROR "Element(s) missing"
# define EMPTYMAP_ERROR "Map content not found"

# define X 0
# define Y 1

typedef struct s_cub	t_cub;

typedef enum e_mapchar
{
	NORTH = 'N',
	SOUTH = 'S',
	EAST = 'E',
	WEST = 'W',
	NOTHING = '0',
	WALL = '1',
	SPACE = ' ',
}			t_mapchar;

typedef struct s_map
{
	char	**map;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		ceiling_color;
	int		floor_color;

}		t_map;

typedef struct s_cub
{
	t_map	*map_data;
	int		height;
	int		width;
	int		blaz;
	double	pos[2];
	double	dir[2];
	double	plane[2];
	double	angle;

}			t_cub;


// debug.c
void	print_data(t_cub *cub_data);

// error.c
void	error(char *msg, int perror_function);

// load_map_data.c
t_map	*load_map_data(int fd);

// Math
void	rotate_vectors(t_map *map, double x, double y);

#endif