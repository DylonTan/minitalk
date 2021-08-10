#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	offset;

	offset = 0;
	if (!dest || !src)
		return (NULL);
	if (src < dest)
	{
		offset = (int) n - 1;
		while (offset >= 0)
		{
			*(char *)(dest + offset) = *(char *)(src + offset);
			offset--;
		}
	}
	else
	{
		offset = 0;
		while (offset < (int) n)
		{
			*(char *)(dest + offset) = *(char *)(src + offset);
			offset++;
		}
	}
	return (dest);
}
