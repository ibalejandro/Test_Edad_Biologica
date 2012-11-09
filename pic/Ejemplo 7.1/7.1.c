//Ejemplo 7.1  Instrucciones básicas

//Encender un led  conectado a RB0 si el SW conectado a RB1 esta activado


#INCLUDE <16f886.h>
#USE     DELAY(CLOCK=4000000)
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
#DEFINE  SW PORTB,1
#DEFINE  LED PORTB,0
#BYTE    PORTB= 6

VOID MAIN()
{
   SET_TRIS_B(0B00000010);       // Configura el puerto B
   
   WHILE(TRUE)                   // Haga por siempre
   { 
      IF(BIT_TEST(SW))           // Si SW esta activado
      {
         BIT_SET(LED);           // Active el led
      }
      ELSE                       // Sino, es decir si SW esta desactivado
      {
         BIT_CLEAR(LED);         // Apagar led
      }
   }
}
                     // Todo lo que se escriba después de
                     // estas barras se considera comentario 
                     // y no altera para nada la ejecución del                                                    
                     // programa.



