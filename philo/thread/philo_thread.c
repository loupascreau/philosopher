/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:47:10 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/10 09:48:13 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*monitoring(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (data->end_eat == data->nbr_human)
			break ;
		if (ft_check_dead(data))
			break ;
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
		if (data->nbr_of_eat > 0 && philo->meal_nbr == data->nbr_of_eat)
		{
			data->end_eat++;
			return (NULL);
		}
		if (ft_check_dead(data))
		{
			pthread_mutex_lock(&data->tab_fork);
			if (philo->left_f == philo->human && data->t_fork[philo->left_f] \
			== philo->human && data->t_fork[philo->right_f] == philo->human)
			{
				data->t_fork[philo->left_f] = -1;
				pthread_mutex_unlock(&data->m_fork[philo->left_f]);
			}
		/*	if (philo->human == philo->left_f && data->t_fork[philo->right_f] == 0 && \
			philo->human == data->nbr_human - 1)
			{
				if (data->t_fork[philo->left_f - 1] && data->t_fork[philo->left_f - 1] == -1)
				{
					printf("human = %d, left = %d, t_l = %d, t_r = %d\n", philo->human, \
					philo->left_f, data->t_fork[philo->left_f], data->t_fork[philo->right_f]);
					data->t_fork[philo->left_f] = -1;
					pthread_mutex_unlock(&data->m_fork[philo->left_f]);
				}
			}*/
			pthread_mutex_unlock(&data->tab_fork);	
			return (NULL);
		}
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
		if (pthread_create(&data->philo[i].th, NULL, &routine, \
		(void *)&data->philo[i]))
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
