/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:11:52 by aguede            #+#    #+#             */
/*   Updated: 2024/03/27 22:21:27 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

// static void	ft_unset_helper(t_minishell *minishell, char *key)
// {
// 	t_env	*current;
// 	t_env	*prev;

// 	printf("inside ft_unset_helper\n");
// 	char **str;
// 	str = calloc(ft_strlen_double_pers(minishell), sizeof(char *));
// 	prev = NULL;
// 	current = minishell->envlst;
// 	while (current)
// 	{
// 		if (!ft_strcmp(key, minishell->environ))
// 		{
// 			if (prev)
// 				prev->next = current->next;
// 			else
// 				minishell->envlst = current->next;
// 			free(current);
// 			return ;
// 		}
// 		prev = current;
// 		current = current->next;
// 	}
// 	// int i;

// 	// i = 0;
// 	// char **str;
// 	// str = calloc(ft_strlen_double_pers(minishell), sizeof(char *));
// 	// while(minishell->environ[i])
// 	// {

// 	// }
// }

static void	ft_unset_helper(t_minishell *minishell, char *key)
{
	int			i;
	int			j;
	char		**str;
	t_lists_env	envi;

	i = 0;
	j = 0;
	str = ft_calloc(ft_strlen_double_pers(minishell->environ), sizeof(char *));
	envi = ft_split_lists_env(minishell->environ);
	while (minishell->environ[j] != NULL)
	{
		if (ft_strcmp(key, envi.p1[j]) == 0)
			j++;
		if (minishell->environ[j] != NULL)
			str[i] = ft_strdup(minishell->environ[j]);
		else
			break ;
		i++;
		j++;
	}
	str[i] = NULL;
	ft_free_double_d(minishell->environ);
	minishell->environ = str;
	ft_free_double_d(envi.p1);
	ft_free_double_d(envi.p2);
}

int	ft_unset(char **args, t_minishell **minishell)
{
	int		i;
	bool	err;

	i = 1;
	if (!args[1])
		return (0);
	err = false;
	while (args[i])
	{
		if (!ft_keycheck(args[i]))
		{
			ft_putstr_fd("lumumbash: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			err = true;
		}
		else
			ft_unset_helper(*minishell, ft_collector(ft_extract_key(args[i]),
					false));
		printf("i is %d inside ft_unset\n", i);
		i++;
	}
	return (err);
}
