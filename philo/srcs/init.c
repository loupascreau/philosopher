/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:16:40 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/04 15:11:20 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_philo(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nbr_human)
	{
		data->philo[i].data = data;
		data->philo[i].human = i;
		data->philo[i].left_f = data->philo[i].human;
		data->philo[i].right_f = (data->philo[i].left_f + 1) % data->nbr_human;
		pthread_mutex_init(&data->m_fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->m_write, NULL);
	return (1);
}

int	ft_init(t_data *data, char **argv, int argc)
{
	data->nbr_human = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nbr_of_eat = ft_atoi(argv[5]);
	else
		data->nbr_of_eat = 0;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_human);
	if (!data->philo)
		return (ft_malloc_error());
	data->m_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nbr_human);
	if (!data->m_fork)
		return (ft_malloc_error());
	return (init_philo(data));
}