/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:25:12 by EClown            #+#    #+#             */
/*   Updated: 2022/04/09 22:20:37 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**clear_and_finish(char **text, char *str)
{
	int	i;

	i = 0;
	while (text[i])
		free(text[i]);
	free(text);
	free(str);
	return (NULL);
}

static char	**get_pointer_array(char *str, char sep, int words_cnt)
{
	int		i;
	int		j;
	int		n;
	char	**result;

	result = ft_calloc((words_cnt + 1), sizeof(char *));
	if (! result)
		return (NULL);
	i = 0;
	j = 0;
	if (str[i] == 0)
		result[j] = ft_calloc(1, sizeof(char));
	while (str[i])
	{
		n = 0;
		while (str[i] != 0 && str[i++] != sep)
			n++;
		result[j++] = malloc(sizeof(char) * (n + 1));
		if (! result[j - 1])
			return (clear_and_finish(result, str));
		while (str[i] != 0 && str[i] == sep)
			i++;
		n = 0;
	}
	return (result);
}

static void	fill_array(char **text, char *str, char sep)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] != sep && str[i] != 0)
			text[j][n++] = str[i++];
		text[j][n++] = 0;
		while (str[i] == sep)
			i++;
		n = 0;
		j++;
	}
}

char	**ft_split(char *str, char sep)
{
	int		split_cnt;
	char	**result;
	char	*str_trim;
	char	char_to_cut[2];
	int		i;

	if (str == NULL)
		return (NULL);
	char_to_cut[0] = sep;
	char_to_cut[1] = 0;
	str_trim = ft_strtrim(str, char_to_cut);
	split_cnt = 1;
	i = 0;
	while (str_trim[i])
	{
		if (str_trim[i] == sep && str_trim[i + 1] != sep)
			split_cnt++;
		i++;
	}
	result = get_pointer_array(str_trim, sep, split_cnt);
	fill_array(result, str_trim, sep);
	free(str_trim);
	return (result);
}
