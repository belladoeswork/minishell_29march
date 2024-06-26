/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:53:25 by aguede            #+#    #+#             */
/*   Updated: 2024/03/27 00:23:14 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "lumumbash.h"

void	ft_print_double_d(char **str, char *from, int n)
{
	int	i;

	i = 0;
	if (n == -1)
	{
		while (str[i] != NULL)
		{
			printf("from %s : %s\n", from, str[i]);
			i++;
		}
		printf("from %s : %s\n", from, str[i]);
	}
	else
	{
		while (str[i] != NULL)
		{
			printf("nbr %d from %s : %s\n", n, from, str[i]);
			i++;
		}
	}
}

int	ft_count_number_of_words(char ***triple_d_str)
{
	int			i;
	int			j;
	static int	total;

	i = 0;
	total = 0;
	while (triple_d_str[i] != NULL)
	{
		j = 0;
		while (triple_d_str[i][j] != NULL)
		{
			total++;
			j++;
		}
		i++;
	}
	return (total);
}

void	ft_free_everything(t_lists_env envi, char **div_by_quote, char **clean)
{
	ft_free_double_d(div_by_quote);
	ft_free_double_d(clean);
	ft_free_double_d(envi.p1);
	ft_free_double_d(envi.p2);
}
