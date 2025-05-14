/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:52:06 by anareval          #+#    #+#             */
/*   Updated: 2025/05/14 15:35:21 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ini_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].last_meal = data->start_time;
		data->philos[i].right = data->philos[i].id - 1;
		data->philos[i].meals_count = 0;
		data->philos[i].lock_l_check = 0;
		data->philos[i].lock_r_check = 0;
		pthread_mutex_init(&data->philos[i].eat_mutex, NULL);
		pthread_mutex_init(&data->philos[i].meals_count_mutex, NULL);
		if (data->philos[i].id == data->num_of_philos)
			data->philos[i].left = 0;
		else
			data->philos[i].left = data->philos[i].id;
		pthread_create
			(&data->philos[i].thread, NULL, &start_philo, &data->philos[i]);
		i++;
	}
}

void	ini_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

int	init_data(char **argv, t_data *data)
{
	int	i;
	int	error;

	i = 0;
	error = check_arg(argv);
	data->time_to_die = ft_atoll(argv[2]);
	data->time_to_eat = ft_atoll(argv[3]);
	data->time_to_sleep = ft_atoll(argv[4]);
	data->dead_flag = 0;
	data->start_time = get_current_time();
	data->num_of_philos = ft_atoll(argv[1]);
	pthread_mutex_init(&data->dead_mutex, NULL);
	if (argv[5])
		data->philos_must_eat = ft_atoll(argv[5]);
	else
		data->philos_must_eat = -1;
	data->philos = malloc (sizeof(t_philo) * data->num_of_philos);
	if (!data->philos)
		return (1);
	data->forks = malloc (sizeof(pthread_mutex_t) * data->num_of_philos);
	if (!data->forks)
		return (1);
	return (error);
}
