/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:07:14 by victgonz          #+#    #+#             */
/*   Updated: 2023/05/22 09:33:04 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  TEMPLATE_STRUCT_H
# define TEMPLATE_STRUCT_H

#include <stdbool.h>
#include <signal.h>

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