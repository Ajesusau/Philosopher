/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:52:06 by anareval          #+#    #+#             */
/*   Updated: 2025/05/08 16:24:57 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_philo(void *var)
{
	t_philo	*philo;

	philo = (t_philo *) var;
	send_messages(philo->start_time, philo->id, "se ha creado");
	msleep(9);
	send_messages(philo->start_time, philo->id, "se esta aburriendo");
	return (NULL);
}

void	ini_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].start_time = data->start_time;
		pthread_create
			(&data->philos[i].thread, NULL, &start_philo, &data->philos[i]);
		i++;
	}
}

int	init_data(char **argv, t_data *data)
{
	int	i;
	int	error;

	i = 0;
	error = check_arg(argv);
	data->num_of_philos = ft_atoll(argv[1]);
	data->time_to_die = ft_atoll(argv[2]);
	data->time_to_eat = ft_atoll(argv[3]);
	data->time_to_sleep = ft_atoll(argv[4]);
	data->dead_flag = 0;
	data->start_time = get_current_time();
	if (argv[5])
		data->philos_must_eat = ft_atoll(argv[5]);
	else
		data->philos_must_eat = -1;
	if (error == 0)
		data->philos = malloc(sizeof(t_philo) * data->num_of_philos);
	return (error);
}
