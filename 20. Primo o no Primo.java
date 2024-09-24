/*
Pide un número por teclado e indica si es un número primo o no. 
Un número primo es aquel solo puede dividirse entre 1 y si mismo. 
Por ejemplo: 25 no es primo, ya que 25 es divisible entre 5, sin embargo, 17 si es primo.
Un buen truco para calcular la raíz cuadrada del numero e ir comprobando que si es divisible desde ese numero hasta 1.
NOTA: Si se introduce un numero menor o igual que 1, directamente es no primo.
*/
import java.util.Scanner;
import InputMismatchException;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = 0;
        int divisor = 2;
        int rta = 0;

        System.out.println("Ingrese un numero para saber si es primo o no");
        try{
            n = input.nextInt();
        }catch(InputMismatchException e){
            System.out.println("Error. Ingrese un numero");
        }

        do{
            rta = n % divisor;
            divisor++;
        }while(rta != 0);


        input.close();
    }
}
