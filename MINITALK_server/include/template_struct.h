#ifndef  PUSHSWAP_STRUCT_H
# define PUSHSWAP_STRUCT_H

#include <stdbool.h>

typedef struct s_variables
{
	char		*str_bits;
	pid_t		pid;
	int			bauds_pause;
	sigset_t	set;
	char		*personal_pid;
	int			recived_counter;
	bool		conversation_started;
}	t_variables;

#endif