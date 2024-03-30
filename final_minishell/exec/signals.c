/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:17:02 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/29 22:08:00 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"
// j


// void ft_signal_ctrl_c(int numsig)
// {
//     g_global.error_num = 130;
//     ft_putstr_fd("\nlumumbash$ ", 1);
    
//     // Clear input buffer
//     struct termios term;
//     tcgetattr(STDIN_FILENO, &term);
//     tcflush(STDIN_FILENO, TCIFLUSH);
//     tcsetattr(STDIN_FILENO, TCSANOW, &term);
    
//     (void)numsig;   // Unused parameter
// }
// void ft_signal_ctrl_c(int numsig)
// {
//     g_global.error_num = 130;
//     //ft_putstr_fd("\n", 1); // Move to a new line
//     ft_putstr_fd("\nlumumbash$ ", 1); // Print prompt
//     fflush(stdout); // Flush the output buffer
    
//     // Discard the current input line
//     tcflush(STDIN_FILENO, TCIFLUSH);
    
//     (void)numsig;   // Unused parameter
// }


// void ft_signal_ctrl_c(int numsig)
// {
//     g_global.error_num = 130;
//     ft_putstr_fd("\nlumumbash$ ", 1);
    
//     // Clear input buffer
//     struct termios term;
//     tcgetattr(1, &term);
//     tcflush(1, TCIFLUSH);
//     tcsetattr(1, TCSANOW, &term);
    
//     (void)numsig;   // Unused parameter
// }

void ft_signal_ctrl_c(int numsig)
{
    g_global.error_num = 130;
    ft_putstr_fd("\n", 1); // Move to a new line
    rl_on_new_line(); // Move cursor to a new line
    rl_replace_line("", 0); // Clear the current input line
    rl_redisplay(); // Redisplay the prompt
    fflush(stdout); // Flush the output buffer
    
    (void)numsig;   // Unused parameter
}

void ft_signals(void)
{
    signal(SIGINT, ft_signal_ctrl_c);
    signal(SIGQUIT, SIG_IGN);
}
