#include "bsq_b.h"

char	*ft_realloc(char *src, int step)
{
    char    *dst;
    int	    ln_src;
    
    ln_src = ft_strlen(src);
    dst = ft_calloc(ln_src + step, 1);
    ft_memcpy(dst, src, ln_src);
    return (dst);
}


