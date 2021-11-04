/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:47:10 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/04 15:18:50 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	eat(philo, data);
	return (NULL);
}

int	philo_thread(t_data *data)
{
	int			i;
	
	i = 0;
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
	return (1);
}