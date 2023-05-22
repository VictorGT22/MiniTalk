/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:14:22 by vics              #+#    #+#             */
/*   Updated: 2023/05/22 14:12:36 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#include "template.h"

t_variables *global_var = NULL;

void	ft_btoa(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
		bit = 0;
		i = 0;			
	}
}

void signal_handler(int signal, siginfo_t *info, void *context)
{
	global_var->pid = info->si_pid;
	//printf("PID CLIENTE: %d\n", global_var->pid);
	// if (!global_var->conversation_started && signal == SIGUSR1)
	// {
		// printf("Peticion comunicacion\n");
		// global_var->conversation_started = true;
		// kill(global_var->pid, SIGUSR1);
	// }
	if (global_var->conversation_started && signal == SIGUSR1)
	{
		printf("1\n");
		ft_btoa(SIGUSR1);
    	kill(global_var->pid, SIGUSR1);
	}
	else if (global_var->conversation_started)
	{
		printf("0\n");
		ft_btoa(SIGUSR2);
    	kill(global_var->pid, SIGUSR2);
	}
}

int main()
{
	struct sigaction sa;
    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("pid personal: %d\n", getpid());
	global_var = malloc(sizeof(t_variables));
	global_var->bauds_pause = 1000;
	global_var->personal_pid = ft_itoa(getpid());
	global_var->str_bits = malloc(sizeof(char) * 9);
	global_var->conversation_started = true;
	ft_bzero(global_var->str_bits, 9);
	global_var->pid = 0;
	global_var->recived_counter = 0;
	sigemptyset(&global_var->set);
	free(global_var->personal_pid);

	while (1) {
		pause();
	}
    return 0;
}

/*	
if (ft_ismemberset(SIGUSR1))
		{
			sigemptyset(&global_var->set);
			global_var->conversation_started = global_var->conversation_started ? false : true;
			if (!global_var->conversation_started)
			{
				ft_bzero(global_var->str_bits, 9);
				global_var->recived_counter = 0;
				printf("FINAL TTRANSFERENCIA\n");
			}
			else
				printf("INICIO TTRANSFERENCIA\n");
			sigemptyset(&global_var->set);
		}
	
else if (global_var->conversation_started && ft_ismemberset(SIGUSR1) && !ft_ismemberset(SIGUSR2))
		{
			sigemptyset(&global_var->set);
			global_var->str_bits[global_var->recived_counter] = '1';
			global_var->recived_counter++;
			if (global_var->recived_counter > 7)
				print_bits();
		}
		else if (global_var->conversation_started && !ft_ismemberset(SIGUSR1) && ft_ismemberset(SIGUSR2))
		{
			sigemptyset(&global_var->set);
			global_var->str_bits[global_var->recived_counter] = '0';
			global_var->recived_counter++;
			if (global_var->recived_counter > 7)
				print_bits();
		}*/