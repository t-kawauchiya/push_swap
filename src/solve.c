/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:14:47 by takawauc          #+#    #+#             */
/*   Updated: 2025/07/17 21:55:01 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	solver_for_3_elements(t_stack *stack_a);
static void	solver_for_5_or_less_elements(t_stack *stack_a, t_stack *stack_b);

void	solve(t_stack stack_a, t_stack stack_b)
{
	int	size;

	size = ft_nodesize(stack_a.head);
	if (size == 1)
		;
	else if (size == 2)
	{
		if (stack_a.head->value > stack_a.tail->value)
			ft_printf("sa\n");
	}
	else if (size == 3)
		solver_for_3_elements(&stack_a);
	else if (size <= 5)
		solver_for_5_or_less_elements(&stack_a, &stack_b);
	else
		radix_sort(stack_a, stack_b);
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
		;
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

static void	solver_for_5_or_less_elements(t_stack *stack_a, t_stack *stack_b)
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
