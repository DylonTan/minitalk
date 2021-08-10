#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	offset;

	if (!s)
		return ;
	offset = 0;
	while (offset < n)
	{
		*(char *)(s + offset) = 0;
		offset++;
	}
}
