/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eclown_func1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:01:55 by EClown            #+#    #+#             */
/*   Updated: 2022/04/08 23:16:26 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 

	*abb*bbe*g*

	S-abbbe-N-de--ab-de-de-de-gg-g

 */

int compare_closed_str(char *str, char *ptrn)
{
	int		str_len;
	int		ptrn_len;
	char	**substrs;
	int		result;
	int		i;

	i = 0;
	result = 1;
	str_len = ft_strlen(str);
	ptrn_len = ft_strlen(ptrn);
	if (ptrn_len == 1 && ptrn[0] == '*')
		return (1);
	substrs = ft_split(ptrn, '*');
	if (! substrs)
		return (-1);
	while (substrs[i])
	{
		str = ft_strnstr(str, substrs[i++], ft_strlen(str));
		if (str == NULL && result--)
			break;
		str += ft_strlen(substrs[i++]);
	}
	ft_free_text(substrs);
	return (result);
}

/*
 Return -1 if pattern doesn't mutch
 Returns the number of characters matched at the beginning
 of a string (how many chars need to cut until '*')
 */
int compare_start(char *str, char *ptrn)
{
	char	**ptrn_list;
	int		result;

	result = -1;
	if (ptrn[0] == '*')
		return (0);
	ptrn_list = ft_split(ptrn, '*');
	if (! ptrn_list)
		return (-1);
	if (ft_strnstr(str, ptrn_list[0], ft_strlen(ptrn_list[0])))
		result = ft_strlen(ptrn_list[0]);
	ft_free_text(ptrn_list);
	return (result);
}

int cmp_str_from_end(char *str1, char* str2, int len)
{
	int	i;
	int	j;
	
	i = ft_strlen(str1) - 1;	
	j = ft_strlen(str2) - 1;
	if (len > i + 1 || len > j + 1 || len < 1)
		return (0);
	if (i == -1 && i == j)
		return (1);
	while (len > 0)
	{
		if (str1[i--] != str2[j--])
			return (0);
		len--;
	}
	return (1);
}

int compare_end(char *str, char *ptrn)
{
	char	**ptrn_list;
	char	**ptrn_tmp;
	int		result;
	int		ptrn_len;


	result = -1;
	ptrn_len = ft_strlen(ptrn);
	if (ptrn[ptrn_len - 1] == '*')
		return (0);
	ptrn_list = ft_split(ptrn, '*');
	if (! ptrn_list)
		return (-1);
	ptrn_tmp = ptrn_list;
	while (*(ptrn_tmp + 1) != NULL)
		ptrn_tmp++;
	if (cmp_str_from_end(str, *ptrn_tmp, ft_strlen(*ptrn_tmp)))
		result = ft_strlen(*ptrn_tmp);
	ft_free_text(ptrn_list);
	return (result);
}


char *str_copy(char *str, int cut_start, int cut_end)
{
	int		str_len;
	int		result_str_len;
	char	*result;
	int		i;

	str_len = ft_strlen(str);
	if (cut_start + cut_end > str_len)
		return (NULL);
	result_str_len = str_len - cut_start - cut_end;
	result = malloc(result_str_len + 1);
	if (! result)
		return (NULL);
	i = 0;
	while (i < result_str_len)
	{
		result[i] = str[i + cut_start];
		i++;
	}
	result[i] = 0;
	return (result);
}

int find_last_char(char *str, char c)
{
	int	result;
	int	i;

	i = 0;
	result = -1;
	while (str[i])
	{
		if (str[i] == c)
			result = i;
		i++;
	}
	return (result);
}

int find_first_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}



int total_compare(char *str, char *ptrn)
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
		if (is_matches_pattern(pattern, *text))
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
