/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldgonza <aldgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:32:46 by aldgonza          #+#    #+#             */
/*   Updated: 2023/01/11 19:21:14 by aldgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_map(char **map, t_data *game, t_img *tile)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while(map[i] != NULL)
	{
		while(map[i][j] != '\0')
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window,
						tile->image, x, y);
			x += tile->img_width;
			j++;
		}
		i++;
		j = 0;
		x = 0;
		y += tile->img_heigth;
	}
	return (0);
}

int	ft_input(int keycode, t_data *game)
{
	mlx_clear_window(game->mlx, game->window);
	if (keycode == 2)
		game->m_char.position_x += game->m_char.img_width;
	else if (keycode == 0)
		game->m_char.position_x -= game->m_char.img_width;
	else if (keycode == 1)
		game->m_char.position_y += 32;
	else if (keycode == 13)
		game->m_char.position_y -= 32;
	else if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->window);
		exit(0);
	}
	printf("key-> %d\nx_pos-> %d\ny_pos-> %d\n", keycode,
		game->m_char.position_x, game->m_char.position_y);
	return(0);
}

int	ft_update(void *param)
{
	t_data		*program = (t_data *)param;
	static int	frame;

	frame++;
	if (frame == ANIMATION_FRAMES)
		program->m_char.position_y += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->m_char.position_y -= 1;
		frame = 0;
	}
	ft_map(program->map, program, &program->m_wall);
	mlx_put_image_to_window(program->mlx, program->window,
		program->m_char.image, program->m_char.position_x,
		program->m_char.position_y);
	return(0);
}

int	ft_window_init(t_data *game, char **map)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (map[i] != NULL)
	{
		i++;
		y = y + 32;
	}
	i = 0;
	while(map[0][i + 1] != '\0')
	{
		i++;
		x = x + 32;
	}
	game->window = mlx_new_window(game->mlx, x, y, "So_long");
	return (0);
}

int	so_long(char **map)
{
	t_data	game;

	game.map = map;
	//////////////////////MLX_SERVER
	game.mlx = mlx_init();
	//////////////////////MLX_WINDOW
	ft_window_init(&game, map);
	//////////////////////CREATING_SPRITE
	game.m_wall.image = mlx_xpm_file_to_image(game.mlx, "sprites/xpm/wall.xpm",
			&game.m_wall.img_width, &game.m_wall.img_heigth);
	game.m_char.image = mlx_xpm_file_to_image(game.mlx, "sprites/xpm/Duck_1.xpm",
			&game.m_char.img_width, &game.m_wall.img_heigth);
	ft_map(map, &game, &game.m_wall);
	game.m_char.position_x = 32;
	game.m_char.position_y = 160;
	mlx_put_image_to_window(game.mlx, game.window,
		game.m_char.image, game.m_char.position_x, game.m_char.position_y);
	mlx_hook(game.window, 2, 0, *ft_input, &game);
	mlx_loop_hook(game.mlx, *ft_update, &game);
	mlx_loop(game.mlx);
	return (0);
}
