#include <crc_main.h>
#include <stdio.h>
int main(int argc,char *argv[])
{
	unsigned char BUFF[]="25 0D F2 C4 00 0B 00 00 01 00 00 00 3A C5 B6 ED";
	printf("get Data is:%02x ",_crcmain(BUFF));
	return 0;
}