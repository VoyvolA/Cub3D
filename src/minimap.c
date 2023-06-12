/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogozturk <ogozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:39:11 by ogozturk          #+#    #+#             */
/*   Updated: 2023/03/16 19:39:12 by ogozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

static void	reset_values(t_game *game)
{
	game->minimap->x = -1;
	game->minimap->y = -1;
	game->minimap->py = 0;
	game->minimap->px = 0;
	game->minimap->i = 0;
}

static void	render_minimap(t_game *game, int color, int pixels_to_draw)
{
	int	i;

	game->minimap->px = game->minimap->x * pixels_to_draw;
	i = 0;
	while (i < pixels_to_draw - 1)
	{
		game->image->addr[game->minimap->py
			* SCREEN_WIDTH + game->minimap->px] = color;
		game->minimap->px++;
		i++;
	}
}

static void	draw_minimap(t_game *game, int pixels_to_draw)
{
	char	c;

	c = game->map[game->minimap->y][game->minimap->x];
	if (c == '1')
		render_minimap(game, 0x00F0F0F0, pixels_to_draw);
	else if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		render_minimap(game, 0, pixels_to_draw);
	if ((game->minimap->y == (int)game->pdata->pos_y)
		&& (game->minimap->x == (int)game->pdata->pos_x))
		render_minimap(game, 0x00FF0000, pixels_to_draw);
}

void	put_image(t_game *game)
{
	int	pixels_to_draw;

	pixels_to_draw = 10;
	reset_values(game);
	while (game->map[++game->minimap->y])
	{
		game->minimap->x = -1;
		while (game->map[game->minimap->y][++game->minimap->x])
		{
			game->minimap->i = 0;
			game->minimap->py = game->minimap->y * pixels_to_draw;
			while (game->minimap->i < pixels_to_draw - 1)
			{
				draw_minimap(game, pixels_to_draw);
				game->minimap->i++;
				game->minimap->py++;
			}
		}
	}
	mlx_put_image_to_window(game->mlx, game->window, game->image->img, 0, 0);
}
