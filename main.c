/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:45:25 by EClown            #+#    #+#             */
/*   Updated: 2022/04/11 23:32:01 by EClown           ###   ########.fr       */
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


	// TEST CASE FOR 	char *expand_wildcard_cwd(char *wildcard)

/* 	char * answer = malloc(256);
	while (answer)
	{
	
		answer = readline("Enter wildcard: ");
		add_history(answer);
		char *files = expand_wildcard_cwd(answer);
		free(answer);
		printf("\n%s\n", files);
		free(files);
	} */

	char * answer = malloc(256);
	while (answer)
	{
	
		answer = readline("Enter command with wildcard: ");
		add_history(answer);
		char *files = expand_wildcard_in_str(answer);
		free(answer);
		printf("---\n=>%s\n", files);
		free(files);
	}


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
 