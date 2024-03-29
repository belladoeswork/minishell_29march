/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:26:35 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/26 16:54:46 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

int	ft_count_colons(char *path)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (path[i] != '\0')
	{
		if (path[i] == ':')
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	**ft_split_path(char *path)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	j = 0;
	result = malloc((ft_count_colons(path) + 1) * sizeof(char *));
	if (result == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	result[j] = path;
	while (path[i] != '\0')
	{
		if (path[i] == ':')
		{
			path[i] = '\0';
			result[++j] = &path[i + 1];
		}
		i++;
	}
	result[j + 1] = NULL;
	return (result);
}

char	*ft_find_command_path(const char *command)
{
	char	**directories;
	int		i;
	char	*path;
	char	*full_path;

	i = 0;
	path = getenv("PATH");
	directories = ft_split_path(path);
	while (directories[i] != NULL)
	{
		full_path = malloc(ft_strlen(directories[i]) + ft_strlen(command) + 2);
		if (full_path == NULL)
			exit(EXIT_FAILURE);
		ft_strcpy(full_path, directories[i]);
		ft_strcat(ft_strcat(full_path, "/"), command);
		if (access(full_path, X_OK) == 0)
		{
			free(directories);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free(directories);
	return (NULL);
}

int	ft_env(char **environ)
{
	int	i;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (1);
}
