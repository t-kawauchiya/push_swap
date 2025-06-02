/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:47:53 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/06/02 12:41:33 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort(int **arrp, int size);
static int	binary_search_int(int *arr, int size, int target);

int	*coordinate_compress(int *input, int size)
{
	int	*ret;
	int	i;
	int	*cp;

	cp = malloc(size * sizeof(int));
	if (!cp)
		return (NULL);
	ft_memcpy(cp, input, size * sizeof(int));
	sort(&cp, size);
	ret = malloc(size * sizeof(int));
	if (!ret)
	{
		free(cp);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		ret[i] = binary_search_int(cp, size, input[i]);
		i++;
	}
	free(cp);
	return (ret);
}

static void	sort(int **arrp, int size)
{
	int	*arr;
	int	i;
	int	tmp;
	int	is_updated;

	arr = *arrp;
	is_updated = 1;
	while (is_updated)
	{
		i = 0;
		is_updated = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				is_updated = 1;
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
