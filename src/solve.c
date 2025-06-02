/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:14:47 by takawauc          #+#    #+#             */
/*   Updated: 2025/06/03 01:12:06 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <sys/wait.h>

static void	solver_for_3_elements(t_stack *stack_a);
static void	solver_for_6_or_less_elements(t_stack *stack_a, t_stack *stack_b);
static void	solver_for_many_elements(t_stack stack_a, t_stack stack_b);
static int	get_index_to_insert(t_stack stack, t_node *node);

void	solve(t_stack stack_a, t_stack stack_b)
{
	int	size;

	size = ft_nodesize(stack_a.head);
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if (stack_a.head->value > stack_a.tail->value)
			ft_printf("sa\n");
		return ;
	}
	else if (size <= 6)
		solver_for_6_or_less_elements(&stack_a, &stack_b);
	else
		solver_for_many_elements(stack_a, stack_b);
}

static void	push_to_sorted_stack(t_stack *stack_a, t_stack *stack_b, int cnt)
{
	int			i;
	t_operation	op;

	op = ra;
	if (2 * cnt > ft_nodesize(stack_a->head))
	{
		op = rra;
		cnt = ft_nodesize(stack_a->head) - cnt;
	}
	i = 0;
	while (i < cnt)
	{
		do_operation(stack_a, stack_b, op);
		i++;
	}
	do_operation(stack_a, stack_b, pa);
}

int	get_top_index(t_stack stack)
{
	t_node	*tmp;
	int		ret;

	ret = 0;
	if (stack.head < stack.tail)
		return (0);
	tmp = stack.head;
	while (tmp)
	{
		ret++;
		if (tmp->value > tmp->next->value)
			return (ret);
		tmp = tmp->next;
	}
	return (-1);
}

static void	solver_for_6_or_less_elements(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	int		cnt;

	if (is_sorted(*stack_a))
		return ;
	while (ft_nodesize(stack_a->head) > 3)
		do_operation(stack_a, stack_b, pb);
	solver_for_3_elements(stack_a);
	while (ft_nodesize(stack_b->head))
	{
		tmp = stack_b->head;
		cnt = get_index_to_insert(*stack_a, tmp);
		push_to_sorted_stack(stack_a, stack_b, cnt);
	}
	if (2 * get_top_index(*stack_a) > ft_nodesize(stack_a->head))
		while (!is_sorted(*stack_a))
			do_operation(stack_a, stack_b, rra);
	else
		while (!is_sorted(*stack_a))
			do_operation(stack_a, stack_b, ra);
}

static int	is_index_to_insert(int tailval, int headval, int val)
{
	return ((tailval < val && val < headval) || ((tailval < val
				|| headval > val) && (tailval > headval)));
}

static int	get_index_to_insert(t_stack stack, t_node *node)
{
	t_node	*head;
	t_node	*tail;
	int		ret;
	int		size;

	size = ft_nodesize(stack.head);
	ret = 0;
	head = stack.head;
	tail = stack.tail;
	while (ret < size && !is_index_to_insert(tail->value, head->value,
			node->value))
	{
		if (!head->next)
			head = stack.head;
		else
			head = head->next;
		if (!head->prev)
			tail = stack.tail;
		else
			tail = head->prev;
		ret++;
	}
	return (ret);
}

static void	solver_for_3_elements(t_stack *stack_a)
{
	int	first_value;
	int	second_value;
	int	third_value;

	first_value = stack_a->head->value;
	second_value = stack_a->head->next->value;
	third_value = stack_a->tail->value;
	if (first_value < second_value && second_value < third_value)
		return ;
	else if (first_value < third_value && third_value < second_value)
	{
		do_operation(stack_a, NULL, sa);
		do_operation(stack_a, NULL, ra);
	}
	else if (second_value < first_value && first_value < third_value)
		do_operation(stack_a, NULL, sa);
	else if (second_value < third_value && third_value < first_value)
		do_operation(stack_a, NULL, ra);
	else if (third_value < second_value && second_value < first_value)
	{
		do_operation(stack_a, NULL, sa);
		do_operation(stack_a, NULL, rra);
	}
	else if (third_value < first_value && first_value < second_value)
		do_operation(stack_a, NULL, rra);
}

static void	solver_for_many_elements(t_stack sa, t_stack sb)
{
	if (!is_sorted(sa))
		radix_sort(sa, sb);
}
