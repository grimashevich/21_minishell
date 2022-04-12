/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:14:45 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:19:50 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_update(char *current_working_directory);

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	envp_init(envp);
	pwd_update("lol");
	envp_remove("PWD");
	envp_remove("OLDPWD");
	pwd_update("minecraft");
	envp_print();
}

// int	main(int argc, char **argv)
// {
// 	t_cmd	*command;

// 	if (argc != 2)
// 	{
// 		printf("one parametr please\n");
// 		return (1);
// 	}
// 	else
// 	{
// 		command = parserlvl1(argv[1]);
// 		printf("----------------------------------------\n");
// 		print_tree(command, 2);
// 		return (0);
// 	}
// }
