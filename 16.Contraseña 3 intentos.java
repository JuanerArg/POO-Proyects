/*
Escribe una aplicación con un String que contenga una contraseña cualquiera. 
Después se te pedirá que introduzcas la contraseña, con 3 intentos. 
Cuando aciertes ya no pedirá mas la contraseña y mostrara un mensaje diciendo «Enhorabuena». 
Piensa bien en la condición de salida (3 intentos y si acierta sale, aunque le queden intentos).
*/
import java.util.Scanner;

public class Main {
    public static void cleaner(){
      System.out.print("\033[H\033[2J");  
      System.out.flush(); 
    }
    
    public static void main(String[] args) {
      Scanner input = new Scanner(System.in);
      
      String password = "1234";
      int acum = 0;
      String passwordUser = "";
      
      do{
        if (acum > 0) {
          cleaner(); 
          System.out.println("Contraseña incorrecta, intente de nuevo");
        }
        
        if (acum == 0) System.out.println("Ingrese la contraseña: ");
        passwordUser = input.nextLine();
      
        if (password.equals(passwordUser)) break; 
        
        acum++;
      }while((acum + 1) <= 3);
      
      if (password.equals(passwordUser)){
        cleaner();
        System.out.println("Enhorabuena");
      }
      else {
        cleaner();
        System.out.println("Contraseña incorrecta");
        System.out.println("Se acabaron los intentos");
      }
      input.close();
    }
}