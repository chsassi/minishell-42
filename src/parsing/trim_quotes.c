#include "minishell.h"

char	*trim_quotes(char *content)
{
	char	*new_content;
	char	to_trim;
	int		len;

	len = ft_strlen(content) - 2;
	if (len < 0)
		return (NULL);
	else if (len == 0)
		return (ft_strdup(""));
	to_trim = content[0];
	new_content = ft_strtrim(content, &to_trim);
	return (new_content);
}

t_input	*handle_trim_quotes(t_input *cmd_line)
{
	t_input *tmp;

	tmp = cmd_line;
	while (tmp)
	{
		if (tmp->token == D_QUOTE || tmp->token == S_QUOTE)
			tmp->content = trim_quotes(tmp->content);
		if (!tmp->content)
			return (NULL);
		tmp = tmp->next;
	}
	return (cmd_line);
}
