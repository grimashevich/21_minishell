/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:45:25 by EClown            #+#    #+#             */
/*   Updated: 2022/04/08 21:19:27 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <time.h>

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


/* 	
	char	*text[10];
	int i = 0;
	text[i++] = "one two trhee";
 	text[i++] = "gu s";
 	text[i++] = "bus";
	text[i++] = "aliquam,#s";
	text[i++] = "aetus nisl";
	text[i++] = "varius,";
	text[i] = NULL;
 */
	
/* 	char	*answer;
	char	**filtered;
	i = 0;
	char **test = ft_split("one two three", ' ');
	while (test[i])
		printf("%s\n", test[i++]);
	ft_free_text(test);
	test = NULL; */



	char	*ptrn = 	"ft*str*.c";
	char	*haystack = "ft_substr_cut.c";
	
	char *tmp = str_copy(haystack, 2, 2);
	printf("\n%s\n", tmp);
	return(0);

	
	int nn = compare_end(haystack, ptrn);
	if (nn != -1)
		printf("\nTRUE\nn=%d\n", nn);
	else
		printf("\nFALSE\n\n");
	return (0);
	
	
	//filtered = apply_wildcard("*", text);
	
/* 	while (1)
	{
		printf("\nORIGINAL:\n- - - - -\n");
		print_text(text);
		answer = readline("\nEnter wildcard > ");
		add_history(answer);
		filtered = apply_wildcard(answer, text);
		printf("\nFILTERED:\n- - - - -\n");
		print_text(filtered);
		printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
		free(filtered);
		free(answer);
		getchar();
	} */
	
	
	
	return (0);
}
 