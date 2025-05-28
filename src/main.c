/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:43:12 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/05/27 23:34:59 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_exit(int status);
void	print_stack_elems(t_stack *stack);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = parse_input(argv, argc);
	if (!stack_a)
		error_exit(1);
	// print_stack_elems(stack_a);
	stack_b = malloc(sizeof(t_stack *));
	resolve(*stack_a, *stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}

void	error_exit(int status)
{
	write(2, "Error\n", 6);
	exit(status);
}

void	print_stack_elems(t_stack *stack)
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
