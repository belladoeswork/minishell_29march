/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:26:04 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/25 20:26:05 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

int	ft_cd(char **args)
{
	char	*home;

	if (args[0] == NULL)
	{
		home = getenv("HOME");
		if (home == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return (1);
		}
		if (chdir(home) != 0)
		{
			perror("cd");
			return (1);
		}
	}
	else
	{
		if (chdir(args[0]) != 0)
		{
			perror("cd");
			return (1);
		}
	}
	return (0);
}
