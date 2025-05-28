/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:40:52 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/05/26 22:48:16 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*ft_nodenew(int value)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (tmp)
	{
		tmp->value = value;
		tmp->next = NULL;
	}
	return (tmp);
}

int	ft_nodesize(t_node *node)
{
	int		cnt;
	t_node	*tmp;

	if (!node)
		return (0);
	cnt = 1;
	tmp = node;
	while (tmp->next)
	{
		tmp = tmp->next;
		cnt++;
	}
	return (cnt);
}

t_node	*ft_nodelast(t_node *node)
{
	t_node	*tmp;

	if (!node)
		return (NULL);
	tmp = node;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_nodeclear(t_node **node, void (*del)(void *))
{
	t_node	*last;

	last = ft_nodelast(*node);
	if (!last)
		return ;
	while (last->prev)
	{
		last = last->prev;
		del(last->next);
	}
	del(last);
}
