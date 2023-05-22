#ifndef  TEMPLATE_STRUCT_H
# define TEMPLATE_STRUCT_H

# include <stdbool.h>

typedef struct s_variables
{
	char	*str_bits;
	int		pid;
	int		bauds_pause;
	char	*personal_pid;
	int		recived_counter;
	bool	error_reciving;
}	t_variables;

#endif