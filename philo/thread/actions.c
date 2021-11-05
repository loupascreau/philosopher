/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:03:12 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/05 14:50:57 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	echoing(t_philo *philo, t_data *data, char *action)
{
	pthread_mutex_lock(&data->m_write);
	ft_putnbr(get_time() - data->start);
	write(1, " ", 1);
	ft_putnbr(philo->human + 1);
	write(1, " ", 1);
	write(1, action, ft_strlen(action));
	write(1, "\n", 1);
	pthread_mutex_unlock(&data->m_write);
}

void	take_a_fork(t_philo *philo, t_data *data, int fork)
{
	pthread_mutex_lock(&data->m_fork[fork]);
	echoing(philo, data, FORK);
}

void	eat(t_philo *philo, t_data *data)
{
	if (data->nbr_human == 1)
		return (ft_only_one_philo(philo, data));
	if (philo->left_f < philo->right_f)
	{
		take_a_fork(philo, data, philo->left_f);
		take_a_fork(philo, data, philo->right_f);
	}
	else
	{
		take_a_fork(philo, data, philo->right_f);
		take_a_fork(philo, data, philo->left_f);
	}
	echoing(philo, data, EAT);
	philo->last_eat = get_time();
	my_usleep(data->time_to_eat, data);
	if (get_time() - philo->last_eat > data->time_to_die)
	{
		pthread_mutex_lock(&data->m_monitor);
		data->sig = DEAD;
		pthread_mutex_unlock(&data->m_monitor);
		echoing(philo, data, DIED);
	}
	pthread_mutex_unlock(&data->m_fork[philo->left_f]);
	pthread_mutex_unlock(&data->m_fork[philo->right_f]);
}

void	sleeping(t_philo *philo, t_data *data)
{
	echoing(philo, data, SLEEP);
	my_usleep(data->time_to_sleep, data);
	echoing(philo, data, THINK);
}

void	died(t_philo *philo, t_data *data)
{
	echoing(philo, data, DIED);
	data->sig = DEAD;
}
