//Ejemplo 9.1.2 Motor paso a paso.

//Controlar un motor paso a paso conectado a los cuatro bits menos 
//significativos del puerto B, de tal manera que si el suiche conectado 
//a RC0 esta en uno gire a la derecha y si el suiche conectado a RC1 
//esta en uno, el motor gire a la izquierda.


#INCLUDE <16f886.h>
#fuses   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP,WRT
#use     delay(clock=4000000)
#byte    PORTB=6
#byte    PORTC=7
#define  SW PORTC,0
#define  SW1 PORTC,1

INT CONT;
byte const HORARIO[4]  =  {0b1000,    
                           0b0100,      
                           0b0010,
                           0b0001};
                           
byte const ANTIH[4]    =  {0b0001,
                           0b0010,
                           0b0100,
                           0b1000};
                           
VOID MAIN()
{
   SET_TRIS_C(0B11111111);                                                                                                                                                                                                                            // Configura el puerto C
   SET_TRIS_B(0B00000000);          // Configura el puerto B
   
   WHILE(TRUE)
   {
      while(BIT_TEST(SW))           // Pregunta si SW esta encendido
      {
         CONT=0;
         
         WHILE((CONT<4))            // Mientras que cont sea menor a 4
         {
            PORTB=(HORARIO[CONT]);  // Envíe al puerto B la información de la 
                                    // tabla de horario.
            DELAY_MS(500);          // Retardo de 500 milisegundos
            CONT++;                 // Incremente la variable cont.
         }
      }
    
      PORTB=0;                      // los bits del puerto b se apagan
      
      while(BIT_TEST(SW1))
      {
         CONT=0;                    //la variable contador se carga con cero.
         WHILE((CONT<4))            //Mientras que cont sea menor a 4 
         {
            PORTB=(ANTIH[CONT]);    //Envíe al puerto B la información de la 
                                    //tabla de antihorario
            DELAY_MS(500);          //Retardo de 500 milisegundos
            CONT++;                 //Incremente la variable cont
         }
      }
      
      PORTB=0;
   }
}

