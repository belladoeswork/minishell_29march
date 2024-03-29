#ifndef GLOBALS_H
#define GLOBALS_H

#include "lumumbash.h"


typedef struct s_global
{
	int	error_num;
	int	stop_heredoc;
	int	in_cmd;
	int	in_heredoc;
}	t_global;

//t_global	g_global;

extern t_global g_global;

#endif
