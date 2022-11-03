#include "bsq_b.h"

char	*ft_parse_chars(int fd, int *lncount)
{
    char    *format;
    char    *pin;
    char    *dst;

    format = ft_read_chars(fd);
    *lncount = ft_atoi(format);
    pin = format;
    while (ft_isnum(*pin))
	pin++;
    dst = ft_strdup(pin);
    free(format);
    return (dst);
}

