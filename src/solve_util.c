/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:14:47 by takawauc          #+#    #+#             */
/*   Updated: 2025/07/18 15:55:07 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <sys/wait.h>

void		push_to_sorted_stack(t_stack *stack_a, t_stack *stack_b, int cnt);
int			get_index_to_insert(t_stack stack, t_node *node);
int			get_top_index(t_stack stack);
static int	is_index_to_insert(int tailval, int headval, int val);

void	push_to_sorted_stack(t_stack *stack_a, t_stack *stack_b, int toins)
{
	int			i;
	t_operation	op;

	op = ra;
	if (2 * toins > ft_nodesize(stack_a->head))
	{
		op = rra;
		toins = ft_nodesize(stack_a->head) - toins;
	}
	i = 0;
	while (i < toins)
	{
		do_operation(stack_a, stack_b, op);
		i++;
	}
	do_operation(stack_a, stack_b, pa);
}

int	get_index_to_insert(t_stack stack, t_node *node)
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

static int	is_index_to_insert(int tailval, int headval, int val)
{
	return ((tailval < val && val < headval) || ((tailval < val
				|| headval > val) && (tailval > headval)));
}
