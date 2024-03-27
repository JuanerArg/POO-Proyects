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
                int num1;
                printf("Ingresar un numero positivo mayor a 0: \n");
                scanf("%d", &num1);

                if(num1 > 0){
                    if(num1 % 2 == 0){
                        printf("El numero %d es par\n", num1);
                    }else printf("El numero %d es impar\n", num1);
                }else printf("Error, el numero no es mayor a 0\n");

                break;
            }
            case 4:{
                int nota1, nota2, nota3, nota4, notaT;
                printf("Ingrese las ultimas 4 notas")
                    scanf("%d", &nota1);
                        printf("\n");
                    scanf("%d", &nota2);
                        printf("\n");
                    scanf("%d", &nota3);
                        printf("\n");
                    scanf("%d", &nota4);
                        printf("\n");
                    scanf("%d", &notaT);
                        printf("\n");

                float promedio = (nota1 + nota2 + nota3 + nota4 + notaT) / 5;

                if(promedio >= 6){
                    printf("El alumno aprobo\n");
                }else printf("El alumno no aprobo\n");
                
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