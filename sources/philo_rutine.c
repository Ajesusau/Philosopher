/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:55:40 by anareval          #+#    #+#             */
/*   Updated: 2025/06/12 11:14:15 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	send_messages
		(philo->data->start_time, philo->id, "is thinking", philo->data);
}

void	ft_sleep(t_philo *philo)
{
	send_messages
		(philo->data->start_time, philo->id, "is sleeping", philo->data);
	msleep(philo->data->time_to_sleep);
}

void	ft_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		msleep(2);
		lock_mutex(philo->left, philo->right, philo, 1);
	}
	else
	{
		lock_mutex(philo->right, philo->left, philo, 2);
		if (philo->data->num_of_philos == 1)
			msleep(philo->data->time_to_die + 10);
	}
	if (!is_philo_dead(philo->data))
	{
		eat_process(philo);
	}
	if (philo->lock_l_check == 1)
		pthread_mutex_unlock(&philo->data->forks[philo->left]);
	if (philo->lock_r_check == 1)
		pthread_mutex_unlock(&philo->data->forks[philo->right]);
	philo->lock_l_check = 0;
	philo->lock_r_check = 0;
	msleep(1);
}
