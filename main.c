/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 08:50:03 by brulutaj          #+#    #+#             */
/*   Updated: 2024/09/26 17:22:30 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit = 0;

int	main(int ac, char **av, char **envp)
{
	t_env	*ptr;
	char	*input;

	(void)ac;
	(void)av;
	(void)envp;
	ptr = create_envp(envp);
	input = NULL;
	minishell_loop(input, ptr);
	return (0);
}
