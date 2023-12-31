/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogozturk <ogozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:39:29 by ogozturk          #+#    #+#             */
/*   Updated: 2023/03/16 19:39:31 by ogozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_str_join(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i])
			str[i] = left_str[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

int	find_double_array_len(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	free_2d_array(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
}

int	no_blank_len(char **str)
{
	int	i;
	int	j;
	int	res;

	i = -1;
	res = 0;
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != ' ')
				res++;
			j++;
		}
		res++;
	}
	return (res);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i]) && (s2[i]))
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
}
