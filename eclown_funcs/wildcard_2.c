/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:36:31 by EClown            #+#    #+#             */
/*   Updated: 2022/04/10 19:09:31 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	compare_start(char *str, char *ptrn);
int	compare_end(char *str, char *ptrn);
int	compare_closed_str(char *str, char *ptrn);

int str_wildcard_compare(char *str, char *ptrn)
{
	int		star_cut;
	int		end_cut;
	char	*closed_str;
	char	*closed_ptrn;
	int		result;

	if (find_first_char(ptrn, '*') == -1)
	{
		if (ft_strncmp(str, ptrn, ft_max_int(ft_strlen(str), ft_strlen(ptrn))) == 0)
			return (1);
		return (0);
	}
	star_cut = compare_start(str, ptrn);
	end_cut = -1;
	if (star_cut != -1)
		end_cut = compare_end(str, ptrn);
	if (end_cut == -1)
		return (0);
	closed_str = str_copy(str, star_cut, end_cut);
	if (! closed_str)
		return (0);
	closed_ptrn = str_copy(ptrn, star_cut, end_cut);
	if (! closed_ptrn)
	{
		free(closed_str);
		return(0);
	}
	result = compare_closed_str(closed_str, closed_ptrn);
	free(closed_str);
	free(closed_ptrn);
	return (result);
}

char	**apply_wildcard(char *pattern, char** text)
{
	int		count;
	char	**arr;
	char	**arr2;
	int		i;

	count = get_lines_count(text);
	arr = malloc(sizeof(char **) * (count + 1));
	if (! arr)
		return (NULL);
	i = 0;
	while (*text)
	{
		if (str_wildcard_compare(*text, pattern))
			arr[i++] = *text;
		text++;
	}
	arr[i] = NULL;
	arr2 = malloc(sizeof(char **) * (i + 1));
	if (! arr2)
		return (arr);
	i = -1;
	while (arr[++i])
		arr2[i] = arr[i];
	arr2[i] = NULL;
	free(arr);
	return (arr2);	
}

int	textlen(char **text)
{
	int	result;

	if (text == NULL)
		return (0);
	result = 0;
	while (text[result])
		result++;
	return (result);
}

/* Uncover pattern * in all words excluding starting with '-' (minus)*/
/* char	*expand_wildcard_in_str(char *str)
{
	char	**words;
	int		i;

	if (str == NULL)
		return (NULL);
	if (*str == 0)
		return(ft_strdup(""));
	words = ft_split(str);
	i = 0;
	while (words[i])
	{
		if (find_first_char)		
	}
	ft_free_text(words);
	
} */
