/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:47:53 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/07/11 20:57:25 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort(int **arrp, int size);
static int	binary_search_int(int *arr, int size, int target);

int	*coordinate_compress(int *input, int size)
{
	int	*ret;
	int	i;
	int	*iarr;

	iarr = malloc(size * sizeof(int));
	if (!iarr)
		return (NULL);
	ret = malloc(size * sizeof(int));
	if (!ret)
		return (free(iarr), NULL);
	ft_memcpy(iarr, input, size * sizeof(int));
	sort(&iarr, size);
	i = 0;
	while (i < size)
	{
		ret[i] = binary_search_int(iarr, size, input[i]);
		i++;
	}
	return (free(iarr), ret);
}

static void	sort(int **arrp, int size)
{
	int	*arr;
	int	is_updated;
	int	tmp;
	int	i;

	arr = *arrp;
	is_updated = 1;
	while (is_updated)
	{
		is_updated = 0;
		i = 0;
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
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] == target)
			return (mid);
		else if (target < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (-1);
}
