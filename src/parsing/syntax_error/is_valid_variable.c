
#include "minishell.h"

bool	is_valid_var(char *var)
{
	int		i;
	bool	is_valid;

	i = -1;
	is_valid = true;
	while (var && var[++i])
	{
		if (i == 0 && (!ft_isalpha(var[i]) || var[i] == '_'))
			is_valid = false;
		else if (!ft_isalnum(var[i]) && var[i] != '_')
			is_valid = false;
		if (!is_valid)
			break ;
	}
	if (!is_valid)
	{
		ft_putstr_fd("unset: ", 2);
		ft_putstr_fd(var, 2);
		ft_putstr_fd(": not a valid identifier\n", 2);
	}
	return (is_valid);
}