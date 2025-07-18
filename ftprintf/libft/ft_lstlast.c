/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:27:17 by takawauc          #+#    #+#             */
/*   Updated: 2025/05/16 16:30:06 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *node)
{
	t_list	*tmp;

	tmp = node;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
