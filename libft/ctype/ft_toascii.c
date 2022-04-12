/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:34:06 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/25 14:34:07 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toascii(int character)
{
	if ((unsigned char)character <= 127)
		return ((unsigned char)(character));
	else
		return ((unsigned char)(character) - 128);
}
