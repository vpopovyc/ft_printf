#include "../ft_printf.h"
#define onebyte 128
#define twobytes 2048
#define threebytes 65536
#define fourbytes 2097152

char    *unicode_to_utf8(wchar_t c)
{
    unsigned char *data;
    data = (unsigned char*)malloc(sizeof(data) * 5);
    unsigned char *b = data;
    
    if (c<(1<<7))
        *b++ = (unsigned char)(c);
    else if (c<(1<<11))
    {
        *b++ = (unsigned char)((c>>6)|0xC0); /*1100 0000 */
        *b++ = (unsigned char)((c&0x3F)|0x80); /* & 0011 1111 | 1000 0000 */
    }
    else if (c<(1<<16))
    {
        *b++ = (unsigned char)(((c>>12))|0xE0); /* 1110 0000 0000 0000 */
        *b++ =  (unsigned char)(((c>>6)&0x3F)|0x80); // & 0011 1111 | 1000 0000 */
        *b++ =  (unsigned char)((c&0x3F)|0x80); // & 0011 1111 | 1000 0000
    } 
    else if (c<(1<<21))
    {
        *b++ = (unsigned char)(((c>>18))|0xF0); // 11110000
        *b++ = (unsigned char)(((c>>12)&0x3F)|0x80);
        *b++ = (unsigned char)(((c>>6)&0x3F)|0x80);
        *b++ = (unsigned char)((c&0x3F)|0x80);
    }
    *b = '\0';
    return ((char*)data);
}

int main(void)
{   
	char	*s;

	s = unicode_to_utf8(L'С');
	write(1, s, 5);
    //ft_putstr(unicode_to_utf8(L'л'));
    //ft_putstr(unicode_to_utf8(L'о'));
    //ft_putstr(unicode_to_utf8(L'х'));
	return (0);
}
