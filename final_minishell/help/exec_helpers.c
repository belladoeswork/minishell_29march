/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasha <tasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:30:08 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/30 03:03:40 by tasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

// void	ft_reset_stds(bool piped)
// {
// 	if (piped)
// 		return ;
// 	dup2(STDIN_FILENO, 0);
// 	dup2(STDOUT_FILENO, 1);
// }

void	ft_reset_stds(int original_stdin, int original_stdout, bool piped)
{
	if (piped)
		return ;
	dup2(original_stdin, STDIN_FILENO);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdin);
	close(original_stdout);
}

bool	ft_is_builtin(char *arg)
{
	if (!arg)
		return (false);
	printf("is_builtin: Checking command - %s\n", arg);
	if (!ft_strcmp(arg, "echo") || !ft_strcmp(arg, "exit") || !ft_strcmp(arg,
			"pwd") || !ft_strcmp(arg, "export") || !ft_strcmp(arg, "unset")
		|| !ft_strcmp(arg, "env") || !ft_strcmp(arg, "cd"))
	{
		printf("is_builtin: Detected as builtin command\n");
		return (true);
	}
	printf("is_builtin: Not a builtin command\n");
	return (false);
}
