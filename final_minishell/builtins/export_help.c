/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:44:45 by aguede            #+#    #+#             */
/*   Updated: 2024/03/29 15:44:49 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

void	skip_spaces(char *str, char **out, int last_space)
{
	while (*str)
	{
		if (isspace(*str))
		{
			if (!last_space)
			{
				*(*out)++ = ' ';
				last_space = 1;
			}
			str++;
		}
		else
		{
			*(*out)++ = *str++;
			last_space = 0;
		}
	}
	**out = '\0';
}

char	*ft_no_space(char *str)
{
	size_t	len;
	char	*new_str;
	char	*out;
	int		last_space;

	len = strlen(str);
	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	out = new_str;
	last_space = 0;
	while (*str && isspace(*str))
	{
		str++;
		last_space = 0;
	}
	skip_spaces(str, &out, last_space);
	return (new_str);
}
