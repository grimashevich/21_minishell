/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digittoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:33:47 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/25 14:33:48 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_digittoint(int character)
{
	if (character >= 48 && character <= 57)
		return (character - 48);
	if (character >= 65 && character <= 70)
		return (character - 55);
	if (character >= 97 && character <= 102)
		return (character - 87);
	return (0);
}
