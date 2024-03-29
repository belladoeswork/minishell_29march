/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:11:24 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/26 17:11:45 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

void	ft_clear_redir_list(t_redir_node **list)
{
	t_redir_node	*current_node;
	t_redir_node	*next;

	current_node = *list;
	if (!current_node)
		return ;
	while (current_node)
	{
		free(current_node->value);
		next = current_node->next;
		free(current_node);
		current_node = next;
	}
	*list = NULL;
}

void	ft_clear_cmd_node(t_node *node)
{
	if (!node)
		return ;
	ft_clear_redir_list(&(node->redir_list));
	if (node->split_args)
	{
		free(node->split_args);
	}
	ft_free_char2(node->expanded_args);
}

void	ft_recursive_clear_ast(t_node *node)
{
	if (!node)
		return ;
	if (node->type == NODE_CMD)
		ft_clear_cmd_node(node);
	else
	{
		if (node->left)
			ft_recursive_clear_ast(node->left);
		if (node->right)
			ft_recursive_clear_ast(node->right);
	}
	free(node);
}

void	ft_clear_ast(t_node **ast, t_minishell *minishell)
{
	t_token	**tokens;

	tokens = &(minishell->tokens);
	ft_recursive_clear_ast(*ast);
	*ast = NULL;
	if (tokens)
		ft_clear_token_list(&(minishell->tokens));
}
