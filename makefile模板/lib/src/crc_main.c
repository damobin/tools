#include <crc_main.h>
#include <crc_table.h>
int _crcmain(byte *STRING)
{
	int CRCSumNum=0;
	//byte STRING[200]="25 0D F2 C4 00 0B 00 00 01 00 00 00 3A C5 B6 ED 24";
					  
	byte BUFF [100];
	memset(BUFF,'\0',100);
	ExcStrToBytes(BUFF,STRING);
	//DISPLAYPOINTSTING(BUFF,(BUFF[1]+4),3);
	CRCSumNum = crc_16(BUFF+3,(BUFF[1]));
	//printf("CRCSumNum = %02x\r\n",(unsigned char)CRCSumNum);
	return (unsigned char)CRCSumNum;
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
	int i;	
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

















