//Ejemplo 8.2  Instrucciones de rotación.

//Encender uno a uno los bits del puerto B, cada medio segundo, comenzando 
//por RB0. En ningún momento se pueden encender dos leds al mismo tiempo.


#INCLUDE <16f886.h>
#USE DELAY(CLOCK=4000000)
#FUSES XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
#BYTE PORTB= 6

VOID  MAIN()
{
   SET_TRIS_B(0B00000000);            // Configura el puerto B  
   
   WHILE(TRUE)                  // Haga por siempre
   { 
        
      PORTB=0B00000001;            // Active el led RB0
      DELAY_MS(500);               // Retardo de 500 mS
      
      WHILE(!BIT_TEST(PORTB,7))            // Mientras RB7=0
      {
         PORTB= PORTB<<1;            // Rote el PORTB una vez a la                                 .                                                                                 //izquierda
         DELAY_MS(500);            // Retardo de 500 mS
      }
   }
}


