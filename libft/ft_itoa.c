#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*strrev(char *str)
{
	size_t	start;
	size_t	end;
	char	temp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (end > start)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
	return (str);
}

static int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	size_t	i;
	int		is_negative;
	int		len;
	char	*str;

	i = 0;
	is_negative = 0;
	len = num_len(n);
	if (n < 0)
		is_negative = 1;
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = abs_val(n % 10) + '0';
		i++;
		n /= 10;
	}
	if (is_negative)
		str[i] = '-';
	str[len] = '\0';
	return (strrev(str));
}
