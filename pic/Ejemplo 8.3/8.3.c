//Ejemplo 8.3  Instrucciones de rotación.
 
//Encender uno a uno los bits del puerto B (0.5seg) desde RB0 hasta RB7
// y luego apagarlos  en sentido contrario desde RB7 hasta RB0.


#INCLUDE <16F886.h>
#USE     DELAY(CLOCK=4000000)
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
#BYTE    PORTB=6


VOID MAIN()
{
   SET_TRIS_B(0B00000000);
   PORTB=0;
   WHILE(TRUE)
   {
      PORTB=0B00000001;
      DELAY_MS(500);
     
      WHILE (!BIT_TEST(PORTB,7))
      {
         PORTB=PORTB<<1;
         DELAY_MS(500);
      }
      
      DELAY_US(500);
      
      WHILE (!BIT_TEST(PORTB,0))
      {
         PORTB=PORTB>>1;
         DELAY_MS(500);
      }
   } 
}

