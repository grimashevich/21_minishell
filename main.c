/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:14:45 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/02 19:41:48 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd(t_cmd *command)
{
	t_cmd	*temporary;

	if (command == NULL)
	{
		return ;
	}
	else
	{
		while (command != NULL)
		{
			ft_strings_remove_all(&command->command);
			free_cmd(command->child);
			temporary = command;
			command = command->next;
			free(temporary);
		}
	}
}

char	*input_trim(char *input)
{
	char	*line;

	line = ft_strtrim(input,  " ");
	free(input);
	if (line == NULL)
	{
		exit(1);
	}
	return (line);
}

int	check(char **line)
{
	if (ft_strncmp(*line, "echo", 4) == 0)
		printf("%s\n", *line + 5);
	else if (ft_strncmp(*line, "cd", 2) == 0)
		printf("\n");
	else if (ft_strncmp(*line, "pwd", 3) == 0)
		printf("\n");
	else if (ft_strncmp(*line, "export", 6) == 0)
		printf("\n");
	else if (ft_strncmp(*line, "unset", 5) == 0)
		envp_remove(*line);
	else if (ft_strncmp(*line, "env", 3) == 0)
		envp_print();
	else if (ft_strcmp(*line, "exit") == 0)
	{
		printf("exit\n");
		return (1);
	}
	return (0);
}

int	check_command(t_cmd *command)
{
	while (command != NULL)
	{
		if (check(command->command) == 1)
			return (1);
		command = command->next;
	}
	return (0);
}

void	minishell(void)
{
	char	*input;
	char	*line;
	t_cmd	*command;

	while (1)
	{
		input = readline("minishell 😎👉 ");
		command = parserlvl1(input);
		if (check_command(command) == 1)
		{
			free_cmd(command);
			break ;
		}
		free_cmd(command);
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	envp_init(envp);
	envp_remove("PWD");
	envp_print();
	minishell();
	return (0);
}
