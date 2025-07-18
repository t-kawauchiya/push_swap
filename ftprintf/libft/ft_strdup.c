/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 02:27:49 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/07/10 00:24:36 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	slen;
	char	*result;
	size_t	i;

	slen = ft_strlen(str);
	result = (char *)malloc((slen + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strndup(const char *str, size_t n)
{
	size_t	slen;
	char	*result;
	size_t	i;

	slen = ft_strlen(str);
	if (slen > n)
		slen = n;
	result = (char *)malloc((slen + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[slen] = '\0';
	i = 0;
	while (i < slen)
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}
