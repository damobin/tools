#ifndef PUBLIC_H
#define PUBLIC_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define  	ON  		1
#define  	OFF 		0
#define 	DISPLAY 	1
#define  	Debug 		0	//是否打印
typedef unsigned char uint8_t;
//AES计算结构
typedef struct AESX_OneTimeCalDATAS{
	uint8_t AESX_Keys[0x10];
	uint8_t AESX_Inputs[0x10];
	uint8_t AESX_Outputs[0x10];
	uint8_t AESX_SubKeys[0x10*11];
	uint8_t AESX_SBoxs[0x10*16];
}AESOneTimeCalDATAS;

extern uint8_t RandIndex[16];



extern unsigned int _COUNTNum;
extern int i, j, k ,a ,b ,c;
extern uint8_t	InputDatas[16];
extern uint8_t AESX_Times;							//执行过AES的次数
const extern  uint8_t c_AESRoundNums[10];			//AES 轮常数
const extern  uint8_t c_SBOX[256];		 			//AES S盒
const extern  uint8_t c_XTIME[256];					//AES 2倍乘数
const extern  uint8_t RandNumsComplexSbox[18];		//AES S盒生成随机数混淆
const extern  uint8_t RandNumsComplexSubKey[18];	//AES 子秘钥生成随机数混淆
const extern uint8_t EEPROM_DATAS[0x800];
#define   STOP 	 while(1);
//数组输出
//字符串指针输出
/*    printf("\nTime=%s P_Line=%d\n",__TIME__,__LINE__);   */
#ifdef DISPLAY
#define DISPLAYPOINTSTING(SRCS,LEN,LEVEL)	do{	    \
    if(LEVEL){                                      \
        _COUNTNum++;                                \
        if((LEN)>16){                               \
            for(a=0;a<(LEN);a++)                    \
            {										\
                printf("%02x ",*(SRCS+a));			\
                if(a!=0 && (a+1)%0x10==0){          \
					if(LEVEL>=1){					\
						printf("\n");               \
						}							\
                }                                   \
            }										\
			if(LEVEL>2){							\
				printf("\n");						\
			}										\
        }                                           \
        else{                                       \
            for(a=0;a<(LEN);a++)                    \
            {										\
                printf("%02x ",*(SRCS+a));			\
            }										\
			if(LEVEL>2){							\
				printf("\n");						\
			}										\
        }                                           \
    }                                               \
}while(0);
#else
#define DISPLAYPOINTSTING(SRCS,(LEN),LEVEL)  do{    \
}while;                    
#endif

#ifdef DISPLAY
#define DISPLAYSS(STR,LEVEL)          do{             \
    if(LEVEL){                                        \
        printf("%s\n",STR);                           \
    }                                                 \
}while(0);
#else
#define DISPLAYSS(STR,LEVEL)          do{             \
}while(0);           
#endif

//字符串copy
#define CHARCPYS(DESTS,SRCS,LEN)	do{		\
	for(a=0;a<LEN;a++)						\
	{										\
		*(DESTS+a) = *(SRCS+a);				\
	}										\
}while(0);

//字符串Xor
#define CHARXORS(DESTS,SRCS,LEN)	do{		\
	for(a=0;a<LEN;a++)						\
	{										\
		*((DESTS)+a) ^= *((SRCS)+a);		\
	}										\
}while(0);

//MATRIX COPY
#define MATRIXCPYS(DESTS,SRCS,ORDER)	do{			\
	for(a=0;a<ORDER;a++){							\
		for(b=0;b<ORDER;b++){						\
			*(DESTS[a]+b) = *(SRCS[a]+b);			\
		}											\
	}												\
}while(0);

//MATRIX EXCHANGE TO INEX
#define MATRIXEXCHANGEINDEX(INDEX,MATRIX,ORDER)	do{			\
	for(a=0;a<ORDER;a++){									\
		for(b=0;b<ORDER;b++){								\
		*(INDEX+a*ORDER + b) = *(MATRIX[a]+b);				\
		}													\
	}														\
}while(0);

#define MATRIX_PRINT(SRCS,NAME)	do{		                                                                                                            \
    if(strlen(SRCS)>=16) {                                                                                                                          \
	    printf("%s is:               %02X %02X %02X %02X   ",NAME,SRCS[0],SRCS[4],SRCS[8],SRCS[12]); printf("\n");                                  \
	    printf("                         %02X %02X %02X %02X   ",SRCS[1],SRCS[5],SRCS[9],SRCS[13]); printf("\n");                                   \
	    printf("                         %02X %02X %02X %02X   ",SRCS[2],SRCS[6],SRCS[10],SRCS[14]); printf("\n");                                  \
	    printf("                         %02X %02X %02X %02X   ",SRCS[3],SRCS[7],SRCS[11],SRCS[15]); printf("\n");                                  \
	    printf("\n");                                                                                                                               \
    }                                                                                                                                               \
}while(0);

#define MATRIX_LINEPRINT(SRCS,NAME)	do{		                                                                                                        \
    if(strlen(SRCS)>=16) {                                                                                                                          \
	    printf("%s is:               %02X %02X %02X %02X   ",NAME,SRCS[0],SRCS[1],SRCS[2],SRCS[3]); printf("\n");                                   \
	    printf("                         %02X %02X %02X %02X   ",SRCS[4],SRCS[5],SRCS[6],SRCS[7]); printf("\n");                                    \
	    printf("                         %02X %02X %02X %02X   ",SRCS[8],SRCS[9],SRCS[10],SRCS[11]); printf("\n");                                  \
	    printf("                         %02X %02X %02X %02X   ",SRCS[12],SRCS[13],SRCS[14],SRCS[15]); printf("\n");                                \
	    printf("\n");                                                                                                                               \
    }                                                                                                                                               \
}while(0);

#define MATRIX_PRINT_DINDEX(SRCS,NAME,LEVEL)	do{	\
	printf("%s\n",NAME);							\
	DISPLAYPOINTSTING(SRCS[0],4,LEVEL);				\
	DISPLAYPOINTSTING(SRCS[1],4,LEVEL);				\
	DISPLAYPOINTSTING(SRCS[2],4,LEVEL);				\
	DISPLAYPOINTSTING(SRCS[3],4,LEVEL);				\
	printf("\n");									\
}while(0);

#define DISPLAYAES_STRUCTDATAS(SRCS,LEVEL)				do{						\
	if(sizeof(*(SRCS))>=480){														\
		DISPLAYSS("\nSTRUCT DATAS",LEVEL);									  	\
		DISPLAYSS("KEY:",LEVEL);									  		  	\
		DISPLAYPOINTSTING((SRCS)->AESX_Keys		,KEY_LEN	,LEVEL)			  	\
		DISPLAYSS("\nINPUTS:",LEVEL);											\
		DISPLAYPOINTSTING((SRCS)->AESX_Inputs		,KEY_LEN	,LEVEL)			  	\
		DISPLAYSS("\nAESX_SubKeys:",LEVEL);										\
		DISPLAYPOINTSTING((SRCS)->AESX_SubKeys	,SUB_KEY_LEN,LEVEL)				\
		DISPLAYSS("\nAESX_SBoxs:",LEVEL);										\
		DISPLAYPOINTSTING((SRCS)->AESX_SBoxs		,SBOX_LEN	,LEVEL)				\
		DISPLAYSS("\nAESX_Outputs:",LEVEL);										\
		DISPLAYPOINTSTING((SRCS)->AESX_Outputs	,KEY_LEN	,LEVEL)			  	\
	}else{																		\
		printf("\n ERR STURCT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");		  		\
	}																			\
}while(0);

#define DISPLAYAES_AESINOUT(SRCS,LEVEL)				do{							\
	if(sizeof(*SRCS)>=480){														\
		DISPLAYSS("\nAESX_INPUTS:",LEVEL);											\
		DISPLAYPOINTSTING(SRCS->AESX_Inputs		,KEY_LEN	,LEVEL)			  	\
		DISPLAYSS("\nAESX_Outputs:",LEVEL);										\
		DISPLAYPOINTSTING(SRCS->AESX_Outputs	,KEY_LEN	,LEVEL)			  	\
	}else{																		\
		printf("\n ERR STURCT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");		  		\
	}																			\
}while(0);

#define AES_STRUCTDATASINITS(SRCS)				do{								\
	if(sizeof(*SRCS)>=480){														\
		memset((SRCS)->AESX_Keys		,'\0',	KEY_LEN		);			  		\
		memset((SRCS)->AESX_Inputs		,'\0',	KEY_LEN		);			  		\
		memset((SRCS)->AESX_Outputs		,'\0',	KEY_LEN		);			  		\
		memset((SRCS)->AESX_SubKeys		,'\0',	SUB_KEY_LEN	);					\
		memset((SRCS)->AESX_SBoxs		,'\0',	SBOX_LEN	);					\
	}else{																		\
		printf("\n ERR STURCT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");		  		\
	}																			\
}while(0);


#define AES_STRUCTDATACOPY(DESTS,SRCS)				do{												\
	if(sizeof(*SRCS)>=480){																			\
		memcpy((DESTS)->AESX_Keys		,(SRCS)->AESX_Keys			,	KEY_LEN		);			  	\
		memcpy((DESTS)->AESX_Inputs		,(SRCS)->AESX_Inputs		,	KEY_LEN		);			\
		memcpy((DESTS)->AESX_Outputs	,(SRCS)->AESX_Outputs		,	KEY_LEN		);			  	\
		memcpy((DESTS)->AESX_SubKeys	,(SRCS)->AESX_SubKeys		,	SUB_KEY_LEN	);				\
		memcpy((DESTS)->AESX_SBoxs		,(SRCS)->AESX_SBoxs			,	SBOX_LEN	);				\
	}else{																							\
		printf("\n ERR STURCT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");		  							\
	}																								\
}while(0);


#define DISPLAYAES_GUIDATA(SRCS,LEVEL)				do{							\
	if(sizeof(*(SRCS))>=5){														\
		DISPLAYSS("\nRANDNUMS:",LEVEL);											\
		DISPLAYPOINTSTING((SRCS)->GUI_RandNums		,4	,LEVEL)			  		\
		DISPLAYSS("\nORDER:",LEVEL);											\
		if(LEVEL){																\
			printf("%02x\n\n",(SRCS)->GUI_Order);									\
		}																		\
	}else{																		\
		printf("\n ERR STURCT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");		  		\
	}																			\
}while(0);


#endif