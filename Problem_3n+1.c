#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv){

    int a;
    int b;
    int i;
    int n;
    int max;
    int count = 0;
    char buffer[20];
    char buff_out[9024];
    char sentence[24];
    FILE *fout = fopen("data.out","w+");
    FILE *fin = fopen("data.in","r");
    buff_out[0] = '\0';
    while(fgets(buffer,sizeof(buffer),fin)) {
        
	if(buffer[0] == '\n' || buffer[0] == '\t' || buffer[0] == ' ')
	    continue;
	sscanf(buffer,"%d %d",&a,&b);        
        max = 1;
	sentence[0] = '\0';
        if(a>0 && b>0 && a<1000000 && b<1000000){
            if(a>b){
                i = b;
                b = a;
                a = i;
            }
            i=n=a;
            while(i<=b){
                count ++;
                if(n==1){ 
                    if(count > max)
                        max = count;
                   count = 0;
                   i++;
                   n=i;
                   continue;
                }

                
                if(n&1)
                    n = (3*n)+1;
                else
                    n >>= 1;      
                
                
            };
	    sprintf(sentence,"%d %d %d\n",a,b,max);
	    strcat(buff_out,sentence);
        }
    };
    fprintf(fout,buff_out);
    fclose(fout);
    return 0;
}
