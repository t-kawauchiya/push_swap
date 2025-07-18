/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:40:52 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/07/17 15:04:15 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*ft_nodenew(int value)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
		return (NULL);
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

int	ft_nodesize(t_node *node)
{
	int		size;
	t_node	*cur;

	cur = node;
	size = 0;
	while (cur)
	{
		cur = cur->next;
		size++;
	}
	return (size);
}

t_node	*ft_nodelast(t_node *node)
{
	t_node	*tmp;

	if (!node)
		return (NULL);
	tmp = node;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_nodeclear(t_node **node, void (*del)(void *))
{
	t_node	*cur;
	t_node	*next;

	if (!node || !del)
		return ;
	cur = *node;
	while (cur)
	{
		next = cur->next;
		del(cur);
		cur = next;
	}
}

int	ft_getmaxvalue(t_node *node)
{
	int		max;
	t_node	*tmp;

	max = INT_MIN;
	tmp = node;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}
