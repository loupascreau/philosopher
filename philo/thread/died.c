/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:15:42 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/08 08:37:00 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_only_one_philo(t_philo *philo, t_data *data)
{
	take_a_fork(philo, data, philo->left_f);
	my_usleep(data->time_to_die, data);
	echoing(philo, data, DIED);
	pthread_mutex_lock(&data->m_monitor);
	data->sig = DEAD;
	pthread_mutex_unlock(&data->m_monitor);
	pthread_mutex_unlock(&data->m_fork[philo->left_f]);
	return ;
}

int	ft_check_dead(t_data *data)
{
	pthread_mutex_lock(&data->m_monitor);
	if (data->sig == DEAD)
	{
		pthread_mutex_unlock(&data->m_monitor);
		return (1);
	}
	pthread_mutex_unlock(&data->m_monitor);
	return (0);
}
