/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:25:39 by takawauc          #+#    #+#             */
/*   Updated: 2025/05/28 15:18:41 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	*get_conpressed_iarr(char **strarr, int size);
static int	*safe_atoi(char *str);
static int	iarr_contains(int *iarr, int size, int ip);

t_stack	*parse_input(char **argv, int argc)
{
	int		*iarr;
	t_stack	*ret;
	int		i;
	t_node	*tmp;

	iarr = get_conpressed_iarr(argv + 1, argc - 1);
	if (!iarr)
		return (NULL);
	ret = malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	tmp = ft_nodenew(iarr[0]);
	ret->head = tmp;
	i = 1;
	while (i < argc - 1)
	{
		tmp->next = ft_nodenew(iarr[i]);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	ret->tail = tmp;
	free(iarr);
	return (ret);
}

static int	*get_conpressed_iarr(char **strarr, int size)
{
	int	i;
	int	*compressed;
	int	*iarr;
	int	*ip;

	iarr = malloc(size * sizeof(int));
	if (!iarr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ip = safe_atoi(strarr[i]);
		if (!ip || iarr_contains(iarr, i, *ip))
		{
			if (ip)
				free(ip);
			free(iarr);
			return (NULL);
		}
		iarr[i++] = *ip;
		free(ip);
	}
	compressed = coordinate_compress(iarr, size);
	free(iarr);
	return (compressed);
}

static int	*safe_atoi(char *str)
{
	int	*ret;
	int	val;
	int	i;

	if (!str || ft_strlen(str) > 11)
		return (NULL);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
			return (NULL);
		i++;
	}
	val = ft_atol(str);
	if (val < INT_MIN || INT_MAX < val)
		return (NULL);
	ret = malloc(sizeof(int));
	if (!ret)
		return (NULL);
	*ret = val;
	return (ret);
}

static int	iarr_contains(int *iarr, int size, int elem)
{
	int	i;

	if (!iarr)
		return (0);
	i = 0;
	while (i < size)
	{
		if (iarr[i] == elem)
			return (1);
		i++;
	}
	return (0);
}
