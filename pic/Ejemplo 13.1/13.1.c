//Ejemplo 13.1  Interrupciones.

//Hacer un programa que me incremente un contador de 0 a 9, cuando ocurra una interrupción externa por RB0. Cuando el contador llegue a 9, comienza  de nuevo en cero.


#INCLUDE <16F886.H>
#FUSES   XT,NOLVP,NOWDT,PUT
#USE     DELAY(CLOCK=4000000)
Byte CONST display[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
#BYTE    PORTC = 7
#BYTE    PORTB = 6
INT CONT=0;

#INT_EXT
VOID INTERRUPCION()
{
   DELAY_MS(200);
   CONT++;                       // Incremente la variable CONT
   IF(CONT==10)                  // Si la variable CONT es igual a 10
   CONT=0;                       // Ponga en cero la  variable CONT  
}

VOID MAIN()
{
    SET_TRIS_B(0B11111111);      // Configurar el puerto B
    SET_TRIS_C(0);               // Configurar el puerto C 
    ENABLE_INTERRUPTS(GLOBAL);   // Habilita todas las interrupciones
    ENABLE_INTERRUPTS(INT_EXT);  // Habilita la interrupción externa
     
    WHILE(TRUE)
    {
      PORTC= (display[CONT]);    // Muestra lo que hay en la variable 
                                 // CONT en el display
    }
}

/*Existen diferentes tipos de interrupción en el microcontrolador, algunas de ellas se mencionan a continuación:

#INT_EXT     INTERRUPCIÓN EXTERNA
#INT_RTCC     DESBORDAMIENTO DEL TIMER0(RTCC)
#INT_RB   CAMBIO EN UNO DE LOS PINES B4,B5,B6,B7  
#INT_AD   CONVERSOR A/D  
#INT_EEPROM  ESCRITURA EN LA EEPROM COMPLETADA
#INT_TIMER1   DESBORDAMIENTO DEL TIMER1
#INT_TIMER2   DESBORDAMIENTO DEL TIMER2*/

