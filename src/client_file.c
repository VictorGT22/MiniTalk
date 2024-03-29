/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:14:22 by vics              #+#    #+#             */
/*   Updated: 2023/10/23 12:07:25 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "template.h"
#include "template_struct.h"
#include <time.h>
/*
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
	return (-1);
}

void	stringToBits(char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(global_var->pid, SIGUSR1);
		else
			kill(global_var->pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}*/

int main (int argc, char **argv) 
{
	/*t_variables *global_var;

	global_var = malloc(sizeof(t_variables));
	global_var->bauds_pause = 5000;
	global_var->personal_pid = getpid();
	global_var->pid = ft_atoi(argv[1]);*/
	//global_var->error_reciving = false;

	/*printf("PID CLIENTE: %d\n", global_var->personal_pid);
	printf("PID SERVER: %d\n", global_var->pid);

	clock_t inicio, fin; //ELIMINAR ESTO
    double tiempo_total; //ELIMINAR ESTO
	inicio = clock();    //ELIMINAR ESTO

	printf("vel: %d\n", global_var->bauds_pause);
	signal(SIGUSR1, &signalHandler);
	signal(SIGUSR2, &signalHandler_2);

	// printf("INCICIO TRANSMISION\n");
	// global_var->error_reciving = true;
	int peticion = 1;//kill(global_var->pid, SIGUSR1);
	printf("Peticion conexion: %d\n", peticion);
	// usleep(global_var->bauds_pause);
	printf("\nENVIANDO TEXTO\n");
	const char *texto = "pepeppppppppppert";//argv[2];
	if (peticion)
	{
		int i = 0;
		while (texto[i])
		{
			stringToBits(texto[i]);
			i++;
		}
		//stringToBits("\0");
	}*/

	printf("FIN TRANSMISION\n");
	// global_var->error_reciving = true;
	// kill(global_var->pid, SIGUSR1);
	// usleep(1);
	// kill(global_var->pid, SIGUSR2);
	// usleep(global_var->bauds_pause);

	
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

	//fin = clock(); // Registrar el tiempo de finalización
    //printf("El tiempo de ejecución fue: %.7f segundos\n", tiempo_total);
}
