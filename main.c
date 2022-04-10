/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:45:25 by EClown            #+#    #+#             */
/*   Updated: 2022/04/09 22:55:44 by EClown           ###   ########.fr       */
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


	char	*text[10];
	int i = 0;
	text[i++] = "eee";
 	text[i++] = "one two trhee";
 	text[i++] = "gu s";
 	text[i++] = "bus";
	text[i++] = "aliquam,#s";
	text[i++] = "aetus nisl";
	text[i++] = "varius,";
	text[i] = NULL;


	char	**filtered;
	char *answer;
	while (1)
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
	}
	
	
	return (0);
}
 