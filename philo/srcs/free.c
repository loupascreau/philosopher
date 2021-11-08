/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:55:11 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/08 08:05:46 by lpascrea         ###   ########.fr       */
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
	pthread_mutex_destroy(&data->m_write);
	free(data->philo);
	data->philo = NULL;
	free(data->m_fork);
	data->m_fork = NULL;
	free(data->t_fork);
	data->t_fork = NULL;
	return (0);
}