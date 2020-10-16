#include "public.h"
#include "check.h"

//区分大小写
int main(int argc,char *argv[])
{
	char s8inputBuff[BUFFMAXLEN]="sdkflshfhf;lhla;HD;lHSD;lh;gljerlgjwel;kg";
	char s8outputBuff[BUFFMAXLEN];
	uint16_t u16list[BUFFMAXLEN];
	uint16_t u16listLen;
	printf("Test \r\n");
	u16listLen = calcultdiffchar(s8inputBuff,s8outputBuff,u16list,strlen(s8inputBuff));
	printf("char times\r\n");
	for(int i =0 ;i<u16listLen;i++){
		printf("%c    %02d\r\n",s8outputBuff[i],u16list[i]);
	}
	return 0;
}