/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:47:01 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/30 10:30:13 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_rules(char **argv, t_rules *rules, int argc)
{
	rules->number_of_philosophers = atoi(argv[1]);
	rules->time_to_die = atoi(argv[2]);
	rules->time_to_eat = atoi(argv[3]);
	rules->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		rules->count_of_eat = atoi(argv[5]);
}

int	create_data(t_data *data)
{
	data->time_start = get_time();
	data->pid = (pid_t *)
		malloc((data->rules->number_of_philosophers) * sizeof(pid_t));
	if (!data->pid)
		return (1);
	data->philos = (t_philo *)
		malloc((data->rules->number_of_philosophers) * sizeof(t_philo));
	if (!data->philos)
		return (1);
	return (0);
}

int	init_sem(t_data *data)
{
	unlink("philo_forks");
	unlink("print");
	unlink("status");
	unlink("status");
	data->forks = sem_open("philo_forks", O_CREAT, S_IRWXU,
			data->rules->number_of_philosophers);
	if (!data->forks)
		return (NULL);
	data->print = sem_open("philo_print", O_CREAT, S_IRWXU, 1);
	if (!data->print)
		return (NULL);
	data->status = sem_open("philo_status", O_CREAT, S_IRWXU, 1);
	if (!data->status)
		return (NULL);
	return (0);
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos->rules->number_of_philosophers)
	{
		data->philos[i].id = i + 1;
		data->philos[i].count_eat = 0;
		data->philos[i].rules = data->rules;
		data->philos[i].data = data;
		data->philos[i].last_time_eat = get_time();
		i++;
	}
}
