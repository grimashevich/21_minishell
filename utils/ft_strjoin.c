/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:36:45 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 16:37:51 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strcpy(const char *from, char *to);
size_t	ft_strlen(const char *string);

char	*ft_strjoin(char *one, char *two)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = ft_strlen(one);
	j = ft_strlen(two);
	new = (char *)malloc(sizeof(char) * (i + j + 1));
	if (new == NULL)
		return (NULL);
	ft_strcpy(one, new);
	ft_strcpy(two, new + i);
	return (new);
}
