/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:55:40 by anareval          #+#    #+#             */
/*   Updated: 2025/05/13 19:50:43 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	lock_mutex(int first, int second, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[first]);
	send_messages(philo->data->start_time, philo->id, "has taken a fork");
	if (philo->data->num_of_philos == 1)
		return ;
	pthread_mutex_lock(&philo->data->forks[second]);
	send_messages(philo->data->start_time, philo->id, "has taken a fork");
}

void	ft_think(t_philo *philo)
{
	int	dead_flag;

	pthread_mutex_lock(&philo->data->dead_mutex);
	dead_flag = philo->data->dead_flag;
	pthread_mutex_unlock(&philo->data->dead_mutex);
	if (!dead_flag && !all_meals(philo->data))
		send_messages(philo->data->start_time, philo->id, "is thinking");
}

void	ft_sleep(t_philo *philo)
{
	int	dead_flag;

	pthread_mutex_lock(&philo->data->dead_mutex);
	dead_flag = philo->data->dead_flag;
	pthread_mutex_unlock(&philo->data->dead_mutex);
	if (!dead_flag && !all_meals(philo->data))
	{
		send_messages(philo->data->start_time, philo->id, "is sleeping");
		msleep(philo->data->time_to_sleep);
	}
}

void	ft_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		msleep(1);
		lock_mutex(philo->left, philo->right, philo);
	}
	else
	{
		lock_mutex(philo->right, philo->left, philo);
		if (philo->data->num_of_philos == 1)
			msleep(philo->data->time_to_die + 10);
	}
	if (!philo->data->dead_flag)
	{
		pthread_mutex_lock(&philo->eat_mutex);
		send_messages(philo->data->start_time, philo->id, "is eating");
		pthread_mutex_lock(&philo->meals_count_mutex);
		philo->meals_count++;
		pthread_mutex_unlock(&philo->meals_count_mutex);
		msleep(philo->data->time_to_eat);
		philo->last_meal = get_current_time();
		pthread_mutex_unlock(&philo->eat_mutex);
	}
	pthread_mutex_unlock(&philo->data->forks[philo->left]);
	pthread_mutex_unlock(&philo->data->forks[philo->right]);
}
