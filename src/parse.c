/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:25:39 by takawauc          #+#    #+#             */
/*   Updated: 2025/05/26 17:51:18 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	*args_to_i(char **strarr, int size);

static int	is_valid_int(char *str);
static int	is_duplicated(int *intarr, int size);

t_stack	*parse_input(char **argv, int argc)
{
	int		*compressed;
	t_stack	*ret;
	int		i;
	t_node	*tmp;

	ret = malloc(sizeof(t_stack *));
	if (!ret)
		return (NULL);
	compressed = coordinate_compress(args_to_i(argv + 1, argc - 1), argc - 1);
	tmp = ft_nodenew(compressed[0]);
	ret->head = tmp;
	i = 1;
	while (i < argc - 1)
	{
		tmp->next = ft_nodenew(compressed[i]);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	ret->tail = tmp;
	ret->size = ft_nodesize(ret->head);
	free(compressed);
	return (ret);
}

static int	*args_to_i(char **strarr, int size)
{
	int		i;
	int		*ret;
	long	element;

	ret = malloc(sizeof(int) * size);
	if (!ret)
		error_exit(2);
	i = 0;
	while (i < size)
	{
		if (!is_valid_int(strarr[i]))
			error_exit(1);
		element = ft_atol(strarr[i]);
		if (element < INT_MIN || INT_MAX < element)
			error_exit(1);
		ret[i] = (int)element;
		i++;
	}
	if (is_duplicated(ret, size))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

static int	is_valid_int(char *str)
{
	int	has_dot;

	has_dot = 0;
	while (*str)
	{
		if (*str == '.')
		{
			if (has_dot)
				return (0);
			has_dot++;
		}
		else if (*str < '0' || '9' < *str)
			return (0);
		str++;
	}
	return (1);
}

static int	is_duplicated(int *intarr, int size)
{
	int	i;
	int	j;

	if (!intarr)
		return (0);
	i = 0;
	while (i < size - 2)
	{
		j = i + 1;
		while (j < size - 1)
		{
			if (intarr[i] == intarr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
