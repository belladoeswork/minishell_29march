/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:48:14 by aguede            #+#    #+#             */
/*   Updated: 2024/03/28 18:01:44 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

void	ft_free_double_d(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	ft_free_envi(char **part1, char **part2)
{
	ft_free_double_d(part1);
	ft_free_double_d(part2);
}
