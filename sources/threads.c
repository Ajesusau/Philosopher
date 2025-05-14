/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:55:52 by anareval          #+#    #+#             */
/*   Updated: 2025/05/14 13:08:27 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	is_dead(t_data *data, int i)
{
	pthread_mutex_lock(&data->dead_mutex);
	data->dead_flag = 1;
	pthread_mutex_unlock(&data->dead_mutex);
	msleep(1);
	send_messages(data->start_time, i + 1, "died");
}

int	all_meals(t_data *data)
{
	int	i;
	int	count_all_meals;
	int	meals_count;

	i = 0;
	count_all_meals = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_lock(&data->philos[i].meals_count_mutex);
		meals_count = data->philos[i].meals_count;
		pthread_mutex_unlock(&data->philos[i].meals_count_mutex);
		if (meals_count == data->philos_must_eat)
			count_all_meals++;
		i++;
	}
	if (count_all_meals == data->num_of_philos)
		return (1);
	else
		return (0);
}

void	*start_god(void *var)
{
	t_data	*data;
	size_t	last_meal_time;
	int		i;

	data = (t_data *) var;
	while (!data->dead_flag && !all_meals(data))
	{
		i = 0;
		msleep(1);
		while (i < data->num_of_philos)
		{
			pthread_mutex_lock(&data->philos[i].eat_mutex);
			last_meal_time = get_current_time() - data->philos[i].last_meal;
			pthread_mutex_unlock(&data->philos[i].eat_mutex);
			if (last_meal_time >= data->time_to_die
				&& data->philos[i].meals_count != data->philos_must_eat)
			{
				is_dead(data, i);
				break ;
			}
			i++;
		}
		msleep(1);
	}
	return (NULL);
}

void	*start_philo(void *var)
{
	t_philo	*philo;

	philo = (t_philo *) var;
	while (!philo->data->dead_flag
		&& (philo->meals_count != philo->data->philos_must_eat))
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
