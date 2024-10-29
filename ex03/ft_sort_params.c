/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:36:43 by jhyokki           #+#    #+#             */
/*   Updated: 2024/09/19 17:12:52 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);
void	quicksort(char *arr[], int low, int high);

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		quicksort(argv, 1, argc - 1);
		while (--argc > 0)
		{
			argv++;
			while (**argv)
			{
				write(1, *argv, 1);
				(*argv)++;
			}
			write(1, "\n", 1);
		}
	}
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *str, char *t)
{
	while (*str && (*str == *t))
	{
		str++;
		t++;
	}
	return (*str - *t);
}

int	partition(char *arr[], int low, int high)
{
	char	*pivot;
	int		i;
	int		j;

	pivot = arr[high];
	i = low -1;
	j = low;
	while (j < high)
	{
		if (ft_strcmp(arr[j], pivot) < 0)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quicksort(char *arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}
