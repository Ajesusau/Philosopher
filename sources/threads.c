/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:55:52 by anareval          #+#    #+#             */
/*   Updated: 2025/05/13 13:33:32 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_philo(void *var)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *) var;
	if (philo->data->philos_must_eat >= 0)
	{
		while (i < philo->data->philos_must_eat && philo->data->dead_flag == 0)
		{
			ft_eat(philo);
			ft_sleep(philo);
			ft_think(philo);
			i++;
		}
	}
	else
	{
		while (philo->data->dead_flag == 0)
		{
			ft_eat(philo);
			ft_sleep(philo);
			ft_think(philo);
		}
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
}
