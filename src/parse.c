/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:25:39 by takawauc          #+#    #+#             */
/*   Updated: 2025/06/01 09:45:24 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int		*get_conpressed_iarr(char **strarr, int size);
static int		*safe_atoi(char *str);
static int		iarr_contains(int *iarr, int size, int ip);
static t_stack	*conv_iarr_to_stack(int *iarr, int size);

t_stack	*parse_input(char **argv)
{
	int		*iarr;
	t_stack	*ret;
	char	**expanded_argv;
	int		expanded_argc;

	expanded_argv = expand_args(argv + 1);
	expanded_argc = 0;
	while (expanded_argv[expanded_argc])
		expanded_argc++;
	iarr = get_conpressed_iarr(expanded_argv, expanded_argc);
	if (!iarr)
		return (NULL);
	ret = conv_iarr_to_stack(iarr, expanded_argc);
	free(expanded_argv);
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

static t_stack	*conv_iarr_to_stack(int *iarr, int size)
{
	t_stack	*ret;
	t_node	*tmp;
	int		i;

	ret = malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	tmp = ft_nodenew(iarr[0]);
	ret->head = tmp;
	i = 1;
	while (i < size)
	{
		tmp->next = ft_nodenew(iarr[i]);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	ret->tail = tmp;
	return (ret);
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
