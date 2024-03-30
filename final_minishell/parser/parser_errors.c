/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:12:56 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/30 22:12:57 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

void	ft_set_parse_error(t_parse_error_type type)
{
	t_minishell	*minishell;

	minishell = NULL;
	if (minishell)
		minishell->parse_error.type = type;
}

char	*ft_get_token_string(t_token_type token_type)
{
	TokenTypeStrings	types;

	types.TOKEN_WORD = "TOKEN_WORD";
	types.TOKEN_PIPE = "<";
	types.TOKEN_INPUT_REDIRECTION = ">";
	types.TOKEN_APPEND_OUTPUT_REDIRECTION = ">>";
	types.TOKEN_HEREDOC = "<<";
	types.TOKEN_NL = "newline";
	if (token_type == TOKEN_WORD)
		return (types.TOKEN_WORD);
	else if (token_type == TOKEN_PIPE)
		return (types.TOKEN_PIPE);
	else if (token_type == TOKEN_INPUT_REDIRECTION)
		return (types.TOKEN_INPUT_REDIRECTION);
	else if (token_type == TOKEN_OUTPUT_REDIRECTION)
		return (types.TOKEN_OUTPUT_REDIRECTION);
	else if (token_type == TOKEN_APPEND_OUTPUT_REDIRECTION)
		return (types.TOKEN_APPEND_OUTPUT_REDIRECTION);
	else if (token_type == TOKEN_HEREDOC)
		return (types.TOKEN_HEREDOC);
	else if (token_type == TOKEN_NL)
		return (types.TOKEN_NL);
	return (NULL);
}

void	ft_handle_parse_error(t_minishell *minishell)
{
	t_token_type	token_type;
	char			*type_str;

	if (minishell == NULL || minishell->parse_error.type == 0)
		return ;
	if (minishell->parse_error.type == SYNTAX_ERROR)
	{
		if (minishell->current_token == NULL)
			token_type = TOKEN_NL;
		else
			token_type = minishell->current_token->type;
		type_str = ft_get_token_string(token_type);
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		ft_putstr_fd(type_str, 2);
		ft_putstr_fd("'\n", 2);
		minishell->exit_s = 258;
	}
	ft_clear_ast(&(minishell->ast), minishell);
	ft_bzero(&(minishell->parse_error), sizeof(t_parse_error));
}

void	ft_print_syntax_error(t_minishell *minishell, t_token_type token_type)
{
	char	*type;

	if (token_type == TOKEN_WORD)
		type = "TOKEN_WORD";
	else if (token_type == TOKEN_INPUT_REDIRECTION)
		type = "<";
	else if (token_type == TOKEN_OUTPUT_REDIRECTION)
		type = ">";
	else if (token_type == TOKEN_HEREDOC)
		type = "<<";
	else if (token_type == TOKEN_APPEND_OUTPUT_REDIRECTION)
		type = ">>";
	else if (token_type == TOKEN_PIPE)
		type = "|";
	else
		type = "\n";
	ft_putstr_fd("lumumbash: syntax error near unexpected token `", 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd("'\n", 2);
	minishell->exit_s = 258;
}

t_token_type	ft_determine_token_type(t_minishell *minishell)
{
	t_token_type	token_type;

	if (minishell->current_token == NULL)
		token_type = TOKEN_NL;
	else
		token_type = minishell->current_token->type;
	return (token_type);
}

void	ft_handle_error(t_minishell *minishell)
{
	if (minishell->parse_error.type == MALLOC_ERROR)
	{
		printf("Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	else if (minishell->parse_error.type == SYNTAX_ERROR)
		printf("Error: Syntax error\n");
	else if (minishell->parse_error.type != NO_ERROR)
	{
		printf("Error: Unknown error occurred\n");
		exit(EXIT_FAILURE);
	}
}
