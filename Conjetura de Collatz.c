#include<stdio.h>

int main(){
    int n;

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    printf("\n%d", n);
    while(n != 1){
        if((n % 2) == 0){
            n = n / 2;
        }else n = (n * 3) + 1;
        printf("\n%d", n);
    }
}