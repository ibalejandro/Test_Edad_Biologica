//Ejemplo 7.4  Instrucciones básicas.

//Hacer un programa en microcontrolador que controle un secador de manos 
//de tal manera que cuando se oprima el pulsador encienda el motor
//y la resistencia durante 10 segundos.


#INCLUDE <16f886.h>
#USE     DELAY(CLOCK=4000000)
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
#BYTE    PORTB= 6
#BYTE    PORTC= 7
#DEFINE  MOTOR          PORTB,0
#DEFINE  RESISTENCIA    PORTB,1
#DEFINE  PULSADOR       PORTC,0

VOID MAIN()
{
   SET_TRIS_B(0B0000000);
   SET_TRIS_C(0B1111111);           // Configura el puerto B
   PORTB=0;

   WHILE(TRUE)                      // Haga por siempre
   {
      IF(BIT_TEST(PULSADOR))
      {
         BIT_SET(MOTOR);            // Active el Motor
         BIT_SET(RESISTENCIA);      // Active la Resistencia
         DELAY_MS(10000);           // Retardo de 10 segundos
         BIT_CLEAR(MOTOR);          // Apagar el Motor
         BIT_CLEAR(RESISTENCIA);    // Apague la Resistencia
      }                             // Cierra el If 
   }                                // Cierra el While 
}                                   // Cierra el Main       
