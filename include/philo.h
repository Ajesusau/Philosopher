/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:00:05 by anareval          #+#    #+#             */
/*   Updated: 2025/05/08 13:26:40 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INT_MAX 2147483647

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
}	t_philo;

typedef struct s_data
{
	int			num_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			philos_must_eat;
	int			dead_flag;
	t_philo		*philos;
}	t_data;

//inicialice.c--------------------------------------------------
void		*start_philo(void *var);
void		ini_philo(t_data *data);
int			init_data(char **argv, t_data *data);

//philo.c-------------------------------------------------------
int			check_arg(char **argv);

//threads.c-----------------------------------------------------
void		wait_for_philos(t_data *data);

//utils.c-------------------------------------------------------
long long	ft_atoll(const char *str);

#endif
