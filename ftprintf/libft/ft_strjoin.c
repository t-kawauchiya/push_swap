/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:33:14 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/07/10 00:25:31 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*rettop;
	size_t	s1len;
	size_t	s2len;

	s1len = 0;
	s2len = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		s1len = ft_strlen(s1);
	if (s2)
		s2len = ft_strlen(s2);
	ret = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	rettop = ret;
	while (s1 && *s1)
		*ret++ = *s1++;
	while (s2 && *s2)
		*ret++ = *s2++;
	*ret = '\0';
	return (rettop);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*ret;
	size_t	i;
	size_t	s1len;
	size_t	retlen;

	retlen = 0;
	s1len = ft_strlen(s1);
	retlen = s1len + ft_strlen(s2);
	if (retlen > n)
		retlen = n;
	ret = (char *)malloc((retlen + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[retlen] = '\0';
	i = 0;
	while (i < retlen)
	{
		if (i < s1len)
			ret[i] = s1[i];
		else
			ret[i] = s2[i - s1len];
		i++;
	}
	return (ret);
}
