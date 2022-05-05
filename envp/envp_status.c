/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 04:03:17 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/04 19:47:05 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "envp.h"

void	envp_status(void)
{
	if (g_ms.envp == NULL)
	{
		perror(NULL);
		exit(1);
	}
}