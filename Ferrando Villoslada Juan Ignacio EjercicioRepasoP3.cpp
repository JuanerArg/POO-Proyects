#include<stdio.h>

/*
1-Dado un alquiler, se pide determinar  cuánto paga en impuesto por concepto de alquiler, considerando la siguiente escala de cobro:  
(sueldo <= 202) ? 0% impuesto,
(202 < sueldo <= 607) ? 5% impuesto,
(607 < sueldo <= 1.013) ?10% impuesto, 
(1.013 < sueldo <= 1.418) ?15% impuesto,
(1.418 < sueldo) ? 25% impuesto.

2-Dada como entrada una hora en formato hh:mm, [24], genere como salida la misma hora pero en formato hh:mm [am/pm]

3-Suponga que un individuo desea invertir su capital en un banco y desea saber 
¿Cuánto dinero ahorra después de un mes, si el banco paga a razón de 2% mensual?

4-Una persona tiene 50 años, y su hijo 20.  
¿Dentro de cuántos años la edad del padre será el doble que la de su hijo?

5-Convierta a horas minutos y segundos un tiempo expresado en segundos

*/

int main(void){
    int menu_option;

    do{
        printf("\n---------------------------------------\n");
        printf("1.Ej1\n2.Ej2\n3.Ej3\n4.Ej4\n5.Ej5\n6.Salir\n");
        scanf("%d", &menu_option);

        switch(menu_option){
            case 1:{
                printf("\n---------------------------------------\n");
                float sueldo;
                float impuesto;

                printf("Ingrese el valor del alquiler: ");
                scanf("%f", &sueldo);
                printf("\n");

                if(sueldo <= 202){
                    impuesto = 0;
                }else if(202 < sueldo <= 607){
                    impuesto = sueldo * 0.05;
                }else if(607 < sueldo <= 1.013){
                    impuesto = sueldo * 0.1;
                }else if(1.013 < sueldo <= 1.418){
                    impuesto = sueldo * 0.15;
                }else if(1.418 < sueldo){
                    impuesto = sueldo * 0.25;
                }
                printf("Se pagara %2.f de impuestos\n", impuesto);

                break;
            }
            case 2:{
                printf("\n---------------------------------------\n");
                int hora;
                int minutos;
                char *pmam;

                printf("Ingrese la hora: ");
                scanf("%d", &hora);
                printf("\n");
                printf("Ingrese los minutos");
                scanf("%d", &minutos);

                if(hora > 12){
                    hora = hora - 12;
                    pmam = "PM";
                }else pmam = "AM";

                printf("La hora es: %d:%d %s", hora, minutos, pmam);

                break;
            }
            case 3:{
                printf("\n---------------------------------------\n");

                float DeC; //dinero en cuenta

                printf("Ingrese cuanto dinero quiere invertir: ");
                scanf("%f", &DeC);
                printf("\n");

                DeC = DeC + (DeC * 0.02);

                printf("Luego de un mes, tendras %f\n", DeC);

                break;
            }
            case 4:{
                printf("\n---------------------------------------\n");

                int padre = 50;
                int hijo = 20;
                int cont;

                do{
                    padre = padre + 1;
                    hijo = hijo + 1;
                    cont = cont + 1;
                }while(padre != hijo * 2);

                printf("El padre tardara %d años en tener el doble de edad que su hijo", cont);

                break;
            }
            case 5:{
                printf("\n---------------------------------------\n");
                int horas, minutos, segundos;
                printf("Ingrese un tiempo en segundos: ");
                scanf("%d", &segundos);

                minutos = segundos / 60; 
                segundos = segundos % 60;

                horas = minutos / 60;
                minutos = minutos % 60;

                printf("En hh:mm:ss es: %d:%d:%d\n", horas, minutos, segundos);

                break;
            }
            case 6:{
                printf("\n---------------------------------------\n");
                printf("Saliendo del Programa...");
                printf("\nGoodbye ;p");

                break;
            }
        }
    }while(menu_option != 6);
    return 0;
}