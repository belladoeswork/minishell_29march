#include "lumumbash.h"

int	ft_append_char_to_word(char *word, int *j, char c)
{
	word[*j] = c;
	(*j)++;
	return (1);
}

int	ft_check_special_char(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == ' ')
		return (1);
	return (0);
}

int	ft_add_word_to_token_list(t_token **token_list, char *word)
{
	if (!ft_token_list_add_back(token_list, ft_new_token(word, TOKEN_WORD)))
	{
		free(word);
		return (0);
	}
	return (1);
}

int	ft_allocate_word(char **word, char *line)
{
	*word = malloc(ft_strlen(line) + 1);
	if (!*word)
		return (0);
	return (1);
}
