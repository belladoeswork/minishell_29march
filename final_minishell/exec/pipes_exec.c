/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:16:43 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/28 17:53:34 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

void	ft_execute_child_process(char **split_args)
{
	char	*full_path;

	full_path = ft_find_command_path(split_args[0]);
	if (full_path == NULL)
	{
		printf("Command '%s' not found\n", split_args[0]);
		exit(EXIT_FAILURE);
	}
	if (execve(full_path, split_args, NULL) == -1)
	{
		perror("execve");
		free(full_path);
		exit(EXIT_FAILURE);
	}
	free(full_path);
}

int	ft_wait_for_child(pid_t pid)
{
	int	tmp_status;

	waitpid(pid, &tmp_status, WUNTRACED);
	while (!WIFEXITED(tmp_status) && !WIFSIGNALED(tmp_status))
	{
		waitpid(pid, &tmp_status, WUNTRACED);
	}
	return (tmp_status);
}

int	ft_exec_child(char **split_args)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		ft_execute_child_process(split_args);
	}
	else if (pid < 0)
	{
		perror("fork");
		return (-1);
	}
	else
	{
		return (ft_wait_for_child(pid));
	}
	return (1);
}
