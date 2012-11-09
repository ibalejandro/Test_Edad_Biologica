//Ejemplo 18.1 Memoria eeprom externa

//Con un teclado telefónico, un LCD y una memoria eeprom externa digitar 
//4 números y luego recuperarlos, en el LCD mostrar el valor digitado 
//y el valor recuperado.
         
//Figura 18.2 Conexión ejemplo 14

#INCLUDE <16F886.H>
#USE     DELAY(CLOCK=4000000)
#DEFINE  USE_PORTB_KBD
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP,WRT
#DEFINE  USE_PORTB_LCD TRUE
#INCLUDE <LCD.C>
#INCLUDE <KBD.C>
#INCLUDE <2402.C>
#BYTE    WPUB=0x95

INT K;                              // Defino la variable K como carácter
BYTE J=16,DIR;          

VOID MAIN()
{
   PORT_B_PULLUPS(TRUE);            // Activar las resistencias a positivo de
   WPUB=255;                                   // Puerto B
   LCD_INIT();
   KBD_INIT();
   INIT_EXT_EEPROM();
  
   FOR (J=12; J>=2; --J)
   {
      LCD_GOTOXY(J,1);
      LCD_PUTC("DIGITADO:       ");
      DELAY_MS(100);                // Retardo de 100 milisegundos
                                    // LCD_PUTC("\F");
   }

   LCD_GOTOXY(12,1);                // Ubicarse en la columna 12 fila 1
   DIR=0;                           // Poner la variable DIR en cero
   WHILE (DIR<4)                    // Mientras que DIR sea menor que 4
   {
      K=0;                          // Poner la variable K en cero
      K=KBD_GETC();   
      IF( (K!='\0'))         
      {
         LCD_PUTC(K);
         WRITE_EXT_EEPROM(DIR,K);
         DIR++;                     // Incrementa la variable DIR
      }
   }
   DELAY_MS(500);                   // Retardo de 500 milisegundos
   
   FOR (J=12; J>=2; --J)
   {
      LCD_GOTOXY(J,2);              // Ubicarse en la fila 2 y la columna varía
      LCD_PUTC("RECUPERADO:     ");
      DELAY_MS(100);                // Retardo de 100 milisegundos
   }
   LCD_GOTOXY(13,2);                // Ubicarse en la columna 13 fila 2
   DIR=0;                           // Poner la variable DIR en cero
 
   WHILE (DIR<4)                    // Mientras que DIR sea menor a 4
   {
      K=READ_EXT_EEPROM(DIR);
      LCD_PUTC(K);
      DIR++;                        // Incrementa la variable DIR
   }
}

