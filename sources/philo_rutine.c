/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:55:40 by anareval          #+#    #+#             */
/*   Updated: 2025/05/13 13:36:42 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	send_messages(philo->data->start_time, philo->id, "is thinking");
}

void	ft_sleep(t_philo *philo)
{
	send_messages(philo->data->start_time, philo->id, "is sleeping");
	msleep(philo->data->time_to_sleep);
}

void	ft_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		msleep(1);
		pthread_mutex_lock(&philo->data->forks[philo->right]);
		pthread_mutex_lock(&philo->data->forks[philo->left]);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->left]);
		pthread_mutex_lock(&philo->data->forks[philo->right]);
	}
	send_messages(philo->data->start_time, philo->id, "is eating");
	msleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->forks[philo->left]);
	pthread_mutex_unlock(&philo->data->forks[philo->right]);
}
