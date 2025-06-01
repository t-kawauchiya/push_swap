/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:40:52 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/06/01 12:51:44 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	if (stack)
	{
    ft_nodeclear(&(stack->head),free);
		ft_nodeclear(&stack->head, free);
		free(stack);
	}
}

int	ft_stacksize(t_stack stack)
{
	return (ft_nodesize(stack.head));
}

void	ft_stackaddhead(t_stack *stack, t_node *node)
{
	int	stsize;

	stsize = ft_stacksize(*stack);
	if (stsize == 0)
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
	int	stsize;

	stsize = ft_stacksize(*stack);
	if (stsize == 0)
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
	if (ft_stacksize(*stack) == 1)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
	}
	ret->next = NULL;
	return (ret);
}

t_node	*ft_stackpoptail(t_stack *stack)
{
	t_node	*ret;

	ret = stack->tail;
	if (ft_stacksize(*stack) == 1)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
	}
	ret->prev = NULL;
	return (ret);
}
