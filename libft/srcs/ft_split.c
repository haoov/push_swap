/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:34:13 by rsabbah           #+#    #+#             */
/*   Updated: 2022/11/09 15:05:46 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getwnb(char const *s, char c)
{
	int		wnb;
	int		i;

	i = 0;
	wnb = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			wnb++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (wnb);
}

static size_t	ft_getwlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**ft_filltab(char **tab, char const *s, char c, int wnb)
{
	size_t		wlen;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < wnb)
	{
		while (s[j] == c)
			j++;
		wlen = ft_getwlen(s + j, c);
		tab[i] = ft_substr(s, j, wlen);
		if (tab[i] == NULL)
		{
			while (--i >= 0)
				free(tab[i]);
			free(tab);
			return (NULL);
		}
		i++;
		j += wlen;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		wnb;

	if (s == NULL)
		return (NULL);
	wnb = ft_getwnb(s, c);
	tab = (char **)malloc(sizeof (char *) * (wnb + 1));
	if (tab == NULL)
		return (NULL);
	tab = ft_filltab(tab, s, c, wnb);
	if (tab == NULL)
		return (free(tab), NULL);
	return (tab);
}
