/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarr_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:09:26 by takawauc          #+#    #+#             */
/*   Updated: 2025/07/17 21:55:16 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_strarr_size(char **strarr)
{
	int	ret;

	ret = 0;
	while (strarr[ret])
		ret++;
	return (ret);
}

int	copy_strarr(char **source, char **dest, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = source[i];
		i++;
	}
	return (0);
}

void	*ft_free_allay(char **ret, size_t i)
{
	while (i > 0)
	{
		i--;
		free(ret[i]);
	}
	free(ret);
	return (NULL);
}
