/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 08:50:03 by brulutaj          #+#    #+#             */
/*   Updated: 2024/08/01 12:09:19 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;
	//t_all	*token;
	int		n;

	while (1)
	{
		input = readline("Minishell~> ");
		if (!input)
			break ;
		n = find_number_of_tokens(input);
		printf("Token number: %d\n", n);
		add_history(input);
	}
	return (0);
}
