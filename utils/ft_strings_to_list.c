/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_to_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:09:37 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 20:11:29 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_strings_to_list(char **strings)
{
	t_list	*list;
	t_list	*one;

	list = NULL;
	while (*strings != NULL)
	{
		one = ft_list_new(*strings++);
		if (one == NULL)
		{
			ft_list_remove(one, NULL);
			ft_list_remove_all(&list, NULL);
			return (NULL);
		}
		ft_list_add_back(&list, one);
	}
	return (list);
}
