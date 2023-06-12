/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogozturk <ogozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:33:25 by ogozturk          #+#    #+#             */
/*   Updated: 2023/03/16 19:33:27 by ogozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strnstr(const char *h, const char *find, size_t len)
{
	size_t	c;

	if (*find == '\0' || h == find)
		return ((char *)h);
	c = ft_strlen(find);
	while (*h && c <= len--)
	{
		if (!(ft_strncmp((char *)h, (char *)find, c)))
			return ((char *)h);
		h++;
	}
	return (NULL);
}
