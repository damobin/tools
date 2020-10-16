#include <winsock2.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
using namespace std;
#define name "www.baidu.com"
int main(int argc,char *argv[]) 
{ 
     
	WSADATA wsadata; 
	int n; 
	hostent *phostent; 
	protoent *pprotoent; 
	struct sockaddr_in sa; 
	if(WSAStartup(MAKEWORD(1,1),&wsadata)!=0) //启动动态库  Ws2_32.lib
	{ 
		printf("wsastartup() failed!!\n"); 
		return 0; 
	}

    if (argc != 2) {
        printf("Use example: %s www.google.com\n", *argv);
        return -1;
    }
	char *hostname = argv[1];
	//sprintf(hostname,"%s",name);
	printf("local host name:%s\n",hostname); 
	printf("------------------\n"); 
	phostent=gethostbyname(hostname); 
	if(phostent==NULL) 
	{ 
		printf("gethostbyname() error!!\n"); 
		return 0;
	} 
	printf("name:%s\nalianses:%s\naddrtype:%d\nlength:%d\n",phostent->h_name,phostent->h_aliases,phostent->h_addrtype,phostent->h_length); 
	//遍历出IP
	for(n=0;phostent->h_addr_list[n];n++) 
	{ 
		memcpy(&sa.sin_addr.s_addr,phostent->h_addr_list[n],phostent->h_length); 
		printf("address:%s\n",inet_ntoa(sa.sin_addr)); 
	} 
	printf("--------------------\n"); 
	pprotoent=getprotobyname("tcp"); 
	if(pprotoent==NULL) 
	{ 
		printf("getprotobyname() failed!!\n"); 
		return 0;
	} 
	printf("name:%\nproto:%d\n",pprotoent->p_name,pprotoent->p_proto); 
	for(n=0;pprotoent->p_aliases[n];n++) 
	{ 
		printf("aliases:%s\n",pprotoent->p_aliases[n]); 
	} 
	WSACleanup();

}    


     