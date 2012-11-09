//Ejemplo 12.2 Multiplexaje de display.

//Mostrar un valor fijo en el display, partiendo de un número decimal.


#INCLUDE <16F886.h>
#USE     DELAY(CLOCK=4000000)
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
Byte CONST display[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
#BYTE    PORTB= 6
#BYTE    PORTC= 7
#DEFINE  TUNI PORTC,1            // Definición de variables
#DEFINE  TDEC PORTC,0            // Definición de variables
INT CONT;                        // Declarar la variable CONT                                                                                                                // como un entero.

VOID MOSTRAR()                  // Rutina mostrar
{
   INT UNI,DEC;                  // Declarar las variables UNI
                                 // DEC como un entero         
   DEC=CONT/10;                       
   UNI=CONT%10;                  // Lo que hay en la variable.                                                                                                                // CONT, llévelo a Y  
   
   
   BIT_CLEAR(TDEC);              // Apaga el display de decena
   BIT_SET (TUNI);               // Prende el display de unidades
   PORTB=(DISPLAY[UNI]);         // Muestra lo que hay en
                                 // unidades en el display 
   DELAY_MS(1);                  // Retardo de 1 milisegundos
   
   
   BIT_CLEAR(TUNI);              // Apaga el display de unidades
   BIT_SET (TDEC);               // Prende el display de decenas
   PORTB=(DISPLAY[DEC]);         // Muestra lo que hay en unidades
                                 // en el display
   DELAY_MS(1);                  // Retardo de 1 milisegundos
}

VOID MAIN()
 {
   SET_TRIS_B(0);                // El puerto B esta configurado como salida
   SET_TRIS_C(0);                // El puerto C esta configurado como entrada,
                                 // excepto los bits RC4 y RC5
   CONT=0;                       // la variable CONT se inicializa con cero
   WHILE(TRUE)                   // Haga por siempre
      {
        CONT=76;
        WHILE(TRUE)              // Haga por siempre
         {
            MOSTRAR();           // Llamar la rutina Mostrar
         }
     }
}

