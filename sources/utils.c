/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:21:16 by anareval          #+#    #+#             */
/*   Updated: 2025/05/07 20:57:48 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	*start_philo(void *var)
{
	t_philo	*philo;

	philo = (t_philo *) var;
	printf("Philo %d created\n", philo->id);
	return (NULL);
}

void	ft_free(t_data *data)
{
	if (data->philos)
		free (data->philos);
}

long long	ft_atoll(const char *str)
{
	long long	n;
	int			sig;
	int			i;

	n = 0;
	i = 0;
	sig = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		str++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == ('-'))
			sig = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	if (str[i])
		return (0);
	return (n * sig);
}
