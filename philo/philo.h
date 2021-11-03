/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:50:54 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/03 16:02:29 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int					which;
}				t_philo;

typedef struct s_data
{
	int			nbr_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_of_eat;
	long		start;
	t_philo		*philo;
}				t_data;

/*****init****/

int		ft_init(t_data *data, char **argv, int argc);

/*****utils*****/

int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		get_time(void);

/*****Thread*****/

int		philo_thread(t_data *data);

/*****Args*****/

int		ft_check_args(char **argv);

/****Errors*****/

int		ft_argc_error(int argc);
int		ft_invalid_arg(char *arg);
int		ft_malloc_error(void);

#endif
