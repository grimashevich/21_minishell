/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:13:33 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:18:33 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

# ifndef FT_CTYPE_H
#  define FT_CTYPE_H

int		ft_digittoint(int character);
int		ft_isalnum(int character);
int		ft_isalpha(int character);
int		ft_isblank(int character);
int		ft_iscntrl(int character);
int		ft_isdigit(int character);
int		ft_isgraph(int character);
int		ft_islower(int character);
int		ft_isprint(int character);
int		ft_ispunct(int character);
int		ft_isspace(int character);
int		ft_isupper(int character);
int		ft_isxdigit(int character);
int		ft_toascii(int character);
int		ft_toupper(int character);
int		ft_tolower(int character);

# endif // FT_CTYPE_H

# ifndef FT_LIST_H
#  define FT_LIST_H

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

void	ft_list_add_back(t_list **list, t_list *new);
void	ft_list_add_front(t_list **list, t_list *new);
size_t	ft_list_count(t_list *list);
void	ft_list_iter(t_list *list, void (*fun)(void *));
t_list	*ft_list_last(t_list *list);
t_list	*ft_list_map(t_list *list, void *(*fun)(void *), void (*del)(void *));
t_list	*ft_list_new(void *data);
t_list	*ft_list_prev(t_list *list, t_list *current);
int		ft_list_print(t_list *list, int fd);
void	ft_list_remove_all(t_list **list, void (*del)(void *));
int		ft_list_remove_current(t_list **list, t_list *current, void (*del)(void *));
void	ft_list_remove(t_list *list, void (*del)(void *));
char	**ft_list_to_strings(t_list *list);
t_list	*ft_strings_to_list(char **strings);

# endif // FT_LIST_H

# ifndef FT_MEMORY_H
#  define FT_MEMORY_H

void	*ft_calloc(size_t count, size_t size);
void	*ft_memccpy(const void *from, void *to, int character, size_t length);
void	*ft_memchr(void *pointer, int character, size_t length);
int		ft_memcmp(const void *one, const void *two, size_t length);
void	*ft_memcpy(const void *from, void *to, size_t length);
void	*ft_memmove(const void *from, void *to, size_t length);
void	*ft_memset(void *pointer, int character, size_t length);

# endif // FT_MEMORY_H

# ifndef FT_STRING_H
#  define FT_STRING_H

int		ft_atoi(char *string);
long	ft_atol(char *string);
char	*ft_itoa(int num);
int		ft_putchar_fd(char character, int fd);
int		ft_putendl_fd(char *string, int fd);
int		ft_putnum_fd(int num, int fd);
int		ft_putstr_fd(char *string, int fd);
char	**ft_split(char *string, int splitter);
char	*ft_strchr(char *string, char character);
int		ft_strcmp(char *one, char *two);
void	ft_strcpy(char *from, char *in);
char	*ft_strdup(char *string);
int		ft_strend(char *string, char *ending);
void	ft_striteri(char *string, void (*func)(unsigned int, char *));
char	*ft_strjoin(char *one, char *two);
size_t	ft_strlcat(char *from, char *in, size_t lenght);
size_t	ft_strlcpy(char *from, char *in, size_t length);
size_t	ft_strlen(char *string);
char	*ft_strmapi(char *string, char (*func)(unsigned int, char));
int		ft_strncmp(char *one, char *two, size_t length);
char	*ft_strnstr(char *haystack, char *needle, size_t lenght);
char	*ft_strrchr(char *string, int character);
char	*ft_strstr(char *haystack, char *needle);
char	*ft_strtrim(char *string, char *set);
char	*ft_substr(char *string, size_t start, size_t length);

# endif // FT_STRING_H

# ifndef FT_STRINGS_H
#  define FT_STRINGS_H

char	**ft_string_to_strings(char *string, char *splitter);
void	ft_strings_append(char ***strings, char *string);
size_t	ft_strings_count(char **strings);
char	**ft_strings_dup(char **strings);
int		ft_strings_get_index(char **strings, char *part);
char	*ft_strings_get_string(char **strings, char *part);
void	ft_strings_insert(char ***strings, char *string, int index);
char	**ft_strings_map(char **strings, char *(*fun)(char *));
int		ft_strings_print(char **strings);
void	ft_strings_remove_all(char ***strings);
void	ft_strings_remove_by_part(char ***strings, char *part);
void	ft_strings_remove_first(char ***strings);
void	ft_strings_remove_last(char ***strings);
void	ft_strings_remove(char ***strings, int index);
int		ft_strings_replace_by_part(char **strings, char *string, char *part);
int		ft_strings_replace(char **strings, char *string, int index);
char	*ft_strings_to_string(char **strings, char *splitter);

# endif // FT_STRINGS_H

#endif // LIBFT_H
