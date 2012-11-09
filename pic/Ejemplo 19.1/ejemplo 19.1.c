//Ejemplo 19.1 Conversor análogo – digital. 

//Mostrar en el LCD el valor numérico correspondiente a la señal análoga que 
//entra por RA0.
 

#INCLUDE <16F886.H>
#DEVICE  ADC=10                     // Define que el conversor trabaja a 10 bits
#USE     DELAY(CLOCK=4000000)
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
#BYTE    PORTA=5
#DEFINE  USE_PORTB_LCD TRUE
#INCLUDE <LCD.C>
LONG     VOLTAJE;                   // Definir la variable voltaje como una 
                                    // Variable tipo long

VOID MAIN()
{
   SET_TRIS_A(0B11111111);          // Configura todo el puerto a como ENTRADA   
   SETUP_ADC_PORTS(sAN0);           // Define todo el puerto a como 
                                    // Entradas análogas
   SETUP_ADC(ADC_CLOCK_INTERNAL);   // Define que el conversor trabaje 
                                    // Con el reloj interno
   LCD_INIT();                      // Inicializa LDC

   WHILE(true)
   {
      SET_ADC_CHANNEL(0);                    // Selecciona el canal 0 (ra0)
      DELAY_MS(1);                           //Llama un retardo de 1 milisegundo      
      VOLTAJE=READ_ADC();                    // Almacena en voltaje el valor 
                                             //de la conversión
      LCD_PUTC("\f");                 
      LCD_GOTOXY(1,1);              
      LCD_PUTC("CONVERSOR A/D");
      LCD_GOTOXY(1,2);
      PRINTF(LCD_PUTC,"VALOR %LU",VOLTAJE);  // Muestra el valor numérico de la 
                                             // Conversión.
      DELAY_MS(200);
   }
}

