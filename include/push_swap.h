/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:52:50 by takawauc          #+#    #+#             */
/*   Updated: 2025/04/12 18:15:57 by TakeshiKawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ftprintf/include/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef enum e_operation
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}						t_operation;

typedef struct s_node	t_node;

struct					s_node
{
	int					index;
	t_node				*next;
	t_node				*prev;
};
typedef struct s_stack
{
	t_node				*head;
	t_node				*tail;
	int					size;
}						t_stack;

t_node					*ft_nodenew(int index);
int						ft_nodesize(t_node *node);
t_node					*ft_nodelast(t_node *ori);
void					ft_nodeclear(t_node **node, void (*del)(void *));

int						*compress(int *input, int size);
void					ft_free_stack(t_stack *stack);
#endif
