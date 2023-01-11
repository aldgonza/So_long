/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldgonza <aldgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:50:40 by aldgonza          #+#    #+#             */
/*   Updated: 2023/01/11 18:56:07 by aldgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

typedef struct	s_img {
	void		*image;
	int			img_heigth;
	int			img_width;
	int			position_x;
	int			position_y;
}				t_img;

typedef struct	s_data {
	void		*mlx;
	void		*window;
	char		**map;
	t_img		m_wall;
	t_img		m_char;
}				t_data;
///////ERASE BEFORE DEFENSE////////
# include <stdio.h>
///////ERASE BEFORE DEFENSE////////
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "minilibx/mlx.h"
# include "GNL/get_next_line.h"

	int	so_long(char **map);
	char	*get_next_line(int fd);
#endif
