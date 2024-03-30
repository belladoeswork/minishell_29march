/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:14:04 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/30 22:14:05 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

t_node	*ft_parse(t_minishell *minishell)
{
	t_node	*ast;

	if (minishell->tokens != NULL)
		minishell->current_token = minishell->tokens;
	ast = ft_expression(minishell);
	if (minishell->current_token)
	{
		ft_set_parse_error(SYNTAX_ERROR);
		return (ast);
	}
	return (ast);
}
