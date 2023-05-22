/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:14:22 by vics              #+#    #+#             */
/*   Updated: 2023/05/19 21:06:30 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "template.h"
#include <time.h>

t_variables *global_var = NULL;
void 	signalHandler(int signal)
{
	printf("ACK RETURNED->1\n");
	global_var->error_reciving = 1;
}

void 	signalHandler_2(int signal)
{
	printf("ACK RETURNED->0\n");
	global_var->error_reciving = 0;
}

int	send_bit(char str, int i)
{
	if (str & (1 << i))
	{
		printf("1");
		kill(global_var->pid, SIGUSR1);
		return (1);
	}
	else
	{
		printf("0");
		kill(global_var->pid, SIGUSR2);
		return (0);
	}
	return (0);
}

void	stringToBits(const char* str)
{
	int j;
	int error;
	char *bits;

	j = 0;
	bits = malloc(sizeof(char) * 9);
	ft_bzero(bits, 9);
    while (str[j])
	{
        for (int i = 7; i >= 0; i--)
		{
            error = 1;
			while (error)
			{
				int x = send_bit(str[j], i);
				usleep(global_var->bauds_pause);
				if (x == global_var->error_reciving)
					error = 0;
			}
        }
		printf("\n");
        j++;
    }
}

int main (int argc, char **argv) 
{
	global_var = malloc(sizeof(t_variables));
	global_var->bauds_pause = 104;
	global_var->personal_pid = ft_itoa(getpid());
	global_var->pid = ft_atoi(argv[1]);
	global_var->error_reciving = false;

	printf("PID: %s\n", global_var->personal_pid);

	clock_t inicio, fin; //ELIMINAR ESTO
    double tiempo_total; //ELIMINAR ESTO
	inicio = clock();    //ELIMINAR ESTO

	printf("vel: %d\n", global_var->bauds_pause);
	signal(SIGUSR1, &signalHandler);
	signal(SIGUSR2, &signalHandler_2);
/**/
	global_var->error_reciving = true;
	kill(global_var->pid, SIGUSR1);
	kill(global_var->pid, SIGUSR2);
	usleep(global_var->bauds_pause);


	printf("\nENVIANDO TEXTO\n");
	const char* texto = "hola\n";
	stringToBits(texto);

	usleep(global_var->bauds_pause);
	global_var->error_reciving = true;
	kill(global_var->pid, SIGUSR1);
	kill(global_var->pid, SIGUSR2);
	usleep(global_var->bauds_pause);
	/*global_var->error_reciving = true;
	
	stringToBits_2(global_var->personal_pid);
	usleep(global_var->bauds_pause);
	stringToBits_2("\n");
	usleep(global_var->bauds_pause);
	printf("ERROR RECIVING = %d\n", global_var->error_reciving);

	usleep(global_var->bauds_pause);
	printf("FINALIZACION TRANSFERENCIA PID\n");
	kill(global_var->pid, SIGUSR1);
	kill(global_var->pid, SIGUSR2);
	usleep(global_var->bauds_pause);*/

	fin = clock(); // Registrar el tiempo de finalización
    printf("El tiempo de ejecución fue: %.7f segundos\n", tiempo_total);
}
