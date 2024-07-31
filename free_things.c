/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:56:36 by araveala          #+#    #+#             */
/*   Updated: 2024/07/31 12:21:30 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_things(t_data *data, int step, int i, int x)
{
	if (step > 0)
	{
		while (--i >= 0)
			pthread_mutex_destroy(&data->main_fork_lock[i]);
		if (step > 1)
			pthread_mutex_destroy(&data->ultima);
		if (step > 2)
			pthread_mutex_destroy(&data->death_lock);
		free(data->main_fork_lock);
		if (step > 3)
		{
			while (--x >= 0)
				pthread_mutex_destroy(&data->philo[x].meal_lock);
		}
		if (step > 4)
		{
			free(data->philo);
			free(data);
		}
	}
	return (1);
}

/*void	free_mutex(t_data *data)
{
	pthread_mutex_destroy(data->main_fork_lock);
	pthread_mutex_destroy(&data->philo->meal_lock);
	pthread_mutex_destroy(&data->ultima);
	pthread_mutex_destroy(&data->death_lock);
	}*/

/*void	free_all(t_data *data)
{
//	free_mutex(data);
//	free(data->main_fork_lock);
	destroy_things(data, 4, data->num_of_philos, data->num_of_philos);
	free(data->philo);
	free(data);
	}*/
