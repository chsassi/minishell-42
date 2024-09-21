/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:52:28 by chsassi           #+#    #+#             */
/*   Updated: 2024/07/30 10:19:00 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bin_pwd(void)
{
	char	*directory;

	directory = getcwd(NULL, 0);
	if (directory)
	{
		ft_printf("%s\n", directory);
		g_exit = 0;
	}
	else
	{
		ft_putstr_fd("pwd: error retrieving current directory\n", 2);
		return ;
	}
	free(directory);
}
