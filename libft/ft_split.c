/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:23:34 by nlouro            #+#    #+#             */
/*   Updated: 2021/09/23 16:58:53 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	wc;
	int	i;

	wc = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 || *(s + i) == c) && *(s + i + 1) != c && *(s + i + 1) != 0)
			wc++;
		else if ((i + 1) == ft_strlen(s) && *(s + i) != c && *(s + i - 1) == c)
			wc++;
		i++;
	}
	if (wc <= 1 && s[0] != c)
		wc = 1;
	return (wc);
}

static char	**split_string(const char *str, char c)
{
	char	**result;
	int		i;
	int		wc;
	int		wbegin;
	int		wend;

	wc = count_words(str, c);
	result = (char **)malloc((wc + 1) * sizeof(char *));
	if (result == 0)
		return (0);
	i = 0;
	wbegin = 0;
	wend = 0;
	while (i < wc && str[wend] != '\0')
	{
		while (str[wend] == c)
			wend++;
		wbegin = wend;
		while (str[wend] != c && wend < ft_strlen(str))
			wend++;
		result[i] = ft_substr(str, wbegin, wend - wbegin);
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**result;

	if (s == 0)
		return (0);
	if (s[0] == 0)
		return (ft_calloc(1, sizeof(char *)));
	i = 0;
	while (s[i] == c)
		i++;
	if (s[0] == '\0' || i == ft_strlen(s))
	{
		result = ft_calloc(1, sizeof(char *));
		if (result == 0)
			return (0);
		result[0] = NULL;
		return (result);
	}
	result = split_string(s, c);
	return (result);
}
