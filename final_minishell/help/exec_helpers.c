/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:30:08 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/26 18:30:13 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

void	ft_reset_stds(bool piped)
{
	if (piped)
		return ;
	dup2(STDIN_FILENO, 0);
	dup2(STDOUT_FILENO, 1);
}

bool	ft_is_builtin(char *arg)
{
	if (!arg)
	{
		return (false);
	}
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
