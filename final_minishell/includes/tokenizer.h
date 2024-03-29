#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "lumumbash.h"
# include <stddef.h>

# define PROMPT "lumumbash$ "

typedef enum
{
	TOKEN_WORD,                      // cmd
	TOKEN_PIPE,                      // |
	TOKEN_INPUT_REDIRECTION,         // <
	TOKEN_OUTPUT_REDIRECTION,        // >
	TOKEN_APPEND_OUTPUT_REDIRECTION, // >>
	TOKEN_HEREDOC,                   // <<
	TOKEN_NL                         // \n
}					t_token_type;
typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;
typedef enum e_error_msg
{
	CMD_NOT_FOUND,
	NO_SUCH_FILE,
	PERMISSION_DENIED,
	AMBIGUOUS,
	TOO_MANY_ARGS,
	NUMERIC_REQUIRED
}					t_error_msg;
typedef enum e_error_no
{
	SUCCESS,
	GENERAL,
	CANT_EXECUTE = 126,
	NOT_FOUND,
	ERROR_EXEC_255 = 255
}					t_error_no;
typedef struct s_err
{
	t_error_no		no;
	t_error_msg		msg;
	char			*cause;
}					t_error;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// tokens_utils.c
int					ft_isspace(char c);
void				ft_skip_spaces(char **line);
int					ft_is_quote(char c);
int					ft_is_separator(char *s);
int					ft_skip_quotes(char *str, size_t *i);
void				ft_putchar_fd(char c, int fd);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_putstr_fd(char *s, int fd);
void				ft_quote_error(char c);
// tokensn_list.c
void				ft_clear_token_list(t_token **lst);
int					ft_token_list_add_back(t_token **lst, t_token *new_token);
// handlers.c
t_token				*ft_new_token(char *value, t_token_type type);
int					ft_append_separator(t_token_type type, char **line_ptr,
						t_token **token_list);
int					ft_handle_separator(char **line_ptr, t_token **token_list);
int					ft_append_word(char **line_ptr, t_token **token_list);
void				ft_free_token(t_token *token);
t_token				*ft_tokenization_handler(char *line);
// tokenizer.c
t_token				*ft_tokenize(char *input_line);

#endif