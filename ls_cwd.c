/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:13:51 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/10 19:15:20 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/ft_list.h"

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

static t_list	*get_list(char *path)
{
	t_list			*list;
	t_list			*new;
	DIR				*dir;
	struct dirent	*dp;

	dir = opendir(path);
	if (dir == NULL)
		return (NULL);
	dp = readdir(dir);
	list = NULL;
	while (dp != NULL)
	{
		new = ft_list_new(dp->d_name);
		if (new == NULL)
		{
			ft_list_remove_all(&list, NULL);
			return (NULL);
		}
		ft_list_add_back(&list, new);
		dp = readdir(dir);
	}
	closedir(dir);
	return (list);
}

char	**ls_cwd(char *path)
{
	char	**strings;
	t_list	*list;

	list = get_list(path);
	if (list == NULL)
		return (NULL);
	strings = ft_list_to_strings(list);
	ft_list_remove_all(&list, NULL);
	if (strings == NULL)
		return (NULL);
	return (strings);
}

void	ft_strings_remove_all(char ***strings);
int		ft_strings_print(char **strings);

int	main(void)
{
	char	**strings;

	strings = ls_cwd("./lol");
	if (strings == NULL)
		return (1);
	ft_strings_print(strings);
	free(strings);
	return (0);
}
