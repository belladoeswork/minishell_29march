/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:15:54 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/28 18:14:26 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

int	ft_exec_builtin(char **args, t_minishell *minishell)
{
	int i;

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

int	ft_exec_builtin_cmd(t_node *node, bool piped, t_minishell *minishell)
{
	int	tmp_status;

	tmp_status = ft_check_redir(node);
	if (tmp_status != SUCCESS)
	{
		ft_reset_stds(piped);
		printf("exec_simple_cmd: Redirection check failed\n");
		return (GENERAL);
	}
	if (ft_strcmp(node->split_args[0], "env") == 0)
	{
		tmp_status = ft_env(minishell->environ);
	}
	else
	{
		tmp_status = ft_exec_builtin(node->split_args, minishell);
	}
	ft_reset_stds(piped);
	return (tmp_status);
}

int	ft_exec_non_builtin_cmd(t_node *node, bool piped)
{
	int	tmp_status;

	tmp_status = ft_check_redir(node);
	if (tmp_status != SUCCESS)
	{
		ft_reset_stds(piped);
		printf("exec_simple_cmd: Redirection check failed\n");
		return (GENERAL);
	}
	tmp_status = ft_exec_child(node->split_args);
	return (tmp_status);
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
