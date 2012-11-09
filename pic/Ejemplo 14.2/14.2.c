//Ejemplo 14.2  Timer.

//Realizar un temporizador de 0 a 60 segundos.


#INCLUDE <16f886.h>
#USE     DELAY(CLOCK=4000000)
#fuses   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
Byte CONST display[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
#DEFINE  U PORTC,0
#DEFINE  D PORTC,1
#byte    PORTB= 6
#byte    PORTC= 7
INT UNI,DEC,I,VECES,SEG;

VOID MOSTRAR()                // Muestra en  el display los segundos
{
   I=SEG;
   UNI=0;
   DEC=0;

   WHILE(I>=10)
   {
      I=I -10;
      DEC++;
   }
   
   UNI=I;
   
   BIT_SET(U);
   BIT_CLEAR(D);
   PORTB=(display[UNI]);
   DELAY_MS(1);
   
   BIT_SET(D);
   BIT_CLEAR(U);
   PORTB=(display[DEC]);
   DELAY_MS(1);
}

#INT_RTCC                     // Rutina de interrupción por RTCC
VOID RELOJ()
{
   VECES--;
   SET_RTCC(238);
     
   IF(VECES==0)
   {
      SEG++;
      VECES=217;
   }
}


VOID MAIN()
{
   SET_TRIS_B(0);
   SET_TRIS_C(0);
   UNI=0;
   DEC=0;
   VECES=217;
   SEG=0;

   SET_RTCC(238);
   SETUP_COUNTERS(RTCC_INTERNAL, RTCC_DIV_256);
   ENABLE_INTERRUPTS(INT_RTCC);
   ENABLE_INTERRUPTS(GLOBAL);

   WHILE(TRUE)
   {
      IF(SEG==60)
      SEG=0;
      ELSE
      MOSTRAR();
   }
}

