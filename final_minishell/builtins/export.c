/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasha <tasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:06:35 by aguede            #+#    #+#             */
/*   Updated: 2024/03/30 01:12:30 by tasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

static int	ft_export_error_msg(char *identifier)
{
	ft_putstr_fd("lumumbash: export: `", 2);
	ft_putstr_fd(identifier, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

// int	ft_strlen_double_pers(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != NULL)
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_create_new_key(char *key)
// {
// 	int		j;
// 	char	*new_key;

// 	j = 0;
// 	new_key = ft_calloc(ft_strlen(key) + 2, sizeof(char));
// 	if (!new_key)
// 		exit(EXIT_FAILURE);
// 	while (key[j] != 0)
// 	{
// 		new_key[j] = key[j];
// 		j++;
// 	}
// 	new_key[j] = '=';
// 	j++;
// 	new_key[j] = 0;
// 	return (new_key);
// }

// char	**duplicate_environ(char **minishellenviron, char *key_update,
// 		char *val)
// {
// 	char	**new_environ;
// 	int		k;

// 	k = 0;
// 	new_environ = ft_calloc(ft_strlen_double_pers(minishellenviron) + 2,
// 			sizeof(char *));
// 	while (minishellenviron[k] != NULL)
// 	{
// 		new_environ[k] = ft_strdup(minishellenviron[k]);
// 		k++;
// 	}
// 	new_environ[k] = ft_strjoin(key_update, val);
// 	k++;
// 	new_environ[k] = NULL;
// 	k = 0;
// 	return (new_environ);
// }

void	ft_modif_env_var(t_lists_env envi, char *key, char *val,
		t_minishell *minishell)
{
	int		i;
	// int		k;
	char	*key_update;
	char	**new_environ;

	i = 0;
	// k = 0;
	key_update = ft_create_new_key(key);
	while (envi.p1[i] != NULL)
	{
		if (ft_strncmp(key, envi.p1[i], ft_strlen(envi.p1[i])) == 0)
			break ;
		i++;
	}
	new_environ = duplicate_environ(minishell->environ, key_update, val);
	ft_free_double_d(minishell->environ);
	minishell->environ = new_environ;
	free(key_update);
}

// void	ft_free_lists_env(t_lists_env envi)
// {
// 	ft_free_double_d(envi.p1);
// 	ft_free_double_d(envi.p2);
// }

char	**populate_str(char **minishellenviron, char *key, char *update,
		t_lists_env list_env)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_calloc(ft_strlen_double_pers(minishellenviron) + 1,
			sizeof(char *));
	if (!str)
		return (NULL);
	while (minishellenviron[i] != NULL)
	{
		if (ft_strncmp(list_env.p1[i], key, ft_strlen(key)) == 0)
		{
			str[i] = ft_strdup(update);
			if (str[i + 1] != NULL)
				i++;
			else
				break ;
		}
		str[i] = ft_strdup(minishellenviron[i]);
		i++;
	}
	i++;
	ft_free_lists_env(list_env);
	return (str[i] = NULL, str);
}

// char	*ft_update(char *key_update, char *val)
// {
// 	char	*p1;
// 	char	*p2;
// 	char	*updated;

// 	p1 = ft_strdup(key_update);
// 	p2 = ft_strdup(val);
// 	updated = ft_strjoin(p1, p2);
// 	free(p1);
// 	free(p2);
// 	return (updated);
// }

// char	**ft_modify_env_var(char **minishellenviron, char *key, char *val)
// {
// 	char		*key_update;
// 	char		**str;
// 	char		*updated;
// 	t_lists_env	list_env;

// 	list_env = ft_split_lists_env(minishellenviron);
// 	key_update = ft_create_new_key(key);
// 	updated = ft_update(key_update, val);
// 	str = populate_str(minishellenviron, key, updated, list_env);
// 	free(key_update);
// 	free(updated);
// 	return (str);
// }
// int	ft_count_double_ft_q(char *val)
// int	ft_q(char *val, char c)
// {
// 	int	n;
// 	int	i;

// 	n = 0;
// 	i = 0;
// 	while (val[i] != 0)
// 	{
// 		if (val[i] == c)
// 			n++;
// 		i++;
// 	}
// 	return (n);
// }

// char	*ft_remove_ft_q(char *val)
// {
// 	int		i;
// 	int		j;
// 	int		n;
// 	char	*str;

// 	i = 0;
// 	n = ft_q(val, '\"') + ft_q(val, '\'');
// 	j = 0;
// 	if (n >= 2 && (ft_q(val, '\"') % 2 == 0) && (ft_q(val, '\'') % 2 == 0))
// 		str = ft_calloc(ft_strlen(val) - n + 1, sizeof(char));
// 	else if (n != 0 && ((ft_q(val, '\"') % 2 != 0) || (ft_q(val, '\'')
// 				% 2 != 0)))
// 		exit(EXIT_FAILURE);
// 	else
// 		return (str = ft_strdup(val));
// 	while (val[i] != '\0')
// 	{
// 		if (val[i] == '\"' || val[i] == '\'')
// 			i++;
// 		str[j] = val[i];
// 		j++;
// 		if (val[i])
// 			i++;
// 	}
// 	return (str[j] = 0, str);
// }
// char	*ft_no_space(char *val)
// {
// 	int		i;
// 	int		n;
// 	char	*no_space;

// 	i = 0;
// 	n = 0;
// 	while (val[i] != '\0')
// 	{
// 		if (ft_isspace(val[i]))
// 			n++;
// 		i++;
// 	}
// 	no_space = ft_calloc(ft_strlen(val) - n + 1, 8);
// 	i = 0;
// 	while (val[i] != '\0')
// 	{
// 		if (!ft_isspace(val[i]))
// 			no_space[i] = val[i];
// 		i++;
// 	}
// 	no_space[i] = '\0';
// 	printf("inside export no_space is :%s\n", no_space);
// 	return (no_space);
// 	// en vrai il faut que je compte le nombre de char not isspace,
// 		//le nombre de fois que je passe de char a isspace,
// 		//le nombre de isspace --> strlen - isspace + nbr of char to isspace()
// 	// maybe start by removing beginning
// 	// remove end
// 	// then count amount of times we switch from char to isspace
// 	// then use the formula to calloc
// 	// then everytime we arrive at a space we while loop until not a space
// 	// then we set 1 space
// 	// then we do -- in the str being copied to get the char
// 	// then loops restart
// }

// char	*ft_no_space(char *str)
// {
// 	char	*end;
// 	char	*out;
// 	int		last_space;

// 	while (*str && isspace(*str))
// 		memmove(str, str + 1, strlen(str));
// 	end = str + strlen(str) - 1;
// 	while (end >= str && isspace(*end))
// 	{
// 		*end-- = '\0';
// 	}
// 	out = str;
// 	last_space = 0;
// 	while (*str)
// 	{
// 		if (isspace(*str))
// 		{
// 			if (!last_space)
// 			{
// 				*out++ = ' ';
// 				last_space = 1;
// 			}
// 		}
// 		else
// 		{
// 			*out++ = *str;
// 			last_space = 0;
// 		}
// 		str++;
// 	}
// 	*out = '\0';
// 	printf("inside export no_space is :%s\n", str);
// 	return (str);
// }

// char *ft_no_space(char *str) {
//     size_t len = strlen(str);  // Get original string length

//
// Allocate memory for modified string with extra space for null terminator
//     char *new_str = malloc(len + 1);
//     if (new_str == NULL) {
//         return (NULL); // Handle allocation failure
//     }

//     char *out = new_str;
//     int last_space = 0;

//
// Process the original string,copying only 
//     for (size_t i = 0; i < len; i++) {
//         if (isspace(str[i])) {
//             if (!last_space) {
//                 *out++ = ' ';
//                 last_space = 1;
//             }
//         } else {
//             *out++ = str[i];
//             last_space = 0;
//         }
//     }

//     *out = '\0';  // Terminate the new string

//     return (new_str);
// }
// void skip_spaces(char *str, char *out, int last_space)
// {
// 	while (*str)
// 	{
// 		if (isspace(*str))
// 		{
// 			if (!last_space)
// 			{
// 				*out++ = ' ';
// 				last_space = 1;
// 			}
// 			str++;
// 		}
// 		else
// 		{
// 			*out++ = *str++;
// 			last_space = 0;
// 		}
// 	}
// 	*out = '\0';
// }
// void	skip_spaces(char *str, char **out, int last_space)
// {
// 	while (*str)
// 	{
// 		if (isspace(*str))
// 		{
// 			if (!last_space)
// 			{
// 				*(*out)++ = ' ';
// 				last_space = 1;
// 			}
// 			str++;
// 		}
// 		else
// 		{
// 			*(*out)++ = *str++;
// 			last_space = 0;
// 		}
// 	}
// 	**out = '\0';
// }

// char	*ft_no_space(char *str)
// {
// 	size_t	len;
// 	char	*new_str;
// 	char	*out;
// 	int		last_space;

// 	len = strlen(str);
// 	new_str = malloc(len + 1);
// 	if (new_str == NULL)
// 		return (NULL);
// 	out = new_str;
// 	last_space = 0;
// 	while (*str && isspace(*str))
// 	{
// 		str++;
// 		last_space = 0;
// 	}
// 	skip_spaces(str, &out, last_space);
// 	return (new_str);
// }

void	ft_add_env_var(char *key, char *val, int true_or_false,
		t_minishell *minishell)
{
	t_lists_env	list_env;
	char		**str;
	char		*val_update;
	char		*no_space;

	printf("in ft_add_env_var value is :%s\n", val);
	no_space = ft_no_space(val);
	val_update = ft_remove_ft_q(no_space);
	list_env = ft_split_lists_env(minishell->environ);
	if (true_or_false == 1)
	{
		str = ft_modify_env_var(minishell->environ, key, val_update);
		ft_free_double_d(minishell->environ);
		minishell->environ = str;
	}
	else if (true_or_false == 0)
		ft_modif_env_var(list_env, key, val_update, minishell);
	free(val_update);
	free(no_space);
	ft_free_lists_env(list_env);
}

int	ft_export(char **argv, t_minishell **minishell, int exit_s)
{
	int		i;
	char	*key;

	exit_s = 0;
	i = 1;
	if (!argv[1])
		return (1);
	while (argv[i] != NULL)
		i++;
	i = 1;
	while (argv[i])
	{
		if (ft_keycheck(argv[i]) == 0)
			exit_s = ft_export_error_msg(argv[i]);
		else
		{
			key = ft_extract_key(argv[i]);
			if (!ft_key_check(key, *minishell))
				ft_add_env_var(key, ft_extract_val(argv[i]), 0, *minishell);
			else
				ft_add_env_var(key, ft_extract_val(argv[i]), 1, *minishell);
		}
		i++;
	}
	return (exit_s);
}
