#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	offset;

	offset = ft_strlen(s);
	while (offset >= 0)
	{
		if (s[offset] == c)
			return ((char *)(s + offset));
		offset--;
	}
	return (NULL);
}
