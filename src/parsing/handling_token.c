#include "minishell.h"

int	check_if_operator(int token)
{
	if (token == PIPE || token == R_INPUT
	|| token == R_OUTPUT || token == D_RED_INPUT
	|| token == D_RED_OUTPUT)
		return (1);
	return (0);
}