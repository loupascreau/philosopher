/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:50:28 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/03 14:39:41 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philo;

	data.philo = &philo;
	if (argc < 5 || argc > 6)
		return (ft_argc_error(argc));
	if (!ft_check_args(argv))
		return (0);
	if (!ft_init(&data, argv, argc))
		return (0);
	if (!philo_thread(&data))
		return (0);
	return (0);
}
