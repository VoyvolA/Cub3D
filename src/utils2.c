/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogozturk <ogozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:39:35 by ogozturk          #+#    #+#             */
/*   Updated: 2023/03/16 19:39:36 by ogozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_color(char *str)
{
	char	**double_array;
	int		result;

	double_array = ft_split(str, ',');
	result = ft_atoi(double_array[0]) * 256 * 256
		+ ft_atoi(double_array[1]) * 256 + ft_atoi(double_array[2]);
	free_2d_array(double_array);
	return (result);
}

void	free_all(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	free(game->draw);
	free(game->image->addr);
	free(game->image->img);
	free(game->image);
	free(game->keys);
	free(game->pdata);
	free(game->ray);
	free(game->tex->ea->addr);
	free(game->tex->no->addr);
	free(game->tex->so->addr);
	free(game->tex->we->addr);
	free(game->tex->ea->img);
	free(game->tex->no->img);
	free(game->tex->so->img);
	free(game->tex->we->img);
	free(game->tex->ea);
	free(game->tex->no);
	free(game->tex->so);
	free(game->tex->we);
	free(game->tex);
	free(game->minimap);
	free_2d_array(game->map);
}

int	len_2d_into(char **s)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (s[++i])
		j += ft_strlen(s[i]);
	return (j + i);
}
