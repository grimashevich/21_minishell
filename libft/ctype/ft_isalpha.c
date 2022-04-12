/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:33:51 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/25 14:33:52 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int character)
{
	return ((character >= 65 && character <= 90) + \
			(character >= 97 && character <= 122));
}
