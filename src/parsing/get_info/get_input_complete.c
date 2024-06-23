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

t_all	get_final_input(char *line, t_all all_info)
{
	int	*merge_arr;

	merge_arr = ft_calloc(dll_input_size(all_info.cmd_line), sizeof(int));
	line = get_merged_line(all_info.cmd_line, merge_arr);
	if (!line)
		return ((t_all){0});
	set_clear_all(&all_info);
	all_info = get_all_info(all_info, line, NULL);
	if (!all_info.cmd_line)
		return ((t_all){0});
	all_info = handle_trim_quotes(all_info);
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
	if (check_if_merge_flags_on(all_info.cmd_line))
		all_info = get_final_input(line, all_info);
	all_info.cmd_line = get_args_mtx(all_info.cmd_line);
	if (!all_info.cmd_line)
		return ((t_all){0});
	return (all_info);
}
