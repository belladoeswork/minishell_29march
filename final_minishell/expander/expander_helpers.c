/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:34:54 by aguede            #+#    #+#             */
/*   Updated: 2024/03/27 00:36:17 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

int	ft_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

char	**ft_string_to_double_d(char *str)
{
	char	**str_double;

	str_double = ft_calloc(2, sizeof(char *));
	if (!str_double)
		return (NULL);
	str_double[0] = ft_strdup(str);
	str_double[1] = NULL;
	return (str_double);
}

char	**ft_double_strdup(char **str)
{
	int		i;
	int		n;
	char	**str_dup;

	i = 0;
	n = 0;
	while (str[i] != NULL)
		i++;
	str_dup = ft_calloc(i + 1, sizeof(char *));
	while (str[n] != NULL)
	{
		str_dup[n] = ft_strdup(str[n]);
		n++;
	}
	str_dup[n] = NULL;
	return (str_dup);
}
