#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	offset;
	size_t	len;

	offset = 0;
	len = ft_strlen(s);
	while (offset <= len)
	{
		if (s[offset] == c)
			return ((char *)(s + offset));
		offset++;
	}
	return (NULL);
}
