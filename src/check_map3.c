/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogozturk <ogozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:38:50 by ogozturk          #+#    #+#             */
/*   Updated: 2023/03/16 19:38:51 by ogozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool	east_west(t_game *game, char p)
{
	if (p == 'E')
	{
		game->pdata->dir_x = 0.00;
		game->pdata->dir_y = 1.00;
		game->pdata->plane_x = 0.66;
		game->pdata->plane_y = 0;
		return (true);
	}
	else if (p == 'W')
	{
		game->pdata->dir_x = 0.00;
		game->pdata->dir_y = -1.00;
		game->pdata->plane_x = -0.66;
		game->pdata->plane_y = 0;
		return (true);
	}
	return (false);
}

static bool	south_north(t_game *game, char p)
{
	if (p == 'S')
	{
		game->pdata->dir_x = -1.00;
		game->pdata->dir_y = 0.00;
		game->pdata->plane_x = 0;
		game->pdata->plane_y = 0.66;
		return (true);
	}
	else if (p == 'N')
	{
		game->pdata->dir_x = 1.00;
		game->pdata->dir_y = 0.00;
		game->pdata->plane_x = 0;
		game->pdata->plane_y = -0.66;
		return (true);
	}
	return (false);
}

bool	check_player(t_game *game, char p)
{
	if (east_west(game, p))
		return (true);
	if (south_north(game, p))
		return (true);
	return (false);
}
