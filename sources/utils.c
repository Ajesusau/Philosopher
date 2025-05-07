/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:21:16 by anareval          #+#    #+#             */
/*   Updated: 2025/05/07 19:03:13 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_philo(void *philo)
{
	static int i = 0;

	if ((pthread_t) philo)
		printf("Philo %d created\n", ++i);
	return (NULL);
}

void	ft_free(t_philo *philo)
{
	if (philo->philosopher)
		free (philo->philosopher);
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
