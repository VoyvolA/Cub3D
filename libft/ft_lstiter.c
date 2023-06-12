/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogozturk <ogozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:35:44 by ogozturk          #+#    #+#             */
/*   Updated: 2023/03/16 19:35:44 by ogozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (lst != NULL)
	{
		tmp = lst;
		while (1)
		{
			f(tmp->content);
			tmp = tmp->next;
			if (tmp == NULL)
				return ;
		}
	}
}
