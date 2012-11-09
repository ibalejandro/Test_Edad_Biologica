//Ejemplo 11.1  Display 7 segmentos.

//Hacer un contador de 0 a 9 cada segundo, mostrando el valor del contador 
//en un display 7 segmentos. Al llegar a 9, el contador comienza de nuevo.

 
#INCLUDE <16F886.H>
#USE     DELAY(CLOCK=4000000)
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
BYTE CONST DISPLAY[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
#BYTE PORTB=6

INT CONTADOR;

VOID MAIN()
{
   SET_TRIS_B(0B00000000);          // Configura el puerto B   
   
   WHILE(TRUE)                      // Haga por siempre
   {
      CONTADOR = 0;                 // Inicializa contador en cero
      
      WHILE(CONTADOR<10)            // Mientras contador < 10
      {
         PORTB= DISPLAY[CONTADOR];  // Muestre el valor en el display                    
         CONTADOR++;                // Incrementa contador
         DELAY_MS(1000);            // Retardo de 1 segundo
      }
   }
}
 

