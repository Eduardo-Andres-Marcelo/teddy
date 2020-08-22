#include<stdio.h>
#include<stdlib.h>

int main(){
    char a[1024];
    char b[1024];

    printf("+ Ingresa el primer valor:");
    scanf("%s[^\n]",a);
    printf("+ Ingresa el segundo valor:");
    scanf("%s[^\n]",b);

    printf("%s + %s = C\n",a,b);
    return 0;
}
