/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 11:06:30 by plam              #+#    #+#             */
/*   Updated: 2020/01/04 15:53:54 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count_prints(char const *s, char c)
{
	size_t	i;
	int		p;

	i = 0;
	p = 0;
	while (s && s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			p++;
		i++;
	}
	return (p);
}

static char	**free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static int	print_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**tab;

	if (!(tab = malloc(sizeof(*tab) * (count_prints(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (s && s[k])
	{
		while (s[k] == c)
			k++;
		if (!(tab[i] = malloc(sizeof(char) * (print_len(&s[k], c) + 1))))
			free_tab(tab);
		if (s[k])
		{
			j = 0;
			while (s[k] && s[k] != c)
				tab[i][j++] = s[k++];
			tab[i++][j] = '\0';
		}
	}
	tab[i] = NULL;
	return (tab);
}
