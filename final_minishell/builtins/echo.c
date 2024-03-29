/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:26:12 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/26 16:54:06 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

void	ft_handle_arguments(char **args, int start_index)
{
	char	*arg;
	size_t	len;
	int		i;

	i = start_index;
	while (args[i])
	{
		arg = args[i];
		len = ft_strlen(arg);
		if ((arg[0] == '"' || arg[0] == '\'') && arg[0] == arg[len - 1])
		{
			arg[len - 1] = '\0';
			arg++;
		}
		ft_putstr_fd(arg, 1);
		if (args[i + 1])
		{
			ft_putstr_fd(" ", 1);
		}
		i++;
	}
}

int	ft_echo(char **args)
{
	int	start_index;

	start_index = ft_handle_flags(args);
	ft_handle_arguments(args, start_index);
	if (start_index == 0)
	{
		ft_putstr_fd("\n", 1);
	}
	return (0);
}
