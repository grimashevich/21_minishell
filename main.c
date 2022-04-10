/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:45:25 by EClown            #+#    #+#             */
/*   Updated: 2022/04/11 01:25:55 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <time.h>


int	str_wildcard_compare(char *str, char *ptrn);

void print_text(char **text)
{
	while (*text)
	{
		printf("%s\n", *text);
		text++;
	}
	
}

int	main(int argc, char **argv, char **envp)
{
	(void) argv;
	(void) argc;
	(void) envp;

	
	char	*cwd;
	char	**files;
	
	cwd = malloc(MAX_PATH_LEN);
	getcwd(cwd, MAX_PATH_LEN);
	
	files = ls_cwd(cwd);

	printf("%s\n", files[0]);


/* 

	// TEST CASE FOR 	char *expand_wildcard_cwd(char *wildcard)

	char **text = malloc(sizeof(char **) * 3);
	int i = 0;


	char *files = expand_wildcard_cwd("*");
	printf("%s\n", files);
	free(files);
*/

/* 
	// TEST CASE FOR 	char **apply_wildcard(char *pattern, char** text)

	char **text = malloc(sizeof(char **) * 3);
	int i = 0;

	text[i++] = ft_strdup("str one");
	text[i++] = ft_strdup("str two");
	text[i++] = NULL;
	
	char** text2 = apply_wildcard("*", text);
	ft_free_text(text);
	print_text(text2);
	ft_free_text(text2);
*/
	
	return (0);
}
 