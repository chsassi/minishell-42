/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 08:50:03 by brulutaj          #+#    #+#             */
/*   Updated: 2024/07/16 10:10:38 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(void)
{
	char	*input;
	t_all	*token;

	while (1)
	{
		input = readline("Minishell~> ");
		if (!input)
			break ;
		printf("Input: %s\n", input);
		add_history(input);
		token = assign_tokens(input);
		free(input);
	}
	return (0);
}
