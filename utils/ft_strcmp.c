/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:59:09 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 21:59:12 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(const char *one, const char *two)
{
	size_t	i;

	i = 0;
	while (one[i] == two[i] && one[i] != '\0')
		i += 1;
	return ((unsigned char)one[i] - (unsigned char)two[i]);
}
