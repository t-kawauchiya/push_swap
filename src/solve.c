/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:14:47 by takawauc          #+#    #+#             */
/*   Updated: 2025/06/01 12:41:41 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	solve_3elements(t_stack stack_a);
static void	solve_many_elements(t_stack stack_a, t_stack stack_b);

void	solve(t_stack stack_a, t_stack stack_b)
{
	int	size;

	size = ft_nodesize(stack_a.head);
	if (size == 1)
		return ;
	if (size == 2)
	{
		if (stack_a.head->value > stack_a.tail->value)
			ft_printf("sa\n");
		return ;
	}
	if (size == 3)
		solve_3elements(stack_a);
	else
		solve_many_elements(stack_a, stack_b);
}

static void	solve_3elements(t_stack stack_a)
{
	int	first_value;
	int	second_value;
	int	third_value;

	first_value = stack_a.head->value;
	second_value = stack_a.head->next->value;
	third_value = stack_a.tail->value;
	if (first_value < second_value && second_value < third_value)
		return ;
	else if (first_value < third_value && third_value < second_value)
		ft_printf("sa\nra\n");
	else if (second_value < first_value && first_value < third_value)
		ft_printf("sa\n");
	else if (second_value < third_value && third_value < first_value)
		ft_printf("ra\n");
	else if (third_value < second_value && second_value < first_value)
		ft_printf("sa\nrra\n");
	else if (third_value < first_value && first_value < second_value)
		ft_printf("rra\n");
}

static void	solve_many_elements(t_stack sa, t_stack sb)
{
	if (!is_sorted(sa))
		radix_sort(sa, sb);
}
