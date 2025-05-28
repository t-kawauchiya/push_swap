/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:15:48 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/05/27 00:11:01 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack stack);
static void	rotate(t_stack stack);
static void	rrotate(t_stack stack);
static void	push(t_stack stacka, t_stack stackb);

void	do_operation(t_stack stack_a, t_stack stack_b, char *op)
{
	ft_putendl_fd(op, STDOUT_FILENO);
	if (ft_strncmp(op, "sa", 2) || ft_strncmp(op, "ss", 2))
		swap(stack_a);
	if (ft_strncmp(op, "sb", 2) || ft_strncmp(op, "ss", 2))
		swap(stack_b);
	if (ft_strncmp(op, "ra", 2) || ft_strncmp(op, "rr", 2))
		rotate(stack_a);
	if (ft_strncmp(op, "rb", 2) || ft_strncmp(op, "rr", 2))
		rotate(stack_b);
	if (ft_strncmp(op, "rra", 3) || ft_strncmp(op, "rrr", 3))
		rrotate(stack_a);
	if (ft_strncmp(op, "rrb", 3) || ft_strncmp(op, "rrr", 3))
		rrotate(stack_b);
	if (ft_strncmp(op, "pa", 2))
		push(stack_a, stack_b);
	if (ft_strncmp(op, "pb", 2))
		push(stack_b, stack_a);
}

static void	push(t_stack stacka, t_stack stackb)
{
	t_node	*pushed;

	pushed = stacka.head;
	stacka.head = stacka.head->next;
	stackb.head->prev = pushed;
	pushed->next = stackb.head;
	stackb.head = pushed;
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
}

static void	rotate(t_stack stack)
{
	t_node	*poped;

	poped = stack.head;
	stack.head->next->prev = NULL;
	stack.tail->next = poped;
	poped->prev = stack.tail;
	stack.tail = poped;
	stack.tail->next = NULL;
}

static void	rrotate(t_stack stack)
{
	t_node	*poped;

	poped = stack.tail;
	stack.tail->prev->next = NULL;
	stack.head->prev = poped;
	poped->next = stack.head;
	stack.head = poped;
	stack.head->prev = NULL;
}
