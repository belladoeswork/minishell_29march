#include "lumumbash.h"
#include "expander.h"

t_global g_global;

static void	ft_init_minishell(t_minishell *minishell, char **env)
{    
    memset(minishell, 0, sizeof(t_minishell));
    minishell->environ = ft_double_strdup(env);
    minishell->line = NULL;  
    tcgetattr(STDIN_FILENO, &(minishell->original_term));
}


static void	ft_start_execution(t_minishell *minishell)
{
	ft_init_tree(minishell->ast);

	minishell->exit_s = ft_exec_node(minishell->ast, false, minishell);
	ft_clear_ast((&minishell->ast), minishell); // minishell or NULL?
}

// void print_lumumbash() {
//     printf("\033[1;31m"); // Start color code for red
//     printf(" __       __    __  .___  ___.  __    __  .___  ___. .______        ___           _______. __    __  \n");
//     printf("|  |     |  |  |  | |   \\/   | |  |  |  | |   \\/   | |   _  \\      /   \\         /       ||  |  |  | \n");
//     printf("|  |     |  |  |  | |  \\  /  | |  |  |  | |  \\  /  | |  |_)  |    /  ^  \\       |   (----`|  |__|  | \n");
//     printf("|  |     |  |  |  | |  |\\/|  | |  |  |  | |  |\\/|  | |   _  <    /  /_\\  \\       \\   \\    |   __   | \n");
//     printf("|  `----.|  `--'  | |  |  |  | |  `--'  | |  |  |  | |  |_)  |  /  _____  \\  .----)   |   |  |  |  | \n");
//     printf("|_______| \\______/  |__|  |__|  \\______/  |__|  |__| |______/  /__/     \\__\\ |_______/    |__|  |__| \n");
//     printf("\033[0m"); // Reset color to default
// }

void print_lumumbash() {
    printf("\033[0;31m"); // Set text color to red
    printf(" __       __    __  .___  ___.  __    __  .___  ___. .______        ___           _______. __    __  \n");
    printf("|  |     |  |  |  | |   \\/   | |  |  |  | |   \\/   | |   _  \\      /   \\         /       ||  |  |  | \n");
    printf("|  |     |  |  |  | |  \\  /  | |  |  |  | |  \\  /  | |  |_)  |    /  ^  \\       |   (----`|  |__|  | \n");
    printf("\033[0;32m"); // Set text color to green
    printf("|  |     |  |  |  | |  |\\/|  | |  |  |  | |  |\\/|  | |   _  <    /  /_\\  \\       \\   \\    |   __   | \n");
    printf("|  `----.|  `--'  | |  |  |  | |  `--'  | |  |  |  | |  |_)  |  /  _____  \\  .----)   |   |  |  |  | \n");
    printf("\033[0;33m"); // Set text color to yellow
    printf("|_______| \\______/  |__|  |__|  \\______/  |__|  |__| |______/  /__/     \\__\\ |_______/    |__|  |__| \n");
    printf("\033[0m"); // Reset text color
}
void	ft_print_tokens(t_token *token)
{
	// int	i;

	// i = 0;
	while(token != NULL)
	{
		printf("token value is %s\n", token->value);
		token = token->next;
	}
}

int	main(int argc, char **argv, char **env)
{
	((void)argc, (void)argv);
    t_minishell minishell;
	t_token		*new_tokens;

	//print_lumumbash();
	ft_signals();
	ft_init_minishell(&minishell, env);
	while (1)
	{
		minishell.line = readline(PROMPT);
		if (!minishell.line)
		{
			break;
			(ft_clean_shell(&minishell),
			ft_putstr_fd("exit\n", 1), exit(minishell.exit_s));
		}
		if (minishell.line[0])
			add_history(minishell.line);
		minishell.tokens = ft_tokenize(minishell.
		line);
		if (!minishell.tokens)
			continue ;
		new_tokens = minishell.tokens;
		new_tokens->prev = NULL;
		ft_print_tokens(new_tokens);
		minishell.tokens = ft_expander(new_tokens, minishell.environ);
		minishell.ast = ft_parse(&minishell);
		if (minishell.parse_error.type)
		{
			ft_handle_parse_error(&minishell);
			continue ;
		}
		ft_start_execution(&minishell);
	}
	//ft_putstr_fd("exit\n", 1);
	//exit(minishell.exit_s));
	ft_putstr_fd("exit\n", 1);
	fflush(stdout);
	ft_free_double_d(minishell.environ);
	ft_collector(NULL, true);
	return (ft_clean_shell(&minishell), minishell.exit_s);
}
// valgrind --leak-check=full --track-origins=yes ./lumumbash