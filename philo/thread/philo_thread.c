/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:47:10 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/05 14:28:29 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*monitoring(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		pthread_mutex_lock(&data->m_monitor);
		if (data->sig == DEAD)
		{
			pthread_mutex_unlock(&data->m_monitor);
			break ;
		}
		pthread_mutex_unlock(&data->m_monitor);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (1)
	{
		eat(philo, data);
		pthread_mutex_lock(&data->m_monitor);
		if (data->sig == DEAD)
		{
			pthread_mutex_unlock(&data->m_monitor);
			break ;
		}
		pthread_mutex_unlock(&data->m_monitor);
		sleeping(philo, data);
	}
	return (NULL);
}

int	philo_thread(t_data *data)
{
	int			i;
	
	i = 0;
	pthread_mutex_init(&data->m_monitor, NULL);
	if (pthread_create(&data->monitoring, NULL, &monitoring, (void *)data))
		return (ft_phtread_create_error(data));
	data->start = get_time();
	while (i < data->nbr_human)
	{
		if (pthread_create(&data->philo[i].th, NULL, &routine, (void *)&data->philo[i]))
			return (ft_phtread_create_error(data));
		i++;
	}
	i = 0;
	while (i < data->nbr_human)
	{
		pthread_join(data->philo[i].th, NULL);
		i++;
	}
	pthread_join(data->monitoring, NULL);
	pthread_mutex_destroy(&data->m_monitor);
	return (1);
}