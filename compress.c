/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:47:53 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/04/13 17:27:57 by TakeshiKawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	sort(int **arrp, int size);
static int	binary_search_int(int *arr, int size, int target);

int	*compress(int *input, int size)
{
	int	*ret;
	int	i;
	int	*cp;

	cp = malloc(size * sizeof(int));
	ft_memcpy(cp, input, size * sizeof(int));
	sort(&cp, size);
	ret = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		ret[i] = binary_search_int(cp, size, input[i]);
		i++;
	}
	return (ret);
}

static void	sort(int **arrp, int size)
{
	int	*arr;
	int	i;
	int	tmp;
	int	updated;

	arr = *arrp;
	updated = 1;
	while (updated)
	{
		i = 0;
		updated = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				updated = 1;
			}
			i++;
		}
	}
}

static int	binary_search_int(int *arr, int size, int target)
{
	int	min;
	int	max;
	int	mid;

	min = 0;
	max = size - 1;
	while (min <= max)
	{
		mid = min + (max - min) / 2;
		if (arr[mid] == target)
			return (mid);
		else if (target < arr[mid])
			max = mid - 1;
		else
			min = mid + 1;
	}
	return (-1);
}
