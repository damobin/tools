#include "check.h"

uint16_t calcultdiffchar(
	char *s8inputchars,				/*输入字串*/
	char *s8outputchars,			/*输出字串*/
	uint16_t *u16list,  			/*输出不同字符的数目*/
	uint32_t u32lens				/*输入字符数目*/
){
	uint32_t i,j,index;
	memset(s8outputchars,'\0',BUFFMAXLEN);	//初始化
	memset(u16list,0,BUFFMAXLEN);
	index=0;
	for(i = 0; i<u32lens;  i++){	//遍历输入
		j=0;
		do{
			if( s8inputchars[i] == s8outputchars[j] ){	//如果发现重复字串,那么对应的重复字串数目自增
				u16list[j]++;							//重复字串,桶数目加一
				break;
			}else if(j>=index){							//检索桶,如果遍历全局后没有重复,那么添加桶
				s8outputchars[index] = s8inputchars[i]; //添加输出字符
				index++;								//桶数目加一
				u16list[j]++;							//桶存量加一
				break;
			}
			j++;
		}while(1);					//检索桶循环
	}
	return index;	//返回桶数目
}