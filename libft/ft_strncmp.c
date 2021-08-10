#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	offset;

	offset = 0;
	while (s1[offset] && (s1[offset] == s2[offset]) && n > 0)
	{
		offset++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char) s1[offset] - (unsigned char) s2[offset]);
}
