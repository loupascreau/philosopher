/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:55:11 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/12 08:42:03 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_exit(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nbr_human)
	{
		pthread_mutex_destroy(&data->m_fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->tab_fork);
	pthread_mutex_destroy(&data->m_write);
	free(data->philo);
	data->philo = NULL;
	free(data->m_fork);
	data->m_fork = NULL;
	free(data->t_fork);
	data->t_fork = NULL;
	return (0);
}

int	ft_no_time_enough(t_data *data, t_philo *philo)
{
	if (data->start_eat > 0 && philo->last_eat > 0 && \
	((data->start_eat - data->start) + data->time_to_eat) - \
	(philo->last_eat - data->start) > data->time_to_die)
	{
		while (1)
		{
			if (get_time() - data->start >= data->time_to_die)
			{
				pthread_mutex_unlock(&data->tab_fork);
				died(philo, data);
				return (1);
			}
			if (ft_check_dead(data))
			{
				pthread_mutex_unlock(&data->tab_fork);
				return (1);
			}
		}
	}
	return (0);
}
