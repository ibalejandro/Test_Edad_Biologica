//Ejemplo 12.1  Multiplexaje de display.

//Hacer un contador de 0 a 99 que incremente cada segundo.


#INCLUDE <16F886.h>
#USE     DELAY(CLOCK=4000000)
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
Byte CONST display[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
#BYTE    PORTB= 6
#BYTE    PORTC= 7
#DEFINE  TUNI PORTC,1            // Definición de variables
#DEFINE  TDEC PORTC,0            // Definición de variables

INT CONT;                        // Declarar la variable CONT como
                                 // un entero, es decir de 8 bits
LONG CONTRET;                    // Declarar la variable CONTRET 
                                 // como long, es decir de 16 bits

VOID MOSTRAR()                   // Rutina mostrar
{
  INT UNI,DEC;                   // Declarar las variables UNI, DEC
                                 // como un entero, es decir de 8bits
  DEC=CONT/10; 
  UNI=CONT%10;
  
  BIT_CLEAR(TDEC);               // Apaga el display de decenas
  BIT_SET (TUNI);                // Enciende el display de unidades
  PORTB=(DISPLAY[UNI]);          // Muestra lo que hay en unidades
                                 // en el display
  DELAY_MS(1);                   // Retardo de 1 milisegundos
  
  BIT_CLEAR(TUNI);               // Apaga el display de unidades
  BIT_SET (TDEC);                // Enciende el display de decenas
  PORTB=(DISPLAY[DEC]);          // Muestra lo que hay en unidades
                                 // en el display
  DELAY_MS(1);                   // Retardo de 1 milisegundos
}

VOID RET1SEG()                   // Rutina RET1SEG
{
   CONTRET=500;                  // Cargue con 500 la variable .                                                                                                                // CONTRET
   
   WHILE (CONTRET>0)             // Mientras que la variable
                                 // CONTRET sea mayor que cero
   {
      MOSTRAR();                 // Llamar  la rutina MOSTRAR
      CONTRET--;                 // Decremente la variable CONTRET
   }
}

VOID MAIN()
{
 
   SET_TRIS_B(0);                // El puerto B esta configurado 
                                 // como salida
   SET_TRIS_C(0B11111100);       // El puerto C esta configurado 
                                 // como entrada
   CONT=0;                       // la variable CONT se inicializa con cero
   
   WHILE(TRUE)                   // Haga por siempre
   {
      CONT=0;
      WHILE(CONT<100)            // mientras la variable CONT es 
                                 // menor que 100
      {
         RET1SEG( );             // Llama la rutina RET1SEG
         CONT++;                 // Incrementa la variable CONT
      }
   }
}

