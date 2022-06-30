/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:07:37 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/30 12:13:39 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_data	t_data;

typedef struct s_rules
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		count_of_eat;
}	t_rules;

typedef struct s_philo
{
	int				id;
	long			last_time_eat;
	int				count_eat;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*status;
	sem_t			*all_eat;
	t_rules			*rules;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	pid_t			*pid;
	long			time_start;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*status;
	t_philo			*philos;
	t_rules			*rules;
}	t_data;

#endif