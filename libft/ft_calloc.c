#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;

	ptr = (void *) malloc(elsize * nelem);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, elsize * nelem);
	return (ptr);
}
