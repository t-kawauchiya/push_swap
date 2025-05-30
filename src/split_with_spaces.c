/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_with_spaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:19:26 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/05/30 16:49:48 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	count_words(const char *s);
static void	*ft_free_allay(char **ret, size_t i);
static char	*get_word(const char *str);

char	**split_with_spaces(const char *s)
{
	int		i;
	char	**ret;

	if (!s)
		return (NULL);
	ret = (char **)malloc((count_words(s) + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[count_words(s)] = NULL;
	i = 0;
	while (*s)
	{
		if (!ft_isspace(*s))
		{
			ret[i] = get_word(s);
			if (!ret[i])
				return (ft_free_allay(ret, i));
			s += ft_strlen(ret[i]);
			i++;
		}
		else
			s++;
	}
	return (ret);
}

static int	count_words(const char *str)
{
	int	ret;

	ret = 0;
	if (!str)
		return (ret);
	if (*str)
		ret++;
	while (*str && *(str + 1))
	{
		if (ft_isspace(*str) && !ft_isspace(*(str + 1)))
			ret++;
		str++;
	}
	return (ret);
}

static char	*get_word(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (NULL);
	while (str[len] && !ft_isspace(str[len]))
		len++;
	return (ft_substr(str, 0, len));
}

static void	*ft_free_allay(char **ret, size_t i)
{
	while (i > 0)
	{
		i--;
		free(ret[i]);
	}
	free(ret);
	return (NULL);
}
