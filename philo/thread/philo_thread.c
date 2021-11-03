/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:47:10 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/03 16:12:13 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("%d init\n", philo->which);
	return (NULL);
}

int	philo_thread(t_data *data)
{
	pthread_t			th[data->nbr_philo];
	pthread_mutex_t		mutex;
	int			i;
	
	i = 0;
	data->start = get_time();
	pthread_mutex_init(&mutex, NULL);
	while (i < data->nbr_philo)
	{
		data->philo[i].which = i + 1;
		pthread_create(&th[i], NULL, &routine, (void *)&data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_join(th[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	return (1);
}