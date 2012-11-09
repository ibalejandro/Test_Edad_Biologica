//Ejemplo 7.3  Instrucciones básicas.

//Encender los 8 leds conectados al puerto B si los suiches conectados 
// a RC0 y RC1 están activados y apagarlos si estan desactivados


#INCLUDE <16F886.h>
#USE     DELAY(CLOCK=4000000)
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
#DEFINE  SW1 PORTC,0
#DEFINE  SW2 PORTC,1
#BYTE    PORTB= 6
#BYTE    PORTC= 7

VOID MAIN()
{
   SET_TRIS_C(0B11111111);                      // Configura el puerto C
   SET_TRIS_B(0B00000000);                      // Configura el puerto B

   WHILE(TRUE)                                  // Haga por siempre
   { 
        
      IF(BIT_TEST(SW1)&&(BIT_TEST(SW2)))        // Si SW1 Y SW2 están en 1
      {
         PORTB=0B11111111;                      // Active los 8 leds
      }
      
      IF(!BIT_TEST(SW1)&&(!BIT_TEST(SW2)))    // Si SW1 en  1 Y SW2 en 0
      {
         PORTB = 0;                             // Apague los 8 leds         
      }
   }                                            //Cierra while                                                                                  
}                                               //Cierra Main

