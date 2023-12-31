/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogozturk <ogozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:39:06 by ogozturk          #+#    #+#             */
/*   Updated: 2023/03/16 19:39:07 by ogozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

static int	exit_game(t_game *game)
{
	free_all(game);
	exit(0);
}

static bool	ft_namecheck(char *str, char *find)
{
	char	*ber_str;

	ber_str = ft_strrchr(str, '.');
	if (ber_str && ft_strlen(ber_str) == 4
		&& ft_strncmp(ber_str, ".cub", 4) == 0)
		return (true);
	return (false);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2 && ft_namecheck(av[1], ".cub"))
	{
		check_map(&game, av[1]);
		mlx_hook(game.window, 2, 1L << 0, key_press, &game);
		mlx_hook(game.window, 3, 1L << 1, key_release, &game);
		mlx_hook(game.window, 17, 0, exit_game, &game);
		mlx_do_sync(game.mlx);
		mlx_loop_hook(game.mlx, update, &game);
		mlx_loop(game. mlx);
	}
	else
		printf("Invalid arguments\n");
	return (0);
}
