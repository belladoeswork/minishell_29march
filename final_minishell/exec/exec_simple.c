/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:15:54 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/30 21:34:06 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

int	ft_exec_builtin(char **args, t_minishell *minishell)
{
	int	i;

	i = 0;
	printf("exec_builtin: Executing command - %s\n", args[0]);
	if (!ft_strcmp(args[0], "echo"))
		return (ft_echo(args + 1));
	if (!ft_strcmp(args[0], "cd"))
		return (ft_cd(args + 1));
	if (!ft_strcmp(args[0], "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(args[0], "export"))
		return (ft_export(args, &minishell, i));
	if (!ft_strcmp(args[0], "unset"))
		return (ft_unset(args, &minishell));
	if (!ft_strcmp(args[0], "exit"))
	{
		ft_exit(args, minishell);
		return (0);
	}
	return (GENERAL);
}

// int	ft_exec_builtin_cmd(t_node *node, bool piped, t_minishell *minishell)
// {
// 	int	tmp_status;
// 	int	original_stdin;
// 	int	original_stdout;

// 	original_stdin = dup(STDIN_FILENO);
// 	original_stdout = dup(STDOUT_FILENO);
// 	tmp_status = ft_check_redir(node);
// 	if (tmp_status != SUCCESS)
// 	{
// 		ft_reset_stds(original_stdin, original_stdout, piped);
// 		printf("exec_simple_cmd: Redirection check failed\n");
// 		return (GENERAL);
// 	}
// 	if (ft_strcmp(node->split_args[0], "env") == 0)
// 		tmp_status = ft_env(minishell->environ);
// 	else
// 		tmp_status = ft_exec_builtin(node->split_args, minishell);
// 	ft_reset_stds(original_stdin, original_stdout, piped);
// 	return (tmp_status);
// }

int	ft_exec_builtin_cmd(t_node *node, bool piped, t_minishell *minishell)
{
	int	tmp_status;
	int	original_stdin;
	int	original_stdout;

	original_stdin = dup(STDIN_FILENO);
	original_stdout = dup(STDOUT_FILENO);
	tmp_status = ft_check_redir(node);
	if (tmp_status != SUCCESS)
	{
		ft_reset_stds(original_stdin, original_stdout, piped);
		printf("exec_simple_cmd: Redirection check failed\n");
		g_global.error_num = GENERAL;
		return (g_global.error_num);
	}
	if (ft_strcmp(node->split_args[0], "env") == 0)
		tmp_status = ft_env(minishell->environ);
	else
		tmp_status = ft_exec_builtin(node->split_args, minishell);
	ft_reset_stds(original_stdin, original_stdout, piped);
	return (tmp_status);
}

// int	ft_exec_non_builtin_cmd(t_node *node, bool piped)
// {
// 	int	tmp_status;
// 	int	original_stdin;
// 	int	original_stdout;

// 	original_stdin = dup(STDIN_FILENO);
// 	original_stdout = dup(STDOUT_FILENO);
// 	tmp_status = ft_check_redir(node);
// 	if (tmp_status != SUCCESS)
// 	{
// 		ft_reset_stds(original_stdin, original_stdout, piped);
// 		printf("exec_simple_cmd: Redirection check failed\n");
// 		return (GENERAL);
// 	}
// 	tmp_status = ft_exec_child(node->split_args);
// 	ft_reset_stds(original_stdin, original_stdout, piped);
// 	return (tmp_status);
// }

int	ft_exec_non_builtin_cmd(t_node *node, bool piped)
{
	int	tmp_status;
	int	original_stdin;
	int	original_stdout;

	original_stdin = dup(STDIN_FILENO);
	original_stdout = dup(STDOUT_FILENO);
	tmp_status = ft_check_redir(node);
	if (tmp_status != SUCCESS)
	{
		ft_reset_stds(original_stdin, original_stdout, piped);
		printf("exec_simple_cmd: Redirection check failed\n");
		g_global.error_num = GENERAL;
		return (GENERAL);
	}
	tmp_status = ft_exec_child(node->split_args);
	if (tmp_status == -1) 
	{
		g_global.error_num = NOT_FOUND;
	}
	else
	{
		g_global.error_num = SUCCESS;
	}
	ft_reset_stds(original_stdin, original_stdout, piped);
	return (g_global.error_num);
}

int	ft_exec_simple_cmd(t_node *node, bool piped, t_minishell *minishell)
{
	int	tmp_status;

	if (node->split_args && node->split_args[0])
	{
		printf("exec_simple_cmd: Command - %s\n", node->split_args[0]);
		if (ft_is_builtin(node->split_args[0]))
		{
			printf("exec_simple_cmd: Detected builtin command\n");
			tmp_status = ft_exec_builtin_cmd(node, piped, minishell);
		}
		else
		{
			printf("exec_simple_cmd: Not a builtin command\n");
			tmp_status = ft_exec_non_builtin_cmd(node, piped);
		}
		return (tmp_status);
	}
	else
	{
		printf("exec_simple_cmd: No command provided\n");
		return (GENERAL);
	}
}
