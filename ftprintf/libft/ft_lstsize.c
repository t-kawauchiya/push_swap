/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwauc <takawauc@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:03:16 by takwauc           #+#    #+#             */
/*   Updated: 2025/05/17 18:05:52 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *node)
{
	int	size;

	if (!node)
		return (0);
	size = 1;
	while (node->next)
	{
		size++;
		node = node->next;
	}
	return (size);
}
