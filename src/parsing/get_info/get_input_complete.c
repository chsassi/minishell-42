/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_complete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:50 by mgalmari          #+#    #+#             */
/*   Updated: 2024/06/18 14:34:59 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_input	*get_final_cmd_line(t_input *cmd_line)
{
	t_input	*new_cmdline;

	new_cmdline = create_cmdline_with_cmds(cmd_line);
	if (!new_cmdline)
		return (NULL);
	new_cmdline = get_args_mtx(new_cmdline, cmd_line);
	if (!new_cmdline)
		return (NULL);
	return (new_cmdline);
}

t_all	get_final_input(char *line, t_all all_info)
{
	line = get_merged_cmdline(all_info.cmd_line);
	if (!line)
		return ((t_all){0});
	set_clear_all(&all_info);
	all_info = get_all_info(all_info, line, NULL);
	if (!all_info.cmd_line)
		return ((t_all){0});
	all_info.cmd_line = get_final_cmd_line(all_info.cmd_line);
	if (!all_info.cmd_line)
		return ((t_all){0});
	return (all_info);
}

t_all	get_input_complete(t_all all_info, char *line, char **envp)
{
	all_info = get_all_info(all_info, line, envp);
	if (!all_info.cmd_line)
		return ((t_all){0});
	all_info = expand_dollar_sign(all_info);
	if (!all_info.cmd_line)
		return ((t_all){0});
	all_info = handle_trim_quotes(all_info);
	if (!all_info.cmd_line)
		return ((t_all){0});
	all_info = get_final_input(line, all_info);
	return (all_info);
}
