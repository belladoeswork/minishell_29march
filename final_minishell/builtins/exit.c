/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:27:00 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/26 17:08:06 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

static void	ft_skip_spaces_and_get_sign(char *s, int *i, int *sign)
{
	while (s[*i] && s[*i] == ' ')
		(*i)++;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

static unsigned long long	calculate_result(char *s, int *i)
{
	unsigned long long	result;

	result = 0;
	while (s[*i])
	{
		result = (result * 10) + (s[*i] - '0');
		(*i)++;
	}
	return (result);
}

static int	ft_exittoi(char *s, t_minishell *minishell)
{
	int					i;
	int					sign;
	int					exit_s;
	unsigned long long	result;

	i = 0;
	sign = 1;
	ft_skip_spaces_and_get_sign(s, &i, &sign);
	if (!ft_isnumber(s + i))
	{
		exit_s = ft_error_msg((t_error){ERROR_EXEC_255, NUMERIC_REQUIRED, s});
		ft_clean_shell(minishell);
		exit(exit_s);
	}
	result = calculate_result(s, &i);
	if (result > LONG_MAX)
	{
		exit_s = ft_error_msg((t_error){ERROR_EXEC_255, NUMERIC_REQUIRED, s});
		ft_clean_shell(minishell);
		exit(exit_s);
	}
	return ((result * sign) % 256);
}

void	ft_exit(char **args, t_minishell *minishell)
{
	int	exit_s;

	exit_s = minishell->exit_s;
	if (args[1])
	{
		if (args[2])
		{
			exit_s = ft_error_msg((t_error){GENERAL, TOO_MANY_ARGS, NULL});
		}
		else if (!ft_isnumber(args[1]))
		{
			exit_s = ft_error_msg((t_error){ERROR_EXEC_255, NUMERIC_REQUIRED,
					args[1]});
		}
		else
		{
			exit_s = ft_exittoi(args[1], minishell);
		}
	}
	ft_clean_shell(minishell);
	exit(exit_s);
}
