/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:52:50 by takawauc          #+#    #+#             */
/*   Updated: 2025/07/17 21:11:20 by takawauc         ###   ########.fr       */
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
	int					value;
	t_node				*next;
	t_node				*prev;
};

typedef struct s_stack
{
	t_node				*head;
	t_node				*tail;
}						t_stack;

t_stack					*parse_input(char **argv);

t_node					*ft_nodenew(int index);
int						ft_nodesize(t_node *node);
t_node					*ft_nodelast(t_node *ori);
void					ft_nodeclear(t_node **node, void (*del)(void *));
void					ft_stackaddhead(t_stack *stack, t_node *node);
void					ft_stackaddtail(t_stack *stack, t_node *node);
t_node					*ft_stackpophead(t_stack *stack);
t_node					*ft_stackpoptail(t_stack *stack);
void					ft_free_stack(t_stack *stack);

void					do_operation(t_stack *stack_a, t_stack *stack_b,
							t_operation op);

char					**expand_args(char **argv);

void					solve(t_stack stack_a, t_stack stack_b);

int						*coordinate_compress(int *input, int size);

void					error_exit(int status);
int						is_sorted(t_stack sa);

void					radix_sort(t_stack sa, t_stack sb);

void					print_stack_elems(t_stack *stack);
void					push_to_sorted_stack(t_stack *stack_a, t_stack *stack_b,
							int cnt);
int						get_index_to_insert(t_stack stack, t_node *node);
int						get_top_index(t_stack stack);

// strarr_util
int						get_strarr_size(char **strarr);
int						copy_strarr(char **source, char **dest, int size);
void					*ft_free_allay(char **ret, size_t i);

#endif
