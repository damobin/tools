#ifndef	CHECK_H
#define	CHECK_H
#include "public.h"
#define BUFFMAXLEN 0x200

uint16_t calcultdiffchar(
	char *s8inputchars,				/*输入字串*/
	char *s8outputchars,			/*输出字串*/
	uint16_t *u16list,  			/*输出不同字符的数目*/
	uint32_t u32lens				/*输入字符数目*/
);

#endif