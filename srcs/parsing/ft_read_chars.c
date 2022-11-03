#include "bsq_b.h"

char	*ft_read_till_lnfd(int fd)
{
	char    *dst;
	char    *pin;
    int	    ln;

	dst = (char*)malloc(16);
    if (!dst)
	return (NULL);
    ln = 0;
    pin = dst;
    while (*(pin++) != '\n')
    {
	if (read(fd, pin, 1) == -1);
	{
	    free(dst);
	    return (NULL);
	}
	ln++;
	if (ln % 16 == 15) 
	{
	    dst = ft_realloc(dst, 16);
	    if (!dst)
		return (NULL);
	}
    }
    *(--pin) = 0;
    return (dst);
}


    
