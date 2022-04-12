/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:33:11 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/25 14:33:13 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

int	ft_digittoint(int character);
int	ft_isalnum(int character);
int	ft_isalpha(int character);
int	ft_isblank(int character);
int	ft_iscntrl(int character);
int	ft_isdigit(int character);
int	ft_isgraph(int character);
int	ft_islower(int character);
int	ft_isprint(int character);
int	ft_ispunct(int character);
int	ft_isspace(int character);
int	ft_isupper(int character);
int	ft_isxdigit(int character);
int	ft_toascii(int character);
int	ft_toupper(int character);
int	ft_tolower(int character);

#endif // FT_CTYPE_H
