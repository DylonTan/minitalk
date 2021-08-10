#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	size_t	offset;

	offset = 0;
	while (set[offset])
	{
		if (set[offset] == c)
			return (1);
		offset++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	str = ft_substr(s1, start, end - start);
	if (!str)
		return (NULL);
	return (str);
}
