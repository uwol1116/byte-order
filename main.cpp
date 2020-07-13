#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>


int main(int argc, char* argv[]){
	FILE *fp1, *fp2;
	uint32_t num1, num2, result;

	if(argc < 3){
		printf("Usage :./add-nbo <file1> <file2>\n");
		return 0;
	}	

	if ((fp1 = fopen(argv[1],"r")) == NULL){
		printf("open error <file1>\n");
		return 0;
	}
	if ((fp2 = fopen(argv[2],"r")) == NULL){
		printf("open error <file2>\n");
		return 0;
	}

	fread(&num1, sizeof(num1), 1, fp1);
	fread(&num2, sizeof(num2), 1, fp2);

	num1 = htonl(num1);
	num2 = htonl(num2);
	result = num1 + num2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",num1, num1,num2,num2,result,result);

	return 0;
}
