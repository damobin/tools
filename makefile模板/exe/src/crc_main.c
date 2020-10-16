#include <crc_main.h>
int i,j,k;
int a,b,c;
int _COUNTNum;
int main(int arc,char *argv[])
{
	int CRCSumNum=0;
	byte STRING[200]="25 07 F8 45 00 00 00 C0 00 04 6B";
					  
	byte BUFF [100];
	memset(BUFF,'\0',100);
	ExcStrToBytes(BUFF,STRING);
	DISPLAYPOINTSTING(BUFF,(BUFF[1]+4),3);
	CRCSumNum = crc_16(BUFF+3,(BUFF[1]));
	printf("CRCSumNum = %02x\r\n",(unsigned char)CRCSumNum);
	
}
uint __fastcall crc_16(byte *buf,int len)
{
    uint crc=0xffff;
    while(len>0)
    {
    crc=(crc>>8)^CRC16_Table[(crc^*buf)&0xff];
    len--;
        buf++;
    }
    return ~crc;
}
void ExcStrToBytes(byte *Obj,byte *Src)
{
	char Temps[2];
	int Tempb=0,Lens=0;
	Temps[0]=Src[3];
	Temps[1]=Src[4];
	sscanf(Temps,"%x",&Tempb);
	Lens=Tempb;
	Obj[1]=Lens;
	for(i=0;i<Lens+4;i++){
		Temps[0]=Src[3*i  ];
		Temps[1]=Src[3*i+1];
		sscanf(Temps,"%x",&Tempb);
		Obj[i]=Tempb;		
	}
}

















