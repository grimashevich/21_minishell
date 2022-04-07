/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:45:25 by EClown            #+#    #+#             */
/*   Updated: 2022/04/07 21:50:15 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <time.h>

int	main(int argc, char **argv, char **envp)
{
	(void) argv;
	(void) argc;
	(void) envp;

	char	*text[10];
	int i = 0;
	text[i++] = "Lorem ipsum dolor sit amet, consectetur adipiscing ";
	text[i++] = "elit. Nullam ornare lacus ac sem placerat, nec porta";
	text[i++] = "turpis tempus. Proin dictum, neque efficitur vehicula";
	text[i++] = "aliquam, felis nibh tempor quam, sit amet pulvinar ";
	text[i++] = "metus nisl eget justo. In ultrices, est vel molestie ";
	text[i++] = "varius, neque augue posuere odio, eget elementum tellus elit ac.";
	text[i] = NULL;

	
	
	return (0);
}
 