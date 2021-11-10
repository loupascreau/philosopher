/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:03:12 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/10 14:07:07 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	echoing(t_philo *philo, t_data *data, char *action)
{
	pthread_mutex_lock(&data->m_write);
	if (ft_check_dead(data))
	{
		pthread_mutex_unlock(&data->m_write);
		ft_unlock_fork(data, philo);
		return ;
	}
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
	if (ft_check_dead(data))
		return ;
	pthread_mutex_lock(&data->tab_fork);
	if (data->t_fork[fork] != -1)
	{
		while (data->time_to_die <= data->time_to_eat)
		{
			if (get_time() - data->start >= data->time_to_die)
			{
				pthread_mutex_unlock(&data->tab_fork);
				return (died(philo, data));
			}
		}
	}
	pthread_mutex_unlock(&data->tab_fork);
	pthread_mutex_lock(&data->m_fork[fork]);
	pthread_mutex_lock(&data->tab_fork);
	data->t_fork[fork] = philo->human;
	pthread_mutex_unlock(&data->tab_fork);
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
	if (ft_check_dead(data))
		return ;
	echoing(philo, data, EAT);
	philo->meal_nbr++;
	philo->last_eat = get_time();
	my_usleep(data->time_to_eat, data);
	ft_unlock_fork_after_eat(data, philo);
}

void	sleeping(t_philo *philo, t_data *data)
{
	if (data->end_eat == data->nbr_human)
		return ;
	echoing(philo, data, SLEEP);
	my_usleep(data->time_to_sleep, data);
	if (philo->last_eat >= 0 && get_time() - philo->last_eat \
	> data->time_to_die)
		return (died(philo, data));
	echoing(philo, data, THINK);
}

void	died(t_philo *philo, t_data *data)
{
	echoing(philo, data, DIED);
	pthread_mutex_lock(&data->m_monitor);
	data->sig = DEAD;
	pthread_mutex_unlock(&data->m_monitor);
}
