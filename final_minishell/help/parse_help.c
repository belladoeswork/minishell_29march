#include "lumumbash.h"

// t_node	*ft_expression(t_minishell *minishell)
// {
// 	t_node			*left;
// 	t_node			*right;
// 	t_token_type	op;

// 	if (minishell->parse_error.type || !minishell->current_token)
// 		return (NULL);
// 	left = ft_term(minishell);
// 	if (!left)
// 		return (NULL);
// 	while (ft_current_token_is_op(minishell))
// 	{
// 		op = minishell->current_token->type;
// 		ft_get_next_token(minishell);
// 		if (!minishell->current_token)
// 			return (ft_set_parse_error(SYNTAX_ERROR), left);
// 		right = ft_expression(minishell);
// 		if (!right)
// 			return (left);
// 		left = ft_combine(op, left, right, minishell);
// 		if (!left)
// 			return (ft_clear_ast(&left, minishell), ft_clear_ast(&right,
// 					minishell), NULL);
// 	}
// 	return (left);
// }

void	ft_process_tokens(t_minishell *minishell, t_node *node, int *i)
{
	while (minishell->current_token
		&& (minishell->current_token->type == TOKEN_WORD
			|| ft_is_redir(minishell->current_token->type)))
	{
		if (minishell->current_token
			&& minishell->current_token->type == TOKEN_WORD)
		{
			node->split_args[*i] = minishell->current_token->value;
			(*i)++;
		}
		else if (minishell->current_token
			&& ft_is_redir(minishell->current_token->type))
		{
			if (!ft_get_redir_list(&(node->redir_list), minishell, node))
			{
				free(node->split_args);
				free(node);
				return ;
			}
		}
		if (minishell->current_token)
			minishell->current_token = minishell->current_token->next;
	}
}

char	**ft_allocate_split_args(void)
{
	char	**split_args;

	split_args = malloc(MAX_NUM_ARGS * sizeof(char *));
	if (!split_args)
	{
		ft_set_parse_error(MALLOC_ERROR);
		return (NULL);
	}
	return (split_args);
}

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
