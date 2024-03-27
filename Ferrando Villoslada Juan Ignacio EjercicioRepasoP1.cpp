#include<stdio.h>

/*1-Enviar un mensaje de texto o whatsApp desde el teléfono celular. 
Se deberá verificar que haya crédito o servicio de Wifi para poder realizar la operación, según corresponda.

2-Para ingresar a un curso de capacitación se solicita a los empleados aprobar dos exámenes. 
Ingresarán aquellos que hayan logrado como mínimo 7 y 8 puntos respectivamente. 
Se deberá mostrar en pantalla la palabra “Apto” o “No apto”.

3-Se ingresa el sueldo de un trabajador y se aplica un aumento del 15% si su sueldo es inferior a $8.000 y 12% en caso contrario. 
Luego, mostrar el nuevo sueldo del trabajador.*/

int main(void){
int menu_option;

do{
    printf("1.Ejercicio 1\n2.Ejercicio 2\n3.Ejercicio 3\n4.Salir\n");

    scanf("%d", &menu_option);

    switch(menu_option){
        case 1:{
            char mensaje[100];
            int wifi;
            int datos;

            printf("Tenes wifi? (1 = si || 0 = no) \n");
            scanf("%d", &wifi);
            
            printf("Tenes datos? (1 = si || 0 = no)\n");
            scanf("%d", &datos);

            if(wifi == 1 || datos == 1){
                printf("Escribe tu mensaje: \n");
                scanf(" %[^\n]", mensaje);
            }

            printf("Mensaje enviado: %s\n", mensaje);
            break;
        }
        case 2:{
            int nota1, nota2;

            printf("Cuanto te sacaste en los examenes? \n");
            scanf("%d", &nota1);
            printf("\n");
            scanf("%d", &nota2);
            printf("\n");

            if(nota1 >= 7 && nota2 >= 8){
                printf("Apto\n");
            }else printf("No Apto\n");
            break;
        }
        case 3:{
            float sueldo;

            printf("Cual es tu sueldo? \n");
            scanf("%f", &sueldo);

            if(sueldo < 8000){
                sueldo = sueldo * 1.15;
            }else sueldo = sueldo * 1.12;

            printf("Tu sueldo con el aumento es de %2.f\n", sueldo);
            break;
        }
        case 4:{
            printf("Saliendo del Programa...");
            printf("\nGoodbye ;p");

            break;
        }
    }
}while(menu_option != 4);
}