#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
uint64_t lookupTable[1000] = {0};
char digitInteger[1000];
uint64_t fibonacci_memo(int n){
	if( n <= 2 ){
		return 1;
	}else{
		if( lookupTable[n] != 0){
			return lookupTable[n];
		}else{
			uint64_t x = fibonacci_memo(n-1) + fibonacci_memo(n-2);
			lookupTable[n] = x;
			return x;
		}
	}
}
int main(){
	FILE *fileInput = fopen("data.in","r");
	FILE *fileOutput = fopen("data.out","w");
	int value;
	while(fscanf(fileInput,"%d\n",&value) != EOF){
		if(value >= 1 && value <= 1000){
			fprintf(fileOutput,"%" PRIu64 "\n",fibonacci_memo(value));
		}
	};
	fclose(fileInput);
	fclose(fileOutput);
	return 0;
}
