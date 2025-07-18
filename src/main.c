/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:43:12 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/07/17 15:32:49 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_exit(int status);
void	debug_print_stack_elems(t_stack *stack);
int		is_sorted(t_stack sa);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = parse_input(argv);
	if (!stack_a)
		error_exit(1);
	stack_b = malloc(sizeof(t_stack *));
	if (!stack_b)
	{
		ft_free_stack(stack_a);
		error_exit(1);
	}
	solve(*stack_a, *stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}

void	error_exit(int status)
{
	write(2, "Error\n", 6);
	exit(status);
}

void	debug_print_stack_elems(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	ft_printf("print_stack_elem: ");
	while (tmp)
	{
		ft_printf("%d,", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int	is_sorted(t_stack stack)
{
	t_node	*tmp;

	tmp = stack.head;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
