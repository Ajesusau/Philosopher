/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:00:05 by anareval          #+#    #+#             */
/*   Updated: 2025/05/13 13:41:42 by anareval         ###   ########.fr       */
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

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	t_data			*data;
	int				right;
	int				left;
	size_t			last_meat;
}	t_philo;

typedef struct s_data
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philos_must_eat;
	int				num_of_philos;
	size_t			start_time;
	int				dead_flag;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_data;

//inicialice.c--------------------------------------------------
void		ini_philo(t_data *data);
void		ini_fork(t_data *data);
int			init_data(char **argv, t_data *data);

//inicialice.c--------------------------------------------------
void		ft_think(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		ft_eat(t_philo *philo);

//philo.c-------------------------------------------------------
int			check_arg(char **argv);

//threads.c-----------------------------------------------------
void		*start_philo(void *var);
void		wait_for_philos(t_data *data);

//utils.c-------------------------------------------------------
void		msleep(size_t m_second);
void		send_messages(size_t start_time, int id, char *str);
size_t		get_current_time(void);
long long	ft_atoll(const char *str);

#endif
