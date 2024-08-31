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

int	g_status_code = 0;

int	main(int ac, char **av, char **envp)
{
	// t_all	ptr;
	char	*input;
	char	**mtx;
	int 	*arr;
	int		i;

	(void)ac;
	(void)av;
	input = NULL;
	// ptr = (t_all){0};
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handle_sigint);
		input = readline("minishell> ");
		if (!input)
		{
			write(1, "exit\n", 5);
			break ;
		}
		// ptr = init(ac, av, envp);
		mtx = create_mtx(input);
		arr = token_arr(mtx);
		exec_cmd(input, mtx, envp); //ignorare spazi nella history
		i = 0;
		if (mtx)
		{
			write_mtx(mtx);
			while (mtx[i])
			{
				printf("[%i] %s\n", arr[i], mtx[i]);
				i++;
			}
			if (mtx[0])
				add_history(input);
		}
	}
	return (0);
}