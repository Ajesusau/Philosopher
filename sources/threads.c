/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:55:52 by anareval          #+#    #+#             */
/*   Updated: 2025/05/13 18:12:37 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_meals(t_data *data)
{
	int	i;
	int	count_all_meals;

	i = 0;
	count_all_meals = 0;
	while (i < data->num_of_philos)
	{
		if (data->philos[i].eats_count == data->philos_must_eat)
			count_all_meals++;
		i++;
	}
	if (count_all_meals == data->philos_must_eat)
		return (1);
	else
		return (0);
}

void	*start_god(void *var)
{
	t_data	*data;
	int		i;

	data = (t_data *) var;
	while (!data->dead_flag && !all_meals(data))
	{
		i = 0;
		msleep(1);
		while (i < data->num_of_philos)
		{
			if (((get_current_time() - data->philos[i].last_meal)
					>= data->time_to_die) && (data->philos[i].eats_count
					!= data->philos_must_eat))
			{
				pthread_mutex_lock(&data->dead_mutex);
				data->dead_flag++;
				pthread_mutex_unlock(&data->dead_mutex);
				send_messages(data->start_time, i + 1, "is dead");
				break ;
			}
			i++;
		}
	}
	return (NULL);
}

void	*start_philo(void *var)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *) var;
	while (!philo->data->dead_flag && !all_meals(philo->data))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

void	wait_for_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	pthread_join(data->god, NULL);
}
