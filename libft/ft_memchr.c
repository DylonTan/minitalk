#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	offset;

	if (!s)
		return (NULL);
	offset = 0;
	while (offset < n)
	{
		if (*(unsigned char *)(s + offset) == (unsigned char)c)
			return ((void *)(s + offset));
		offset++;
	}
	return (NULL);
}
