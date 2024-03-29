/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasha <tasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:26:04 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/30 01:12:59 by tasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

char	*ft_get_path(char **args)
{
	char	*path;

	if (args[0] == NULL)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return (NULL);
		}
	}
	else if (strcmp(args[0], "-") == 0)
	{
		path = getenv("OLDPWD");
		if (path == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return (NULL);
		}
	}
	else
		path = args[0];
	return (path);
}

int	ft_cd(char **args)
{
	char	*path;

	path = ft_get_path(args);
	if (path == NULL)
		return (1);
	if (chdir(path) != 0)
	{
		perror("cd");
		return (1);
	}
	return (0);
}
