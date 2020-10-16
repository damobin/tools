#include <Float_Exc_Int.h>
typedef	unsigned int 		uint32_t;
typedef	unsigned short int 	uint16_t;
typedef	unsigned char		uint8_t;
int main(int argc,char *argv[]){
	uint32_t	objExData;
	float		outFloatData;
	while(1){
		printf("Float Exc Int Funs\r\n");
		
		scanf("%x",&objExData);
		

		if( (objExData & 0xff000000) == 0xff000000){
			printf("Nev Code ");
			objExData = (0xffffffff-objExData) +1;
			printf("-%d\r\n\r\n",objExData);
		}else{
			memcpy(&outFloatData,&objExData,4);
			printf("%.5f\r\n\r\n",outFloatData);
		}
		
		//printf("%.5uf\r\n\r\n",outFloatData);
		fflush(stdin);
		fflush(stdout);
	}
}