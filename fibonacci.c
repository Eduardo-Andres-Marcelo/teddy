#include<stdio.h>
#include<stdlib.h>

int lookupFib[1000] = { 0 };
int maxFib = 0;
int fibonacci_mem(int f){
   
   int index;
   if(maxFib < f){
	int temp = 0;
	for(index=2; index<=f; ++index){
		lookupFib[index] = lookupFib[index-2] + lookupFib[index-1];
	}
	maxFib = f;
   }
   return lookupFib[f];
}

int main(){
   FILE *fileData = fopen("data.in","r");
   FILE *fileResult = fopen("data.out","w");
   int value;

   lookupFib[0] = 0;
   lookupFib[1] = 1;

   while(fscanf(fileData,"%d\n",&value) != EOF){
	if(value >=1 && value <=1000){
		fprintf(fileResult,"%d\n",fibonacci_mem(value));
	}
   }
   fclose(fileData);
   fclose(fileResult);
   return 0;
}
