/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 08:50:03 by brulutaj          #+#    #+#             */
/*   Updated: 2024/09/26 17:22:30 by brulutaj         ###   ########.fr       */
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
			free_env_list(ptr);
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
			if (!args[1])
				cd_home(ptr);
			else
				bin_cd(ptr, args[1]);
		}
		else if (!ft_strcmp(args[0], "pwd"))
			bin_pwd();
		else if (!ft_strcmp(args[0], "<<"))
			handle_heredoc(args[1]);
		else if (!ft_strcmp(args[0], "export"))
			bin_export(&ptr, args);
		expansion(args[0], ptr);
		i = 0;
		while(args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
	return (0);
}
