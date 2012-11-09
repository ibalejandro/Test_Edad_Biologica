//Ejemplo 7.5  Instrucciones básicas.

//Hacer un programa en microcontrolador que me indique si se quedaron 
//encendidas las luces del carro después de apagarlo, mediante un sonido 
//que prende y apaga cada 0,5 segundos y solo es posible desactivarlo 
//si se apagan las luces.


#INCLUDE <16F886.H>
#USE     DELAY(CLOCK=4000000)
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
#BYTE    PORTB= 6
#BYTE    PORTC= 7
#DEFINE  SONIDO    PORTB,0
#DEFINE  ENCENDIDO PORTC,0
#DEFINE  LUCES     PORTC,1


VOID MAIN()
{
   SET_TRIS_B(0B0000000);           // Configura el puerto B
   SET_TRIS_C(0B1111111);           // Configura el puerto C

   WHILE(TRUE)                      // Haga por siempre
   {
      IF(!BIT_TEST(ENCENDIDO)&&(BIT_TEST(LUCES)))    
      {
         BIT_SET(SONIDO);
         DELAY_MS(500);
         BIT_CLEAR(SONIDO);
         DELAY_MS(500);
      }
      IF(!BIT_TEST(ENCENDIDO)&&(!BIT_TEST(LUCES)))
      {
         BIT_CLEAR(SONIDO);
      }
   } 
}

