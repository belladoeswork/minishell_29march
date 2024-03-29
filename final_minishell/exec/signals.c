/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:17:02 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/29 16:13:58 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

void	ft_signal_ctrl_c(int numsig)
{
	g_global.error_num = 130;
	// printf("\nReceived SIGINT and exit status is : %d\n",g_global.error_num);
	// printf("lumumbash$ ");
	//write(STDOUT_FILENO, "\nlumumbash$ ", 13);
	ft_putstr_fd("\nlumumbash$ ", 1);
	fflush(stdin); // Flush the output buffer
	(void)numsig;   // Unused parameter
}

// void	ft_signal_ctrl_d(int numsig)
// {
// 	g_global.error_num = 131;
// 	write(STDOUT_FILENO, "\nReceived SIGQUIT\n", 43);
// 	// printf("\nReceived SIGQUIT and exit status is : %d\n",g_global.error_num);
// 	exit(EXIT_SUCCESS); // Exit the shell gracefully
// 	(void)numsig;       // Unused parameter
// }

// void	ft_signal_ctrl_slash(int numsig)
// {
// 	g_global.error_num = 131;
// 	printf("\nReceived SIGQUIT and exit status is : %d\n", g_global.error_num);
// 	// printf("lumumbash$ ");
// 	fflush(stdout); // Flush the output buffer
// 	exit(EXIT_SUCCESS);
// 	(void)numsig; // Unused parameter
// }
void	ft_signals(void)
{
	signal(SIGINT, ft_signal_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}