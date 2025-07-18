/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:40:52 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/07/17 16:36:37 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_stack(t_stack *stack) // tofix
{
	if (stack)
	{
		ft_nodeclear(&stack->head, free);
		free(stack);
	}
}

void	ft_stackaddhead(t_stack *stack, t_node *node)
{
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		stack->head->prev = node;
		node->next = stack->head;
		stack->head = node;
	}
}

void	ft_stackaddtail(t_stack *stack, t_node *node)
{
	if (!stack->tail)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		stack->tail->next = node;
		node->prev = stack->tail;
		stack->tail = node;
	}
}

t_node	*ft_stackpophead(t_stack *stack)
{
	t_node	*ret;

	ret = stack->head;
	if (stack->head->next == NULL)
	{
		stack->head = NULL;
		stack->tail = NULL;
		return (ret);
	}
	stack->head->next->prev = NULL;
	stack->head = stack->head->next;
	ret->next = NULL;
	return (ret);
}

t_node	*ft_stackpoptail(t_stack *stack)
{
	t_node	*ret;

	ret = stack->tail;
	if (stack->head->next == NULL)
	{
		stack->head = NULL;
		stack->tail = NULL;
		return (ret);
	}
	stack->tail->prev->next = NULL;
	stack->tail = stack->tail->prev;
	ret->prev = NULL;
	return (ret);
}
