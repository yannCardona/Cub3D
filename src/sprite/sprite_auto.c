/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_auto.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:10:11 by ycardona          #+#    #+#             */
/*   Updated: 2023/10/12 10:35:48 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* static int	ft_check_x(int new_x, int new_x_min, int new_x_max, t_game *game)
{
	
	if (0 <= new_x && 0 <= new_x_min
		&& 0 <= new_x_max && new_x < game->map_width
		&& new_x_min < game->map_width
		&& new_x_max < game->map_width)
	{
		if ((game->map[(int)(game->sprite_pos.y)][new_x] == 0
			|| game->map[(int)(game->sprite_pos.y)][new_x] == 3) \
			&& (game->map[(int)(game->sprite_pos.y)][new_x_min] == 0
			|| game->map[(int)(game->sprite_pos.y)][new_x_min] == 3) \
			&& (game->map[(int)(game->sprite_pos.y)][new_x_max] == 0
			|| game->map[(int)(game->sprite_pos.y)][new_x_max] == 3))
			return (0);
	}
	return (1);
} */

static void	ft_check_x(t_vector *new_pos, t_vector sprite_ortho, t_game *game)
{
	double	new_x;
	double	new_x_min;
	double	new_x_max;

	new_x = new_pos->x;
	new_x_min = (new_pos->x - sprite_ortho.x);
	new_x_max = (new_pos->x + sprite_ortho.x);
	if (0 <= new_x && 0 <= new_x_min
		&& 0 <= new_x_max && new_x < game->map_width
		&& new_x_min < game->map_width
		&& new_x_max < game->map_width)
	{
		if ((game->map[(int)(game->sprite_pos.y)][(int)new_x] == 0
			|| game->map[(int)(game->sprite_pos.y)][(int)new_x] == 3) \
			&& (game->map[(int)(game->sprite_pos.y)][(int)new_x_min] == 0
			|| game->map[(int)(game->sprite_pos.y)][(int)new_x_min] == 3) \
			&& (game->map[(int)(game->sprite_pos.y)][(int)new_x_max] == 0
			|| game->map[(int)(game->sprite_pos.y)][(int)new_x_max] == 3))
			return ;
		else
			new_pos->x = game->sprite_pos.x;
	}
}

static void	ft_check_y(t_vector *new_pos, t_vector sprite_ortho, t_game *game)
{
	double	new_y;
	double	new_y_min;
	double	new_y_max;

	new_y = new_pos->y;
	new_y_min = (new_pos->y - sprite_ortho.y);
	new_y_max = (new_pos->y + sprite_ortho.y);
	if (0 < new_y && 0 < new_y_min
		&& 0 < new_y_max && new_y < game->map_height
		&& new_y_min < game->map_height
		&& new_y_max < game->map_height)
	{
		if ((game->map[(int)new_y][(int)(new_pos->x)] == 0
			|| game->map[(int)new_y][(int)(new_pos->x)] == 3) \
			&& (game->map[(int)new_y_min][(int)(new_pos->x)] == 0
			|| game->map[(int)new_y_min][(int)(new_pos->x)] == 3) \
			&& (game->map[(int)new_y_max][(int)(new_pos->x)] == 0
			|| game->map[(int)new_y_max][(int)(new_pos->x)] == 3))
			return ;
		else
			new_pos->y = game->sprite_pos.y;
	}
}

static int	ft_stet_text(t_game *game)
{
	if (game->finger != 0)
	{
		game->sprite_text = game->sprite_text3;
		return (1);
	}
	if (game->counter == 0)
		game->sprite_text = game->sprite_text1;
	if (game->counter == 15)
		game->sprite_text = game->sprite_text2;
	return (0);
}

void	ft_norm_vec(t_vector *vec)
{
	t_vector	vec_old;

	vec_old = *vec;
	vec->x = vec_old.x / sqrt(pow(vec_old.x, 2) + pow(vec_old.y, 2));
	vec->y = vec_old.y / sqrt(pow(vec_old.x, 2) + pow(vec_old.y, 2));
}

void	ft_move_sprite(t_game *game)
{
	t_vector	sprite_dir;
	t_vector	sprite_ortho;
	t_vector	new_pos;
	double		fact;

	if (ft_stet_text(game) != 0)
		return ;
	fact = game->sprite_width / 2.0;
	sprite_dir.x = game->pos.x - game->sprite_pos.x;
	sprite_dir.y = game->pos.y - game->sprite_pos.y;
	ft_norm_vec(&sprite_dir);
	new_pos.x = game->sprite_pos.x + sprite_dir.x * MOV_SPEED;
	new_pos.y = game->sprite_pos.y + sprite_dir.y * MOV_SPEED;
	sprite_ortho.x = -sprite_dir.y * fact / sqrt(pow(-sprite_dir.y, 2) \
	+ pow(sprite_dir.x, 2));
	sprite_ortho.y = sprite_dir.x * fact / sqrt(pow(-sprite_dir.y, 2) \
	+ pow(sprite_dir.x, 2));
	ft_check_x(&new_pos, sprite_ortho, game);
	ft_check_y(&new_pos, sprite_ortho, game);
	game->sprite_pos.x = new_pos.x;
	game->sprite_pos.y = new_pos.y; 
}
