/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:20:53 by takawauc          #+#    #+#             */
/*   Updated: 2025/06/01 12:53:10 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	distribute_by_digit(t_stack *sa, t_stack *sb, int digit_pos);
void	collect_to_stack(t_stack *sa, t_stack *sb);

void	radix_sort(t_stack sa, t_stack sb)
{
	int	i;

	i = 0;
	while (!is_sorted(sa))
	{
		distribute_by_digit(&sa, &sb, i);
		collect_to_stack(&sa, &sb);
		i++;
	}
}

void	distribute_by_digit(t_stack *sa, t_stack *sb, int digit_pos)
{
	int	i;
	int	itermax;

	itermax = ft_stacksize(*sa);
	i = 0;
	while (i < itermax)
	{
		if (!(sa->head->value & 1 << digit_pos))
			do_operation(sa, sb, pb);
		else
			do_operation(sa, sb, ra);
		i++;
	}
}

void	collect_to_stack(t_stack *sa, t_stack *sb)
{
	while (sb->head)
	{
		do_operation(sa, sb, pa);
	}
}
