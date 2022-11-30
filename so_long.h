/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldgonza <aldgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:50:40 by aldgonza          #+#    #+#             */
/*   Updated: 2022/11/30 15:48:38 by aldgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

typedef struct	s_data {
	void		*mlx;
	void		*window;
	void		*image;
	int			position_x;
	int			position_y;
	int			img_heigth;
	int			img_width;
}				t_data;

# include <stdio.h>

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "minilibx/mlx.h"
	int	so_long();
#endif
