/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:35:49 by takawauc          #+#    #+#             */
/*   Updated: 2025/07/17 21:18:03 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char		**expand_args(char **argv);
static char	**split_with_spaces(const char *s);
static int	count_words(const char *str);
static int	count_all_words(char **argv);
static char	*get_word(const char *str);

char	**expand_args(char **argv)
{
	int		size;
	char	**ret;
	char	**args;
	char	**cur;
	int		argssize;

	size = count_all_words(argv);
	ret = malloc((size + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[size] = NULL;
	cur = ret;
	while (*argv && *argv[0])
	{
		args = split_with_spaces(*argv);
		if (!args)
			return (free(ret), NULL);
		argssize = get_strarr_size(args);
		copy_strarr(args, cur, argssize);
		cur += argssize;
		free(args);
		argv++;
	}
	return (ret);
}

static char	**split_with_spaces(const char *str)
{
	int		i;
	int		size;
	char	**ret;

	i = 0;
	if (!str)
		return (NULL);
	size = count_words(str);
	ret = (char **)malloc((size + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[size] = NULL;
	while (*str)
	{
		if (!ft_isspace(*str))
		{
			ret[i] = get_word(str);
			if (!ret[i])
				return (ft_free_allay(ret, i), NULL);
			str += ft_strlen(ret[i++]);
		}
		else
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

static int	count_all_words(char **argv)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (argv[i])
		ret += count_words(argv[i++]);
	return (ret);
}

static int	count_words(const char *str)
{
	int	ret;

	ret = 0;
	if (!str)
		return (ret);
	if (!ft_isspace(*str))
		ret++;
	while (*str && *(str + 1))
	{
		if (ft_isspace(*str) && !ft_isspace(*(str + 1)))
			ret++;
		str++;
	}
	return (ret);
}
