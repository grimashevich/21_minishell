/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:10 by EClown            #+#    #+#             */
/*   Updated: 2022/04/06 20:34:16 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define TMP_FILE_NAME ".tmp_file"
# define LLI_MIN "9223372036854775808"
# define LLI_MAX "9223372036854775807"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

typedef struct s_str
{
	char			*value;
	struct s_str	*next;
}	t_str;

typedef struct s_dict
{
	char			*key;
	char			*value;
	struct s_str	*next;
}	t_dict;

enum Exec_condition
{
	ANY_CASE,
	ERROR,
	SUCCESS
};

typedef struct s_cmd
{
	int				exec_condition;	// Условие выполнения в зависимости от результат предыдущей команды 'A' (Any case), 'E' (error) 'S' (succes)
	int				in_fd;			// fd для входящего потока
	int				out_fd;			// fd для исходящего потока
	int				isbroken;		// 1 если команда задана не верно, иначе 0		???
	char			*error_text;	// Если is_broken == 1, содержит текст ошибки для вывода	???
	int				isfunc;			// 1 если команда является внутренний функций, иначе 0
	char			**command;		// Массив. 0-й аргумент пусть до файла (имя функции), остальные элементы - аргументы.
	struct s_cmd	*next;			// Указатель на следующий элемент (по горизонтали)
	struct s_cmd	*child;			// Указатель на потомка (NULL по умолчанию). Если  NULL, то это команда.
}	t_cmd;

typedef struct s_list
{
	void			*value;
	struct s_list	*next;
}	t_list;


typedef struct s_cmd_cntr
{
	t_cmd				*first_command;
	int					exec_condition;	// Условие выполнения в зависимости от результат предыдущей команды 'A' (Any case), 'E' (error) 'S' (succes)
	struct s_cmd_cntr	*children;
	t_list				*cntrs;

}	t_cmd_c;

typedef struct s_ms
{
	char	**envp;
	t_cmd	*commands;		// Указатель на начало списка текущих команд
	t_str	*funcs;			// Список валидных функций minishell
	t_dict	*vars;			// Список переменных типа  $var
	int		exit_code;		// Exit code последней исполненной команды
}   t_ms;


t_ms	g_ms;

/* 

РЕКУРСИВНЫЙ ПАРСЕР 1 УР.

s_cmd	*parser_lvl1(char *str, int start, int end)

((cmd1 && (cmd2 param1 param2 | cmd 3) || cmd4 param1) | ((((cmd5) | cmd 6))))
выделить сущности между &&, || и |

 вернет
 cont	-	-	-	cmd5 | cmd6
  |
  |
  |
  |
 cmd1	-	cont	-	cmd4
			  |
			  |
			  |
			  |
			  cmd2	-	cmd3
 
 
 ПАРСЕР 2 УР.
 Парсит сущности, которые создал парсер 1 ур.
 	Фактически рабзирает каждую конкретную команду на саму команду и параметры.
	Преобразовывает переменные в их значения
	Разбирает кавычки

 char	**parser_lvl2(char *str);

 */

#endif  /* MINISHELL_H */
