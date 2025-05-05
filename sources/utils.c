/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:21:16 by anareval          #+#    #+#             */
/*   Updated: 2025/05/05 16:04:13 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_thread(void *philo)
{
	static int	i;

	i = 0;
	if ((pthread_t) philo)
		printf("Philo %d created\n", ++i);
	sleep(3);
	return (NULL);
}

void	ft_free(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philosophers)
	{
		if (&philo->mutex[i])
			pthread_mutex_destroy(&philo->mutex[i]);
		i++;
	}
	if (philo->mutex)
		free (philo->mutex);
	if (philo->philosopher)
		free (philo->philosopher);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	sig;

	n = 0;
	sig = 1;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == ('-'))
			sig = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = (n * 10) + (*str - '0');
		str++;
	}
	return (n * sig);
}
