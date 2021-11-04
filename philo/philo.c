/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:50:28 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/04 15:11:46 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!ft_check_args(argv, argc))
		return (0);
	if (!ft_init(&data, argv, argc))
		return (0);
	if (!philo_thread(&data))
		return (0);
	return (ft_exit(&data));
}
