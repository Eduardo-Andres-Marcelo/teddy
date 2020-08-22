#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){

    int a;
    int b;
    int i;
    int n;
    int count = 0;
    char buffer[20];
    FILE *fout = fopen("data.out","w+");
    while(fgets(buffer,sizeof(buffer),stdin)) {
        sscanf(buffer,"%d %d[^\n]",&a,&b);        
        int max = 1;
        if(a>0 && b>0 && a<1000000 && b<1000000 && b>a){
            for(i=n=a; i<=b; count++){
                if(n==1){
                    if(count > max)
                        max = count;
                    count = 0;
                    i++;
                    n=i;
                    continue;
                }
                if(n%2)
                    n = (3*n)+1;
                else
                    n /= 2;      
            }
            fprintf(fout,"%d %d %d\n",a,b,max);
        }
    };
    fclose(fout);
    return 0;
}