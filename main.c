/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 08:50:03 by brulutaj          #+#    #+#             */
/*   Updated: 2024/08/31 16:44:32 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_exit = 0;

int main(int ac, char **av, char **envp)
{
	t_env	*ptr = NULL;
	char	*input;
	char	**args;
	int i = 0;

	(void)ac;
	(void)av;
	(void)envp;
	ptr = create_envp(envp);
	input = NULL;
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
		args = ft_split(input, ' ');
		if (!args[0])
			continue ;
		if (!ft_strcmp(args[0], "env"))
			ptr = bin_env(ptr);
		else if (!ft_strcmp(args[0], "unset"))
		{
			if (args[1])
				ptr = bin_unset(&ptr, args[1]);
		}
		else if (!ft_strcmp(args[0], "cd"))
		{
			if (args[1])
				bin_cd(ptr, args[1]);
		}
		else if (!ft_strcmp(args[0], "pwd"))
			bin_pwd();
		expansion(args[0], ptr);
		while (args[i])
		{
			free(args[i]);
			i++;
		}
	}
	return (0);
}
