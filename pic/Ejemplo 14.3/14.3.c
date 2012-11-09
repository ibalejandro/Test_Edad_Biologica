//Ejemplo 14.3 Timer.

//Hacer un contador de 0 a 9, de tal manera que incremente cada segundo 
//por interrupción a través del timer, al llegar a 9 comienza de nuevo.


#INCLUDE <16F886.H>
#USE     DELAY(CLOCK=4000000)
#FUSES   XT,NOLVP,NOWDT
BYTE CONST DISPLAY[10]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X67};
#BYTE    PORTB=6
#DEFINE  INTS_PER_SECOND 15         // (4000000/(4*256*256)) 4=4mhz, 256= 
                                    // División 256, 256=Timer 256 se carga 
                                    // con cero.

BYTE SEGUNDOS;
BYTE INT_CONTADOR;
#INT_RTCC                           // Esta función es llamada cada 

VOID CLOCK_ISR()
{                                   // vez que el RTCC) pasa de (255->0).
   --INT_CONTADOR;                  // Para  este programa es
                                    //aproximadamente 76 veces   
                                    //por segundo
   IF(INT_CONTADOR==0)              
   {         
      ++SEGUNDOS;
      INT_CONTADOR=INTS_PER_SECOND;
   }
}

VOID MAIN() 
{
   SET_TRIS_B(0);
   INT_CONTADOR=INTS_PER_SECOND;
   SET_RTCC(0);
   SETUP_COUNTERS( RTCC_INTERNAL, RTCC_DIV_256);
   ENABLE_INTERRUPTS(INT_RTCC);      //Habilita la interrupción por RTCC        
   ENABLE_INTERRUPTS(GLOBAL);        // Habilita todas las interrupciones

   DO 
   {
      IF(SEGUNDOS==10)
      {
         SEGUNDOS=0;
      }
      PORTB=(DISPLAY[SEGUNDOS]);     // Muestra lo que hay en la variable
                                     // SEGUNDOS en el display
   } 
   WHILE (TRUE);
 }

