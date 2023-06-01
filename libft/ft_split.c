/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:24:56 by erivero-          #+#    #+#             */
/*   Updated: 2023/05/01 16:29:21 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_cutre(const char *s, char c)
{
	int	cuts;

	cuts = 0;
	while (*s)
	{
		if (*s != c)
		{
			cuts++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (cuts);
}

static int	ft_sublen(const char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	subs = malloc ((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start];
		i++;
		start++;
	}
	subs[i] = '\0';
	return (subs);
}

static void	ft_free(char **str, int cuts)
{
	while (cuts > 0)
	{
		free(str[cuts]);
		cuts--;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		cuts;

	str = malloc((ft_cutre(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	cuts = -1;
	i = 0;
	while (++cuts < ft_cutre(s, c))
	{
		while (s[i] == c)
			i++;
		str[cuts] = ft_substr(s, i, ft_sublen(s, c, i));
		if (!(str[cuts]))
		{
			ft_free(str, cuts);
			return (0);
		}
		i += ft_sublen(s, c, i);
	}
	str[cuts] = 0;
	return (str);
}
