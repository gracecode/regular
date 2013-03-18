/*
 * macros for bitmap
 */
#define BMAP_INVALID (-1L)

#define IND_BYTE(ind)	((ind)>>3)
#define IND_BIT(ind)	(1 << ((ind) & 0x7))

#define BMAP_SET(bmap, ind)	((bmap)[IND_BYTE(ind)] |= IND_BIT(ind))
#define BMAP_CLR(bmap, ind)	((bmap)[IND_BYTE(ind)] &= ~IND_BIT(ind))
#define BMAP_ISSET(bmap, ind)	((bmap)[IND_BYTE(ind)] & IND_BIT(ind))

/*
 * data translation
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char **argv)
{
        int value, content = 0x12345678;
        char buffer[256] = {"\0"};

        memcpy(buffer, (char *)(&content), sizeof(int));
        
        value = (int)(*((int *)buffer));        
        
        printf("value is 0x%x\n", value);       

        return (0);
}
