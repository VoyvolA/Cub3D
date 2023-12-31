/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogozturk <ogozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:39:02 by ogozturk          #+#    #+#             */
/*   Updated: 2023/03/16 19:39:03 by ogozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

static void	rotate_cam(t_game *game)
{
	double		old_dirx;
	double		old_planex;
	t_player	*p;

	p = game->pdata;
	if (game->keys->left_key)
	{
		old_dirx = p->dir_x;
		p->dir_x = p->dir_x * cos(p->rot_speed) - p->dir_y * sin(p->rot_speed);
		p->dir_y = old_dirx * sin(p->rot_speed) + p->dir_y * cos(p->rot_speed);
		old_planex = p->plane_x;
		p->plane_x = p->plane_x * cos(p->rot_speed)
			- p->plane_y * sin(p->rot_speed);
		p->plane_y = old_planex * sin(p->rot_speed)
			+ p->plane_y * cos(p->rot_speed);
	}
	if (game->keys->right_key)
		rotate_right(p);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		free_all(game);
		exit(0);
	}
	if (keycode == 13)
		game->keys->w_key = true;
	if (keycode == 1)
		game->keys->s_key = true;
	if (keycode == 123)
		game->keys->left_key = true;
	if (keycode == 124)
		game->keys->right_key = true;
	if (keycode == 49)
		game->keys->shift_key = true;
	if (keycode == 0)
		game->keys->a_key = true;
	if (keycode == 2)
		game->keys->d_key = true;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 13)
		game->keys->w_key = false;
	if (keycode == 1)
		game->keys->s_key = false;
	if (keycode == 123)
		game->keys->left_key = false;
	if (keycode == 124)
		game->keys->right_key = false;
	if (keycode == 49)
		game->keys->shift_key = false;
	if (keycode == 0)
		game->keys->a_key = false;
	if (keycode == 2)
		game->keys->d_key = false;
	return (0);
}

void	movements(t_game *game)
{
	rotate_cam(game);
	if (game->keys->d_key)
		go_east(game);
	if (game->keys->a_key)
		go_west(game);
	if (game->keys->w_key)
		go_north(game);
	if (game->keys->s_key)
		go_south(game);
	if (game->keys->shift_key)
		game->pdata->speed = 0.1f;
	else
		game->pdata->speed = 0.05f;
}
