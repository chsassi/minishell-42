/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 08:50:03 by brulutaj          #+#    #+#             */
/*   Updated: 2024/08/19 09:09:51 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*input;
	//t_all	*token;
	int		n;

	while (1)
	{
		input = readline("Minishell~> ");
		if (!input)
			break ;
		n = count_number_of_tokens(input);
		printf("Token number: %d\n", n);
		add_history(input);
	}
	return (0);
}
