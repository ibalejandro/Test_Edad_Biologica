//Ejemplo 20.2  Comunicación serial.

//Mostrar en el LCD el carácter digitado en el computador. 
   
  
#INCLUDE <16F886.H>
#USE     DELAY(CLOCK=4000000)
#USE     RS232(BAUD=9600, XMIT=PIN_C6, RCV=PIN_C7)
#DEFINE  USE_PORTB_LCD TRUE
#INCLUDE <LCD.C>
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP,WRT
#BYTE    PORTB= 6
#BYTE    PORTC= 7

VOID MAIN()
{
   CHAR K;                       // Definir la variable K como una variable 
                                 // Tipo caracter
   LCD_INIT();
   LCD_PUTC("\DIGITE EL TEXTO?\N");
   WHILE (TRUE)
   {
      K=GETC();                  // Guardar en K el valor capturado del 
                                 // Puerto serial
      LCD_PUTC(K);               // Mostrar K en el LCD
   }
}

