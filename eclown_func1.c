/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eclown_func1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:01:55 by EClown            #+#    #+#             */
/*   Updated: 2022/04/07 21:47:50 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
	some
	s*em
	
	some
	s*me
	
	
	some string
	*s*e *st*ng*
	
	some string4dfgf
	*s*e *st*ng*
	
	
	str1
	st*2
 */


void move_counters(char *str, char *pattern, int *i, int *j)
{
	int	p_at_star;
	int	p_eq_s;
	int	p1_at_star;
	int	p1_eq_s;

	p_at_star = pattern[*i] == '*';
	p_eq_s = pattern[*i] == str[*j];
	p1_at_star = pattern[(*i) + 1] == '*';
	p1_eq_s = pattern[(*i) + 1] == str[*j];
	if ((p_at_star && p1_at_star) || (p_at_star && p1_eq_s))
		(*i)++;
	else if (p_eq_s)
	{
		(*i)++;
		(*j)++;
	}
	else if (p_at_star && ! p1_eq_s)
		(*j)++;
	else
	{
		printf("WARNING WE SHOULD NOT BE HERE!!!\n");
		printf("move_counters()\n");
		printf("p = %c; s = %c;\n", pattern[*i], str[*j]);
	}
}

int	is_matches_pattern(char *pattern, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (pattern[i] && str[j])
	{
		if (pattern[i] != '*' && pattern[i] != str[j])
			return (0);
		move_counters(str, pattern, &i, &j);
	}
	if (pattern[i] == str[j])
		return (1);
	if (pattern[i] == '*' && pattern[i + 1] == 0 && str[j] == 0)
		return (1);
	return (0);
}

int get_lines_count(char **text)
{
	int	n;

	n = 0;
	while (text[n])
		n++;
	return (n);
}

char	**apply_wildcard(char *pattern, char** text)
{
	int		count;
	char	*arr;
	char	*arr2;
	char	**tmp;
	int		i;

	count = get_lines_count(text);
	arr = malloc(sizeof(char *) * (count + 1));
	if (! arr)
		return (NULL);
	tmp = *text;
	i = 0;
	while (tmp)
	{
		if (is_matches_pattern(pattern, tmp))
			arr[i++] = tmp;
		tmp++;
	}
	arr[i] = NULL;
	arr2 = malloc(sizeof(char *) * i + 1);
	if (! arr2)
		return (arr);
	i = -1;
	while (arr[++i])
		arr2[i] = arr[i];
	arr2[i] = NULL;
	free(arr);
	return (arr2);	
}
