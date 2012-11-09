//Ejemplo 15.5  LCD.

//Mostrar el mensaje  “BIENVENIDOS” en la primera línea del LCD, que se vaya 
//desplazando y luego el mensaje fijo “SELECCIONE MENU”  en la segunda línea.


#INCLUDE <16F886.h>
#USE     DELAY(CLOCK=4000000)
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,NOPUT,NOLVP
#DEFINE  USE_PORTB_LCD TRUE
#INCLUDE <LCD.C>
#BYTE    PORTC= 7

BYTE J;

VOID MAIN()
{
   SET_TRIS_C(0B11111111);             // Configurar el puerto C como entrada
   LCD_INIT();                         // Inicializar el LCD
   J=16;
   
   WHILE (J>0)                         // Mientras J sea mayor que 0
   {
   LCD_PUTC("\f");                     // Borrar el contenido del LCD
   LCD_GOTOXY(J,1);                    // En la  fila 1
   LCD_PUTC("  BIENVENIDOS   ");       // Mostrar el mensaje “BIENVENIDOS”
   DELAY_MS(150);                      // Esperar 150 milisegundos
   J--;
   }
   
   WHILE(1)                            // Haga por siempre
   {
   LCD_GOTOXY(J,2);                    // En la fila 2
   LCD_PUTC("SELECCIONE MENU:");       // Mostrar “SELECCIONE MENU”
   }   
}                                      // Cerrar main

