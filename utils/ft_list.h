/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:39 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/10 23:43:15 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stddef.h>
# include "../minishell.h"
/* 
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
 */


void	ft_list_add_back(t_list **list, t_list *new);
void	ft_list_add_front(t_list **list, t_list *new);
void	ft_list_remove_all(t_list **list, void (*del)(void *));
int		ft_list_remove_current(t_list **list, t_list *current, void (*del)(void *));
void	ft_list_remove(t_list *list, void (*del)(void *));
size_t	ft_list_get_count(t_list *list);
t_list	*ft_list_get_last(t_list *list);
t_list	*ft_list_get_prev(t_list *list, t_list *current);
void	ft_list_iter(t_list *list, void (*fun)(void *));
t_list	*ft_list_map(t_list *list, void *(*fun)(void *), void (*del)(void *));
t_list	*ft_list_new(void *content);
char	**ft_list_to_strings(t_list *list);

t_list	*ft_strings_to_list(char **strings);

#endif // FT_LIST_H
