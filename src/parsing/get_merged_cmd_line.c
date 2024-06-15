#include "minishell.h"

char	*merge_content(t_input *cmd_line, char *new_content)
{
	char	*new_content_prev;
	char	*new_content_next;

	new_content_prev = NULL;
	new_content_next = NULL;
	if (cmd_line->merge == MERGE_PREV || cmd_line->merge == MERGE_BOTH)
	{
		if (cmd_line->prev->merge == MERGE_BOTH || cmd_line->prev->merge == MERGE_NEXT)
			new_content_prev = new_content;
		else
			new_content_prev = ft_strjoin(cmd_line->prev->content, cmd_line->content);
		if (!new_content_prev)
			return (NULL);
	}
	else if (cmd_line->merge == MERGE_NEXT)
		return (ft_strjoin(cmd_line->content, cmd_line->next->content));
	if (cmd_line->merge == MERGE_BOTH)
		return (ft_strjoin(new_content_prev, cmd_line->next->content));
	return (new_content_prev);
}

char	*get_new_content(t_input **cmd_line)
{
	char	*new_content;
	t_input	**tmp;

	tmp = cmd_line;
	new_content = ft_strdup((*tmp)->content);
	if (check_if_operator((*tmp)->token))
		return (ft_strdup((*tmp)->content));
	if ((*tmp)->next && ((*tmp)->next->merge == MERGE_BOTH 
		|| (*tmp)->next->merge == MERGE_PREV))
		(*tmp) = (*tmp)->next;
	while ((*tmp) && (*tmp)->merge)
	{
		new_content = merge_content((*tmp), new_content);
		(*tmp) = (*tmp)->next;
	}
	cmd_line = tmp;
	return (new_content);
}

t_input	*get_merged_cmd_line(t_input *cmd_line)
{
	t_input	**head;
	t_input	*old_head;
	t_input	*new_cmd_line;
	t_input	*new_node;
	char	*new_content;
	int		token;

	new_cmd_line = NULL;
	old_head = cmd_line;
	head = &cmd_line;
	while ((*head))
	{
		new_content = get_new_content(head);
		if (!ft_strncmp(new_content, "", 1))
		{
			(*head) = (*head)->next;
			continue ;
		}
		token = WORDS;
		if ((*head) && check_if_operator((*head)->token))
			token = (*head)->token;
		new_node = dll_input_new(new_content);
		if (!new_node)
			return (dll_input_clear(&new_cmd_line), NULL);
		new_node->token = token;
		dll_input_addback(&new_cmd_line, new_node);
		if (!(*head) || !(*head)->next)
			break ;
		(*head) = (*head)->next;
	}
	dll_input_clear(&old_head);
	return (new_cmd_line);
}
