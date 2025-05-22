/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:43:12 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/04/13 17:48:04 by TakeshiKawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	initialize_argv(char ***inputp);
t_stack	*get_input(char **argv, int argc);

void	put_operation(t_operation op);
t_stack	getinput(char **input);
void	resolve(t_stack *stack_a, t_stack *stack_b);
void	resolve_many_elements(t_stack *stack_a, t_stack *stack_b);
void	print_error(void);
int		*parse(char **strarr, int size);
void	resolve_3elements(t_stack *stack_a);
void	print_error(void);
void	resolve_many_elements(t_stack *stack_a, t_stack *stack_b);

int	main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv;
	int		argc;
	t_node	*node;

	// todebug
	argv = NULL;
	initialize_argv(&argv);
	argc = 10;
	stack_a = get_input(argv, argc);
	node = stack_a->head;
	while (node->next)
	{
		ft_printf("index: %d\n", node->index);
		node = node->next;
	}
	if (!stack_a)
	{
		print_error();
		return (1);
	}
	stack_b = malloc(sizeof(t_stack *));
	resolve(stack_a, stack_b);
	free(argv);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}

void	initialize_argv(char ***inputp)
{
	*inputp = malloc(sizeof(char *) * 10);
	(*inputp)[0] = ft_strdup("42");
	(*inputp)[1] = ft_strdup("1");
	(*inputp)[2] = ft_strdup("71");
	(*inputp)[3] = ft_strdup("32");
	(*inputp)[4] = ft_strdup("80");
	(*inputp)[5] = ft_strdup("1000");
	(*inputp)[6] = ft_strdup("92");
	(*inputp)[7] = ft_strdup("2");
	(*inputp)[8] = ft_strdup("65");
	(*inputp)[9] = ft_strdup("53");
}

t_stack	*get_input(char **argv, int argc)
{
	int		*compressed;
	t_stack	*ret;
	int		i;
	t_node	*tmp;

	ret = malloc(sizeof(t_stack *) * argc);
	compressed = compress(parse(argv, argc), argc);
	tmp = ft_nodenew(compressed[0]);
	ret->head = tmp;
	i = 1;
	while (i < argc)
	{
		tmp->next = ft_nodenew(compressed[i]);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	ret->tail = tmp->next;
	ret->size = ft_nodesize(ret->head);
	return (ret);
}

int	*parse(char **strarr, int size)
{
	int	i;
	int	*ret;

	ret = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		ret[i] = ft_atoi(strarr[i]);
		i++;
	}
	return (ret);
}

void	resolve(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->size;
	if (size == 1)
		return ;
	if (size == 2)
	{
		if (stack_a->head > stack_a->tail)
			ft_printf("sa\n");
		return ;
	}
	if (size == 3)
		resolve_3elements(stack_a);
	else
		resolve_many_elements(stack_a, stack_b);
}

void	resolve_3elements(t_stack *stack_a)
{
	int	first_index;
	int	second_index;
	int	third_index;

	first_index = stack_a->head->index;
	second_index = stack_a->head->next->index;
	third_index = stack_a->tail->index;
	if (first_index < second_index && second_index < third_index)
		return ;
	else if (first_index < third_index && third_index < second_index)
		ft_printf("sa\nra\n");
	else if (second_index < first_index && first_index < third_index)
		ft_printf("sa\nra\n");
	else if (first_index < third_index && third_index < second_index)
		ft_printf("sa\nra\n");
	else if (first_index < third_index && third_index < second_index)
		ft_printf("sa\nra\n");
	else if (first_index < third_index && third_index < second_index)
		ft_printf("sa\nra\n");
}

void	resolve_many_elements(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	ft_printf("run: resolve_many_elements");
}

void	print_error(void)
{
	ft_printf("error.");
}
