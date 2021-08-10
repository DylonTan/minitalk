#include "libft.h"
#include <stdio.h>

static int	is_delimiter(char c, char delimiter)
{
	return (c == delimiter);
}

static int	count_words(char const *s, char c)
{
	size_t	offset;
	int		count;

	offset = 0;
	count = 0;
	while (s[offset])
	{
		while (s[offset] && is_delimiter(s[offset], c))
			offset++;
		if (s[offset] && !is_delimiter(s[offset], c))
		{
			count++;
			while (s[offset] && !is_delimiter(s[offset], c))
				offset++;
		}
	}
	return (count);
}

static char	*get_word(char const *s, char c)
{
	size_t	len;
	size_t	offset;
	char	*word;

	len = 0;
	offset = 0;
	while (s[len] && !is_delimiter(s[len], c))
		len++;
	word = (char *) malloc(sizeof(char) * (len + 1));
	while (s[offset] && !is_delimiter(s[offset], c))
	{
		word[offset] = s[offset];
		offset++;
	}
	word[offset] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**arr;

	i = 0;
	arr = (char **) malloc(sizeof(char *) * (count_words(s, c) + 1));
	while (*s)
	{
		while (*s && is_delimiter(*s, c))
			s++;
		if (*s && !is_delimiter(*s, c))
		{
			arr[i] = get_word(s, c);
			i++;
			while (*s && !is_delimiter(*s, c))
				s++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
