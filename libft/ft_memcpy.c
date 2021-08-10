#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	offset;

	if (!dest)
		return (NULL);
	offset = 0;
	while (offset < n)
	{
		*(char *)(dest + offset) = *(char *)(src + offset);
		offset++;
	}
	return (dest);
}
