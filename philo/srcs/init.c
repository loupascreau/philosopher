/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:16:40 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/03 14:49:45 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_init(t_data *data, char **argv, int argc)
{
	data->nbr_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nbr_of_eat = ft_atoi(argv[5]);
	else
		data->nbr_of_eat = 0;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philo + 1);
	if (!data->philo)
		return (ft_malloc_error());
	return (1);
}