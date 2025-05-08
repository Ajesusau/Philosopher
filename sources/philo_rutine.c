/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:55:40 by anareval          #+#    #+#             */
/*   Updated: 2025/05/08 19:25:35 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	send_messages(philo->start_time, philo->id, "is thinking");
}

void	ft_sleep(t_philo *philo)
{
	send_messages(philo->start_time, philo->id, "is sleeping");
	msleep(philo->time_to_sleep);
}

void	ft_eat(t_philo *philo)
{
	send_messages(philo->start_time, philo->id, "is eating");
	msleep(philo->time_to_eat);
}
