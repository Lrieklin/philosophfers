/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 04:34:57 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/30 17:12:42 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_rules(char **argv, t_rules *rules, int argc)
{
	rules->number_of_philosophers = atoi(argv[1]);
	rules->time_to_die = atoi(argv[2]);
	rules->time_to_eat = atoi(argv[3]);
	rules->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		rules->count_of_eat = atoi(argv[5]);
	printf("rules->count_of_eat = %d\n", rules->count_of_eat);
}

int	create_data(t_data *data)
{
	data->time_start = get_time();
	data->philos = NULL;
	data->thread = NULL;
	data->forks = NULL;
	// data->print = NULL;
	// data->status = NULL;
	data->philos = (t_philo *)
		malloc((data->rules->number_of_philosophers) * sizeof(t_philo));
	if (!data->philos)
		return (1);
	data->thread = (pthread_t *)malloc((data->rules->number_of_philosophers)
			* sizeof(pthread_t));
	if (!data->thread)
		return (1);
	data->forks = (pthread_mutex_t *)
		malloc((data->rules->number_of_philosophers)
			* sizeof(pthread_mutex_t));
	if (!data->forks)
		return (1);
	// data->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	// if (!data->print)
	// 	return (1);
	// data->status = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	// if (!data->status)
	// 	return (1);
	return (0);
}

void	give_forks_to_philo(t_data *data)
{
	t_philo	*philo;
	static int	i;
	int	count;

	count = data->rules->number_of_philosophers;
	// printf("count  = %d\n", count);
	philo = data->philos;
	if (philo[i].id == 1)
	{
		if (count == 1)
		{
			
			philo[0].left_fork = &(data->forks[0]);
			philo[0].right_fork = &(data->forks[0]);
			//printf("id: %d, left: %p, right: %p\n", philo[i].id, philo[i].left_fork, philo[i].right_fork);
		}
		else if (data->rules->number_of_philosophers != 1)
		{
			philo[i].left_fork = &(data->forks[i]);
			philo[i].right_fork = &(data->forks[count - 1]);
			//printf("id: %d, left: %p, right: %p\n", philo[i].id, philo[i].left_fork, philo[i].right_fork);
		}
		i++;
	}
	else if (philo[i].id == count)
	{
		philo[i].left_fork = &(data->forks[count - 1]);
		philo[i].right_fork = &(data->forks[count - 2]);
		//printf("id: %d, left: %p, right: %p\n", philo[i].id, philo[i].left_fork, philo[i].right_fork);
		i++;
	}
	else
	{
		philo[i].left_fork = &(data->forks[i]);
		philo[i].right_fork = &(data->forks[i - 1]);
		//printf("id: %d, left: %p, right: %p\n", philo[i].id, philo[i].left_fork, philo[i].right_fork);
		i++;
	}
}

void	create_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rules->number_of_philosophers)
	{
		data->philos[i].data = data;
		data->philos[i].rules = data->rules;
		data->philos[i].id = i + 1;
		data->philos[i].count_eat = 0;
		data->philos[i].last_time_eat = get_time();
		give_forks_to_philo(data);
		i++;
	}
}
