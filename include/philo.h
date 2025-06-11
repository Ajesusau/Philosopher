/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:00:05 by anareval          #+#    #+#             */
/*   Updated: 2025/06/11 19:48:05 by anareval         ###   ########.fr       */
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
	int				lock_r_check;
	int				lock_l_check;
	size_t			last_meal;
	int				meals_count;
	pthread_mutex_t	meals_count_mutex;
	pthread_mutex_t	eat_mutex;
}	t_philo;

typedef struct s_data
{
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				philos_must_eat;
	int				num_of_philos;
	size_t			start_time;
	int				dead_flag;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	print_mutex;
	pthread_t		god;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_data;

//inicialice.c--------------------------------------------------
void		ini_philo(t_data *data);
void		ini_fork(t_data *data);
int			init_data(char **argv, t_data *data);

//philo_rutine_utils.c------------------------------------------
//static void	send_message_fork(t_philo *philo);
//static int	is_philo_dead(t_philo *philo);
void		eat_process(t_philo *philo);
void		lock_mutex(int first, int second, t_philo *philo, int option);
int			is_any_dead(t_data *data);

//philo_rutine.c------------------------------------------------
void		ft_think(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		ft_eat(t_philo *philo);

//philo.c-------------------------------------------------------
//static int			check_arg(char **argv);
//int	main(int argc, char **argv);

//threads.c-----------------------------------------------------
//static void	is_dead(t_data *data, int i);
int			all_meals(t_data *data);
void		*start_god(void *var);
void		*start_philo(void *var);
void		wait_for_philos(t_data *data);

//utils.c-------------------------------------------------------
void		ft_free(t_data *data);
void		msleep(size_t m_second);
void		send_messages(size_t start_time, int id, char *str, t_data *data);
size_t		get_current_time(void);
long long	ft_atoll(const char *str);

#endif
