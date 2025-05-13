/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:21:16 by anareval          #+#    #+#             */
/*   Updated: 2025/05/13 16:06:26 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_exit(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	if (data->philos)
		free (data->philos);
	if (data->forks)
		free (data->forks);
}

void	msleep(size_t m_second)
{
	usleep(m_second * 1000);
}

void	send_messages(size_t start_time, int id, char *str)
{
	size_t	time;

	time = get_current_time() - start_time;
	printf("%zu %d %s\n", time, id, str);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
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
