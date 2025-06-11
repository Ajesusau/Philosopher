/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:54:30 by anareval          #+#    #+#             */
/*   Updated: 2025/06/11 19:31:17 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	send_message_fork(t_philo *philo)
{
	send_messages
		(philo->data->start_time, philo->id, "has taken a fork", philo->data);
}

static int	is_philo_dead(t_philo *philo)
{
	int	dead_flag;

	pthread_mutex_lock(&philo->data->dead_mutex);
	dead_flag = philo->data->dead_flag;
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (dead_flag);
}

void	eat_process(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->eat_mutex);
	pthread_mutex_lock(&philo->meals_count_mutex);
	philo->meals_count++;
	pthread_mutex_unlock(&philo->meals_count_mutex);
	send_messages(philo->data->start_time, philo->id, "is eating", philo->data);
	msleep(philo->data->time_to_eat);
}

void	lock_mutex(int first, int second, t_philo *philo, int option)
{
	if (!is_philo_dead(philo))
	{
		pthread_mutex_lock(&philo->data->forks[first]);
		if (option == 1)
			philo->lock_l_check = 1;
		else
			philo->lock_r_check = 1;
		if (!is_philo_dead(philo))
			send_message_fork(philo);
		if (philo->data->num_of_philos == 1)
			return ;
	}
	if (!is_philo_dead(philo))
	{
		pthread_mutex_lock(&philo->data->forks[second]);
		if (option == 1)
			philo->lock_r_check = 1;
		else
			philo->lock_l_check = 1;
		if (!is_philo_dead(philo))
			send_message_fork(philo);
	}
}
