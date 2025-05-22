/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:15:48 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/04/12 20:43:38 by TakeshiKawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	swap(t_stack stack);
static void	rotate(t_stack stack);
static void	rrotate(t_stack stack);
static void	push(t_stack stacka, t_stack stackb);

void	operation(t_stack stack_a, t_stack stack_b, char *op)
{
	ft_putendl_fd(op, STDOUT_FILENO);
	if (ft_strncmp(op, "sa", 2))
		swap(stack_a);
	else if (ft_strncmp(op, "sb", 2))
		swap(stack_b);
	else if (ft_strncmp(op, "ss", 2))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (ft_strncmp(op, "pa", 2))
		push(stack_a, stack_b);
	else if (ft_strncmp(op, "pb", 2))
		push(stack_b, stack_a);
	else if (ft_strncmp(op, "ra", 2))
		rotate(stack_a);
	else if (ft_strncmp(op, "rb", 2))
		rotate(stack_b);
	else if (ft_strncmp(op, "rr", 2))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strncmp(op, "rra", 3))
		rrotate(stack_a);
	else if (ft_strncmp(op, "rrb", 3))
		rrotate(stack_b);
	else if (ft_strncmp(op, "rrr", 3))
	{
		rrotate(stack_a);
		rrotate(stack_b);
	}
}

static void	push(t_stack stacka, t_stack stackb)
{
	t_node	*heada;
	t_node	*headb;
	t_node	*secondb;
	t_node	*tmp;

	heada = stacka.head;
	headb = stackb.head;
	secondb = stackb.head->next;
	headb->next = heada;
	heada->prev = headb;
	secondb->prev = NULL;
	stacka.head = headb;
	stackb.head = secondb;
	stacka.head->index = 0;
	stacka.size++;
	stackb.size--;
	tmp = stacka.head->next;
	while (tmp->next)
	{
		tmp->index++;
		tmp = tmp->next;
	}
	tmp = stackb.head;
	while (tmp->next)
	{
		tmp->index--;
		tmp = tmp->next;
	}
}

static void	rrotate(t_stack stack)
{
	t_node	*first;
	t_node	*seclast;
	t_node	*last;
	t_node	*tmp;

	first = stack.head;
	seclast = stack.head->next;
	last = stack.tail;
	first->prev = last;
	seclast->next = NULL;
	last->next = first;
	last->prev = NULL;
	stack.head = last;
	stack.tail = seclast;
	stack.head->index = 0;
	tmp = stack.head->next;
	while (tmp->next)
	{
		tmp->index++;
		tmp = tmp->next;
	}
}
static void	rotate(t_stack stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;
	t_node	*tmp;

	first = stack.head;
	second = stack.head->next;
	last = stack.tail;
	first->next = NULL;
	first->prev = last;
	second->prev = NULL;
	last->next = first;
	stack.head = second;
	stack.tail = first;
	tmp = stack.head;
	while (tmp->next)
	{
		tmp->index--;
		tmp = tmp->next;
	}
	stack.tail->index = stack.size - 1;
}

static void	swap(t_stack stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack.head;
	second = stack.head->next;
	third = stack.head->next->next;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	third->prev = first;
	stack.head = second;
	// todo update index
}
