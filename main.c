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
	char	*input;
	char	**mtx;

	while (1)
	{
		input = readline("Minishell~> ");
		if (!input)
			break ;
		mtx = create_mtx(input);
		if (mtx)
			write_mtx(mtx);
		//free_mtx(mtx);
		add_history(input);
	}
	return (0);
}
