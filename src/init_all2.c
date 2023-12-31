/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogozturk <ogozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:38:58 by ogozturk          #+#    #+#             */
/*   Updated: 2023/03/16 19:38:59 by ogozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

void	init_textures(t_game *game)
{
	int	a;

	game->tex = malloc(sizeof(t_textures));
	game->tex->ea = malloc(sizeof(t_data));
	game->tex->we = malloc(sizeof(t_data));
	game->tex->no = malloc(sizeof(t_data));
	game->tex->so = malloc(sizeof(t_data));
	game->tex->ceilingc = 0x33ccff;
	game->tex->floorc = 0x33cc33;
}

void	init_keys(t_game *game)
{
	game->keys = malloc(sizeof(t_keyboard));
	game->keys->left_key = false;
	game->keys->right_key = false;
	game->keys->w_key = false;
	game->keys->a_key = false;
	game->keys->s_key = false;
	game->keys->d_key = false;
	game->keys->shift_key = false;
}

void	init_minimap(t_game *game)
{
	game->minimap = malloc(sizeof(t_minimap));
	game->minimap->x = 0;
	game->minimap->y = 0;
	game->minimap->i = 0;
	game->minimap->py = 0;
	game->minimap->px = 0;
}
