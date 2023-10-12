/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:44:38 by jalbers           #+#    #+#             */
/*   Updated: 2023/10/12 13:11:50 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Exit the program as failure.
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	get_player_block(t_game *game)
{
	int	new_y;
	int	new_x;

	new_y = (int)game->pos.y;
	new_x = (int)game->pos.x;
	return (game->map[new_y][new_x]);
}

// void	ft_delete(t_game *game)
// {
// 	int	i;

// 	mlx_delete_image(game->mlx, game->mlx_img);
// 	mlx_delete_texture(game->NO);
// 	mlx_delete_texture(game->SO);
// 	mlx_delete_texture(game->WE);
// 	mlx_delete_texture(game->EA);
// 	mlx_delete_texture(game->door);
// 	mlx_delete_texture(game->door_wall_1);
// 	mlx_delete_texture(game->door_wall_2);
// 	mlx_delete_texture(game->sprite_text1);
// 	mlx_delete_texture(game->sprite_text2);
// 	mlx_delete_texture(game->sprite_text3);
// 	mlx_delete_texture(game->finger_left_text);
// 	mlx_delete_texture(game->finger_right_text);
// 	mlx_delete_texture(game->game_over_text);
// 	i = 0;
// 	while (i < (int)game->sky_text->width)
// 		free(game->sky_box[i++]);
// 	free(game->sky_box);
// 	mlx_delete_texture(game->sky_text);
// 	mlx_terminate(game->mlx);
// 	destroy_game(game);
// }

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		handle_error("Wrong number of arguments", NULL);
	game = init_game();
	parse_file(game, argv[1]);
	game->mlx = mlx_init(game->screen_width,
			game->screen_height, "cub3d", false);
	if (!game->mlx)
		ft_error();
	mlx_set_cursor_mode(game->mlx, 0x00034002);
	game->mlx_img = mlx_new_image(game->mlx,
			game->screen_width, game->screen_height);
	if (!game->mlx_img
		|| (mlx_image_to_window(game->mlx, game->mlx_img, 0, 0) < 0))
		ft_error();
	mlx_key_hook(game->mlx, &ft_key_hook, game);
	mlx_cursor_hook(game->mlx, &ft_cursor_hook, game);
	mlx_loop_hook(game->mlx, &ft_plot, game);
	mlx_loop(game->mlx);
	destroy_game(game);
	return (EXIT_SUCCESS);
}
