#include "minishell.h"

t_all	trim_quotes_and_merge(t_all all_info)
{
	all_info.cmd_line = handle_trim_quotes(all_info.cmd_line);
	if (!all_info.cmd_line)
		return ((t_all){0});
	all_info.cmd_line = get_merged_cmd_line(all_info.cmd_line);
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
	all_info = trim_quotes_and_merge(all_info);
	return (all_info);
}