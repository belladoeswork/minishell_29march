#include "lumumbash.h"

bool	ft_current_token_is_op(t_minishell *minishell)
{
	t_token_type	type;

	if (!minishell->current_token)
		return (false);
	type = minishell->current_token->type;
	if (type == TOKEN_PIPE)
		return (true);
	return (false);
}

void	ft_get_next_token(t_minishell *minishell)
{
	minishell->current_token = minishell->current_token->next;
}

bool	ft_is_redir(t_token_type type)
{
	if (type == TOKEN_INPUT_REDIRECTION || type == TOKEN_OUTPUT_REDIRECTION
		|| type == TOKEN_HEREDOC || type == TOKEN_APPEND_OUTPUT_REDIRECTION)
		return (true);
	return (false);
}

bool	ft_join_args(char **args, t_minishell *minishell)
{
	char	*to_free;

	if (minishell->parse_error.type)
		return (false);
	if (!*args)
		*args = ft_strdup("");
	if (!*args)
		return (false);
	while (minishell->current_token
		&& minishell->current_token->type == TOKEN_WORD)
	{
		to_free = *args;
		*args = ft_strjoin_with(*args, minishell->current_token->value, ' ');
		if (!*args)
		{
			free(to_free);
			return (false);
		}
		free(to_free);
		ft_get_next_token(minishell);
	}
	return (true);
}

bool	ft_get_redir_list(t_redir_node **redir_list, t_minishell *minishell)
{
	t_token_type	redir_type;
	t_redir_node	*tmp_redir_node;

	if (minishell->parse_error.type)
	{
		return (false);
	}
	while (minishell->current_token
		&& ft_is_redir(minishell->current_token->type))
	{
		redir_type = minishell->current_token->type;
		ft_get_next_token(minishell);
		if (!minishell->current_token)
		{
			return (ft_set_parse_error(SYNTAX_ERROR), false);
		}
		if (minishell->current_token->type != TOKEN_WORD)
		{
			return (ft_set_parse_error(SYNTAX_ERROR), false);
		}
		tmp_redir_node = ft_new_redir_node(redir_type,
				minishell->current_token->value);
		if (!tmp_redir_node)
		{
			ft_clear_redir_list(redir_list);
			ft_set_parse_error(MALLOC_ERROR);
			return (false);
		}
		ft_append_redir_node(redir_list, tmp_redir_node);
		ft_get_next_token(minishell);
	}
	return (true);
}
