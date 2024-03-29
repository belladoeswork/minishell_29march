// #include "lumumbash.h"

// int check_if_space(char *str)
// {
// 	int i;
//     int j;

// 	i = 0;
// 	while(str[i] != 0)
// 	{
// 		if(ft_isspace(str[i]))
// 			j++;
// 		i++;
// 	}
// 	return (0);
// }

// t_token *split_tokens(t_token *token)
// {
//     char **str;
//     int i;
//     t_token *token_update;

//     i = 0;
// // "     echo            hello"
//     while(token->value != NULL)
//     {
//         if (check_space(token->value) > 0)
//         {
//             //str = ft_calloc(check_if_space(token->value) + 1, sizeof(char *));
//             str = ft_split(token->value);
//         }
//     }
//     token_update = ft_calloc(ft_strlen_double(str) + 1, sizeof(t_token));
//     while(str[i] != NULL)
//     {
//         token_update->value = str[i];
//         if (i == 0)
//         {
//             token_update->prev = token->prev;
//             token->prev->next = token_update;
//         }
//         i++;
//         token_update = token_update->next;
//     }
//     token_update->next = token->next;
//     // add the linked list in the middle of the original one
// }

// t_token *split_loop(t_token *token)
// {
//     t_token *head = token;
//     while(token != NULL)
//     {
//         split_tokens(token);
//         token = token->next;
//     }
//     return(head);
// }
