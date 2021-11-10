/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:55:11 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/10 09:51:27 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_exit(t_data *data)
{
	int		i;

	i = 0;
	pthread_mutex_lock(&data->tab_fork);
	while (i < data->nbr_human)
	{
		printf("h = %d, t_l = %d, t_r = %d\n", i, data->t_fork[data->philo[i].left_f], data->t_fork[data->philo[i].right_f]);
		pthread_mutex_destroy(&data->m_fork[i]);
		i++;
	}
	pthread_mutex_unlock(&data->tab_fork);
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
