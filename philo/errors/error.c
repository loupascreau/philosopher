/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:49:05 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/04 15:21:40 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_argc_error(int argc)
{
	if (argc < 5)
		write(2, "Missing arguments\n", 18);
	else
		write(2, "too many arguments\n", 19);
	return (0);
}

int	ft_invalid_arg(char *arg)
{
	write(2, arg, ft_strlen(arg));
	write(2, " : invalide argument\n", 21);
	return (0);
}

int	ft_malloc_error(void)
{
	write(2, "malloc error\n", 13);
	return (0);
}

int	ft_phtread_create_error(t_data *data)
{
	write(2, "pthread_create error\n", 21);
	return (ft_exit(data));
}
