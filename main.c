/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 08:50:03 by brulutaj          #+#    #+#             */
/*   Updated: 2024/08/27 11:23:31 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	// t_all	ptr;
	char	*input;
	char	**mtx;
	int 	*arr;
	int		i;

	input = NULL;
	// ptr = (t_all){0};
	while (1)
	{
		// signal(SIGQUIT, handle_sigquit);
		// signal(SIGINT, handle_sigint);
		// signal(SIGTERM, handle_sigterm);
		input = readline("minishell> ");
		if (!input)
			break ;
		// ptr = init(ac, av, envp);
		mtx = create_mtx(input);
		arr = token_arr(mtx);
		i = 0;
		if (mtx)
		{
			//write_mtx(mtx);
			while (mtx[i])
			{
				printf("[%i] %s\n", arr[i], mtx[i]);
				i++;
			}
		}
		add_history(input);
	}
	return (0);
}
