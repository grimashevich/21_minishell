/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_min_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 23:07:21 by EClown            #+#    #+#             */
/*   Updated: 2022/04/08 23:10:07 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max_int(int n1, int n2)
{
	if (n1 > n2)
		return n1;
	return n2;
}

int	ft_min_int(int n1, int n2)
{
	if (n1 < n2)
		return n1;
	return n2;
}