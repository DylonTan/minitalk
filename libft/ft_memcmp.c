#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	offset;

	offset = 0;
	while (offset < n)
	{
		if (*(unsigned char *)(s1 + offset) != *(unsigned char *)(s2 + offset))
			return (*(unsigned char *)(s1 + offset)
				- *(unsigned char *)(s2 + offset));
		offset++;
	}
	return (0);
}
