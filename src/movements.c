/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogozturk <ogozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:39:15 by ogozturk          #+#    #+#             */
/*   Updated: 2023/03/16 19:39:17 by ogozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	go_east(t_game *game)
{
	if (game->map[(int)(game->pdata->pos_y)][(int)(game->pdata->pos_x + game->pdata->plane_x * game->pdata->speed)] != 49)
		game->pdata->pos_x += game->pdata->plane_x * game->pdata->speed;
	if (game->map[(int)(game->pdata->pos_y + game->pdata->plane_y * game->pdata->speed)][(int)(game->pdata->pos_x)] != 49)
		game->pdata->pos_y += game->pdata->plane_y * game->pdata->speed;
}

void	go_west(t_game *game)
{
	if (game->map[(int)(game->pdata->pos_y - game->pdata->plane_y * game->pdata->speed)][(int)game->pdata->pos_x] != 49)
		game->pdata->pos_y -= game->pdata->plane_y * game->pdata->speed;
	if (game->map[(int)(game->pdata->pos_y)][(int)(game->pdata->pos_x - game->pdata->plane_x * game->pdata->speed)] != 49)
		game->pdata->pos_x -= game->pdata->plane_x * game->pdata->speed;
}

void	go_north(t_game *game)
{
	if (game->map[(int)game->pdata->pos_y][(int)(game->pdata->pos_x + game->pdata->dir_x * game->pdata->speed)] != 49)
		game->pdata->pos_x += game->pdata->dir_x * game->pdata->speed;
	if (game->map[(int)(game->pdata->pos_y + game->pdata->dir_y * game->pdata->speed)][(int)game->pdata->pos_x] != 49)
		game->pdata->pos_y += game->pdata->dir_y * game->pdata->speed;
}

void	go_south(t_game *game)
{
	if (game->map[(int)game->pdata->pos_y][(int)(game->pdata->pos_x - game->pdata->dir_x * game->pdata->speed)] != 49)
		game->pdata->pos_x -= game->pdata->dir_x * game->pdata->speed;
	if (game->map[(int)(game->pdata->pos_y - game->pdata->dir_y * game->pdata->speed)][(int)(game->pdata->pos_x)] != 49)
		game->pdata->pos_y -= game->pdata->dir_y * game->pdata->speed;
}

void	rotate_right(t_player *p)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = p->dir_x;
	p->dir_x = p->dir_x * cos(-p->rot_speed) - p->dir_y * sin(-p->rot_speed);
	p->dir_y = old_dirx * sin(-p->rot_speed) + p->dir_y * cos(-p->rot_speed);
	old_planex = p->plane_x;
	p->plane_x = p->plane_x * cos(-p->rot_speed)
		- p->plane_y * sin(-p->rot_speed);
	p->plane_y = old_planex * sin(-p->rot_speed)
		+ p->plane_y * cos(-p->rot_speed);
}
