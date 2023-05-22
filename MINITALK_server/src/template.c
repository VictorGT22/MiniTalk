/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:14:22 by vics              #+#    #+#             */
/*   Updated: 2023/05/19 21:15:58 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#include "template.h"

t_variables *global_var = NULL;

char	bitsToString(const char* bits)
{
    int i = 0;
	
    while (bits[i] != '\0') {
        unsigned char ch = 0;
        for (int j = 0; j < 8; j++) {
            ch = (ch << 1) | (bits[i] - '0');
            i++;
        }
        return (ch);
    }
	return ('\0');
}

void	print_bits()
{
	char ch;
	
	ch = bitsToString(global_var->str_bits);
	printf("%c", ch);
	ft_bzero(global_var->str_bits, 9);
	global_var->recived_counter = 0;
}

void signal_handler(int signal, siginfo_t *info, void *context)
{
	//printf("entra\n");
	global_var->pid = info->si_pid;
	if (signal == SIGUSR1)
	{
		sigaddset(&global_var->set, SIGUSR1);
    	kill(global_var->pid, SIGUSR1);
	}
	else
	{
		sigaddset(&global_var->set, SIGUSR2);
    	kill(global_var->pid, SIGUSR2);
	}
	//printf("PID CLIENTE: %d\n", global_var->pid);
}

int	ft_ismemberset(int signal)
{
	int isIncluded = (global_var->set.__val[0] & (1 << (signal - 1))) != 0;
	if (isIncluded)
		return (1);
	return (0);
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
	global_var->bauds_pause = 104;
	//printf("vel: %d\n", global_var->bauds_pause);
	global_var->personal_pid = ft_itoa(getpid());
	global_var->str_bits = malloc(sizeof(char) * 9);
	global_var->conversation_started = false;
	ft_bzero(global_var->str_bits, 9);
	global_var->pid = 0;
	global_var->recived_counter = 0;
	sigemptyset(&global_var->set);
	free(global_var->personal_pid);

	while (1) {
		if (ft_ismemberset(SIGUSR1) && ft_ismemberset(SIGUSR2))
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
		}
		
		usleep(1000);
	}
    return 0;
}