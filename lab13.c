#include <stdio.h>

/* structure with bit fields */
struct BP
{
	unsigned char byte1:8;
	unsigned char byte2:8;
	unsigned char byte3:8;
	unsigned char byte4:8;
};

typedef struct BP BP;

int main(){
	BP bp;
	int n1,n2,n3,n4;
	unsigned byte1, byte2, byte3, byte4;
	puts("Enter bit fields:");
	printf("byte1:");
	scanf("%X",&byte1);
	printf("byte2:");
	scanf("%X",&byte2);
	printf("byte3:");
	scanf("%X",&byte3);
	printf("byte4:");
	scanf("%X",&byte4);
	bp.byte1=byte1;
	bp.byte2=byte2;
	bp.byte3=byte3;
	bp.byte4=byte4;
	puts("\nEnter shifts:");
	printf("byte1 shift:");
	scanf("%d",&n1);
	printf("byte2 shift:");
	scanf("%d",&n2);
	printf("byte3 shift:");
	scanf("%d",&n3);
	printf("byte4 shift:");
	scanf("%d",&n4);
	if (n1>7) n1=n1%8;
	if (n2>7) n2=n2%8;
	if (n3>7) n3=n3%8;
	if (n4>7) n4=n4%8;
	puts("\nResult:");
	printf("byte1:%X\n",bp.byte1>>n1);
	printf("byte2:%X\n",bp.byte2>>n2);
	printf("byte3:%X\n",bp.byte3>>n3);
	printf("byte4:%X",bp.byte4>>n4);
	return 0;
}
