/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:29:01 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 16:29:02 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strcpy(const char *from, char *to);
size_t	ft_strlen(const char *string);

char	*ft_strdup(const char *string)
{
	char	*duplicate;

	duplicate = (char *)malloc(sizeof(char) * (ft_strlen(string) + 1));
	if (duplicate == NULL)
		return (NULL);
	ft_strcpy(string, duplicate);
	return (duplicate);
}
