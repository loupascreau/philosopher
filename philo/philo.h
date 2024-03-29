/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:50:54 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/12 08:24:57 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

/******************************************************************************/
/*								print actions								  */
/******************************************************************************/

# define FORK	"has taken a fork"
# define EAT		"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DIED	"died"

/******************************************************************************/
/*									signaux									  */
/******************************************************************************/

# define INIT	0
# define DEAD	1
# define STOP	2

/******************************************************************************/
/*							structure generale								  */
/******************************************************************************/

typedef struct s_data
{
	struct s_philo		*philo;
	int					nbr_human;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nbr_of_eat;
	int					end_eat;
	long				start;
	int					sig;
	pthread_t			monitoring;
	pthread_mutex_t		m_monitor;
	pthread_mutex_t		m_write;
	pthread_mutex_t		*m_fork;
	pthread_mutex_t		tab_fork;
	int					*t_fork;
	long				start_eat;
}				t_data;

/******************************************************************************/
/*							structure par philo								  */
/******************************************************************************/

typedef struct s_philo
{
	struct s_data		*data;
	int					human;
	int					right_f;
	int					left_f;
	int					meal_nbr;
	long				last_eat;
	pthread_t			th;
}				t_philo;

/******************************************************************************/
/*									init									  */
/******************************************************************************/

int		ft_init(t_data *data, char **argv, int argc);

/******************************************************************************/
/*									utils									  */
/******************************************************************************/

void	ft_putnbr(int n);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	my_usleep(int time, t_data *data);
long	get_time(void);

/******************************************************************************/
/*								thread - died								  */
/******************************************************************************/

int		philo_thread(t_data *data);
void	ft_only_one_philo(t_philo *philo, t_data *data);
int		ft_check_dead(t_data *data);
void	ft_unlock_fork(t_data *data, t_philo *philo);
void	ft_check_unlock_before_exit(t_data *data, t_philo *philo);
int		ft_no_time_enough(t_data *data, t_philo *philo);

/******************************************************************************/
/*									actions									  */
/******************************************************************************/

void	echoing(t_philo *philo, t_data *data, char *action);
void	take_a_fork(t_philo *philo, t_data *data, int fork);
void	eat(t_philo *philo, t_data *data);
void	ft_unlock_fork_after_eat(t_data *data, t_philo *philo);
void	sleeping(t_philo *philo, t_data *data);
void	died(t_philo *philo, t_data *data);

/******************************************************************************/
/*									args									  */
/******************************************************************************/

int		ft_check_args(char **argv, int argc);

/******************************************************************************/
/*									errors									  */
/******************************************************************************/

int		ft_argc_error(int argc);
int		ft_invalid_arg(char *arg);
int		ft_malloc_error(void);
int		ft_phtread_create_error(t_data *data);

/******************************************************************************/
/*								free - exit									  */
/******************************************************************************/

int		ft_exit(t_data *data);

#endif
