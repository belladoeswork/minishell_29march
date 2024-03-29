/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:16:27 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/26 18:55:30 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

int	ft_get_exit_status(int status)
{
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}

static void	child_process_left(t_node *tree, int *pfds, t_minishell *minishell)
{
	ft_safe_close(pfds[0]);
	ft_safe_dup2(pfds[1], STDOUT_FILENO);
	ft_safe_close(pfds[1]);
	ft_exec_node(tree->left, true, minishell);
	exit(EXIT_FAILURE);
}

static void	child_process_right(t_node *tree, int *pfds, t_minishell *minishell)
{
	ft_safe_close(pfds[1]);
	ft_safe_dup2(pfds[0], STDIN_FILENO);
	ft_safe_close(pfds[0]);
	ft_exec_node(tree->right, true, minishell);
	exit(EXIT_FAILURE);
}

static int	ft_exec_pipeline(t_node *tree, t_minishell *minishell)
{
	int	status;
	int	pfds[2];
	int	pid_left;
	int	pid_right;

	pipe(pfds);
	pid_left = fork();
	if (pid_left == 0)
	{
		child_process_left(tree, pfds, minishell);
	}
	pid_right = fork();
	if (pid_right == 0)
	{
		child_process_right(tree, pfds, minishell);
	}
	ft_safe_close(pfds[0]);
	ft_safe_close(pfds[1]);
	waitpid(pid_left, &status, 0);
	waitpid(pid_right, &status, 0);
	return (ft_get_exit_status(status));
}

int	ft_exec_node(t_node *tree, bool piped, t_minishell *minishell)
{
	if (!tree)
		return (1);
	if (tree->type == NODE_PIPE)
		return (ft_exec_pipeline(tree, minishell));
	else
		return (ft_exec_simple_cmd(tree, piped, minishell));
	return (GENERAL);
}
