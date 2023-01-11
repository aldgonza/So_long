/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldgonza <aldgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:32:46 by aldgonza          #+#    #+#             */
/*   Updated: 2023/01/11 16:36:40 by aldgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_input(int keycode, t_data *game)
{
	mlx_clear_window(game->mlx, game->window);
	if (keycode == 2)
		game->position_x += game->img_width;
	else if (keycode == 0)
		game->position_x -= game->img_width;
	else if (keycode == 1)
		game->position_y += game->img_heigth;
	else if (keycode == 13)
		game->position_y -= game->img_heigth;
	else if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->window);
		exit(0);
	}
	printf("key-> %d\nx_pos-> %d\ny_pos-> %d\n", keycode,
		game->position_x, game->position_y);
	return(0);
}

int	ft_update(void *param)
{
	t_data		*program = (t_data *)param;
	static int	frame;

	frame++;
	if (frame == ANIMATION_FRAMES)
		program->position_y += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->position_y -= 1;
		frame = 0;
	}

	mlx_put_image_to_window(program->mlx, program->window,
		program->image, program->position_x,
		program->position_y);
	return(0);
}

int	so_long()
{
	t_data	game;

	//////////////////////MLX_SERVER
	game.mlx = mlx_init();
	//////////////////////MLX_WINDOW
	game.window = mlx_new_window(game.mlx, 800, 400, "Test");
	//////////////////////CREATING_SPRITE
	game.image = mlx_xpm_file_to_image(game.mlx,"sprites/xpm/idle00.xpm",
			&game.img_width, &game.img_heigth);
	game.position_x = 400;
	game.position_y = 200;

	mlx_put_image_to_window(game.mlx, game.window,
		game.image, game.position_x, game.position_y);

	mlx_hook(game.window, 2, 0, *ft_input, &game);
	mlx_loop_hook(game.mlx, *ft_update, &game);

	mlx_loop(game.mlx);
	return (0);
}
