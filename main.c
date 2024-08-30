/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 08:50:03 by brulutaj          #+#    #+#             */
/*   Updated: 2024/08/21 17:41:12 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	// t_all	ptr;
	char	*input;
	char	**mtx;

	input = NULL;
	// ptr = (t_all){0};
	while (1)
	{
		signal(SIGQUIT, handle_sigquit);
		signal(SIGINT, handle_sigint);
		signal(SIGTERM, handle_sigterm);
		input = readline("minishell> ");
		if (!input)
		{
			write(1, "exit\n", 5);
			break ;
		}
		// ptr = init(ac, av, envp);
		mtx = create_mtx(input);
		if (mtx)
			write_mtx(mtx);
		//free_mtx(mtx);
		add_history(input);
	}
	return (0);
}
