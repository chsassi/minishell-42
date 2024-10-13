/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 08:50:03 by brulutaj          #+#    #+#             */
/*   Updated: 2024/10/12 16:26:33 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit = 0;

int	main(int ac, char **av, char **envp)
{
	t_env	*ptr;

	(void)av;
	if (ac == 1)
	{
		ptr = create_envp(envp);
		minishell_loop(ptr);
		return (0);
	}
	ft_putstr_fd("Error: command line arguments not supported\n", 2);
	return (1);
}
