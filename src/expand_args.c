/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:35:49 by takawauc          #+#    #+#             */
/*   Updated: 2025/05/30 16:54:52 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char		**expand_args(char **argv);
static int	count_words(char *str);
static char	**get_expanded_args(char **argv, int size);

char	**expand_args(char **argv)
{
	int	i;
	int	arrlen;

	arrlen = 0;
	i = 0;
	while (argv[i])
		arrlen += count_words(argv[i++]);
	return (get_expanded_args(argv, arrlen));
}

static char	**get_expanded_args(char **argv, int size)
{
	int		i;
	int		cnt;
	char	**ret;
	char	**strarr;

	ret = malloc((size + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[size] = NULL;
	cnt = 0;
	while (*argv && *argv[0])
	{
		strarr = split_with_spaces(*argv);
		if (!strarr)
		{
			free(ret);
			return (NULL);
		}
		i = 0;
		while (strarr[i])
			ret[cnt++] = strarr[i++];
		argv++;
		free(strarr);
	}
	return (ret);
}

static int	count_words(char *str)
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
