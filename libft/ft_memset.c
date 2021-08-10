#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	offset;

	if (!s)
		return (NULL);
	offset = 0;
	while (offset < n)
	{
		*(char *)(s + offset) = (char) c;
		offset++;
	}
	return (s);
}
