#include<stdio.h>

/*

Hallar tres números consecutivos cuya suma sea 87.

Calcular la media (promedio) de 3 números

Determinar si un valor numérico positivo, mayor que cero ingresado es par o impar.

Dado como entrada las notas de 4 pruebas de un alumno y la nota de tarea, 
se pide determinar si el alumno aprobó o no la materia (se aprueba con 6). 

Dada una nota escriba “Aprobado” ó “Reprobado” según la nota ingresada, 
pero además si la nota de aprobación es mayor o igual a 8, escriba felicitaciones. 
y si la nota es 1, escriba “Debes esforzarte más”.

*/

int main(void){
    int menu_option;

    do{
        printf("1.Ej1\n2.Ej2\n3.Ej3\n4.Ej4\n5.Ej5\n6.Salir\n");
        scanf("%d", &menu_option);

        switch(menu_option){
            case 1:{
                int a = 1, b = 2, c = 3;
                int x = 87;

                while(a + b + c != x){
                    a = a + 1;
                    b = b + 1;
                    c = c + 1;
                }

                printf("Los numeros consecutivos que sumando dan 87 son :%d, %d y %d\n", a, b, c);
                break;
            }
            case 2:{
                int a, b, c;
                float promedio;

                printf("Ingrese 3 numeros: \n");
                scanf("%d ", &a);
                scanf("%d ", &b);
                scanf("%d", &c);
                printf("\n");

                promedio = (a + b + c)/3;
                printf("El promedio entre esos numeros es de: %2.f \n", promedio);
                break;
            }
            case 3:{
                

                break;
            }
            case 4:{
                

                break;
            }
            case 5:{
                

                break;
            }
            case 6:{
                printf("Saliendo del Programa...");
                printf("\nGoodbye ;p");
                
                break;
            }
        }
    }while(menu_option != 6);
    return 0;
}