/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:33:54 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/25 14:33:55 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isblank(int character)
{
	return (character == 9 || character == 32);
}