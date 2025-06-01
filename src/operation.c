/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:15:48 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/06/01 09:46:50 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	print_operation(t_operation op);
static void	swap(t_stack *stack);
static void	rotate(t_stack *stack, int is_reverse);
static void	push(t_stack *stacka, t_stack *stackb);

void	do_operation(t_stack *stack_a, t_stack *stack_b, t_operation op)
{
	// ft_printf("sa:");
	// print_stack_elems(stack_a);
	// ft_printf("sb:");
	// print_stack_elems(stack_b);
	print_operation(op);
	if (op == sa || op == ss)
		swap(stack_a);
	if (op == sb || op == ss)
		swap(stack_b);
	if (op == ra || op == rr)
		rotate(stack_a, 0);
	if (op == rb || op == rr)
		rotate(stack_b, 0);
	if (op == rra || op == rrr)
		rotate(stack_a, 1);
	if (op == rrb || op == rrr)
		rotate(stack_b, 1);
	if (op == pa)
		push(stack_b, stack_a);
	if (op == pb)
		push(stack_a, stack_b);
}

static void	print_operation(t_operation op)
{
	if (op == sa)
		ft_printf("sa\n");
	else if (op == sb)
		ft_printf("sb\n");
	else if (op == ss)
		ft_printf("ss\n");
	else if (op == ra)
		ft_printf("ra\n");
	else if (op == rb)
		ft_printf("rb\n");
	else if (op == rr)
		ft_printf("rr\n");
	else if (op == rra)
		ft_printf("rra\n");
	else if (op == rrb)
		ft_printf("rrb\n");
	else if (op == rrr)
		ft_printf("rrr\n");
	else if (op == pa)
		ft_printf("pa\n");
	else if (op == pb)
		ft_printf("pb\n");
	return ;
}

static void	push(t_stack *stacka, t_stack *stackb)
{
	t_node	*pushed;

	pushed = ft_stackpophead(stacka);
	ft_stackaddhead(stackb, pushed);
}

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	first = ft_stackpophead(stack);
	second = ft_stackpophead(stack);
	ft_stackaddhead(stack, first);
	ft_stackaddhead(stack, second);
}

static void	rotate(t_stack *stack, int is_reverse)
{
	t_node	*poped;

	if (is_reverse)
	{
		poped = ft_stackpoptail(stack);
		ft_stackaddhead(stack, poped);
	}
	else
	{
		poped = ft_stackpophead(stack);
		ft_stackaddtail(stack, poped);
	}
}
