#include "lumumbash.h"

static t_node	*ft_get_simple_cmd(t_minishell *minishell)
{
    t_node	*node;
    int i = 0;

    if (minishell->parse_error.type)
        return (NULL);
    node = ft_new_node(NODE_CMD);
    if (!node)
    {
        ft_set_parse_error(MALLOC_ERROR);
        return (NULL);
    }

	node->split_args = malloc(MAX_NUM_ARGS * sizeof(char *));
    if (!node->split_args)
    {
        ft_set_parse_error(MALLOC_ERROR);
        free(node);
        return (NULL);
    }

    while (minishell->current_token
        && (minishell->current_token->type == TOKEN_WORD
            || ft_is_redir(minishell->current_token->type)))
    {
        if (minishell->current_token->type == TOKEN_WORD)
        {
            node->split_args[i] = minishell->current_token->value;
            i++;
        }
        else if (ft_is_redir(minishell->current_token->type))
        {
            if (!ft_get_redir_list(&(node->redir_list), minishell))
            {
				free(node->split_args); // ADDED TODAY
                free(node->args);
                free(node);
                return (NULL);
            }
        }
        minishell->current_token = minishell->current_token->next;
    }
    node->split_args[i] = NULL; 
    return (node);
}

t_node	*ft_term(t_minishell *minishell)
{
	// t_node	*node;
	if (minishell->parse_error.type)
		return (NULL);
	if (ft_current_token_is_op(minishell))
	{
		ft_set_parse_error(SYNTAX_ERROR);
		return (NULL);
	}
	else
	{
		return (ft_get_simple_cmd(minishell));
	}
}

t_node	*ft_combine(t_token_type op, t_node *left, t_node *right,
		t_minishell *minishell)
{
	t_node	*node;

	if (minishell->parse_error.type)
		return (NULL);
	node = ft_new_node(ft_get_node_type(op));
	if (!node)
		return (ft_set_parse_error(MALLOC_ERROR), NULL);
	node->left = left;
	node->right = right;
	return (node);
}

t_node	*ft_expression(t_minishell *minishell)
{
	t_node			*left;
	t_node			*right;
	t_token_type	op;

	if (minishell->parse_error.type || !minishell->current_token)
		return (NULL);
	left = ft_term(minishell);
	if (!left)
		return (NULL);
	while (ft_current_token_is_op(minishell))
	{
		op = minishell->current_token->type;
		ft_get_next_token(minishell);
		if (!minishell->current_token)
			return (ft_set_parse_error(SYNTAX_ERROR), left);
		right = ft_expression(minishell);
		if (!right)
			return (left);
		left = ft_combine(op, left, right, minishell);
		if (!left)
			return (ft_clear_ast(&left, minishell), ft_clear_ast(&right,
					minishell), NULL);
	}
	return (left);
}
