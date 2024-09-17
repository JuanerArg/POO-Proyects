/*
Lee un número por teclado y comprueba que este numero es mayor o igual que cero, 
si no lo es lo volverá a pedir (do while), después muestra ese número por consola.
*/
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
      Scanner input = new Scanner(System.in);
      int num = 0;
      int acum = 0;
      do{
        if(acum > 0){
          System.out.println("Error, el numero no era mayor o igual a 0");
        }
        System.out.println("Introduce un número mayor o igual a 0");
        num = input.nextInt();
        acum++;
      }while(num < 0);
      System.out.println("El número introducido es: " + num);
      input.close();
      
    }
}