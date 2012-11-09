//Ejemplo 15.4  LCD.

//Mostrar un mensaje diferente de acuerdo al pulsador que se oprima. 


#INCLUDE <16F886.h>
#USE DELAY(CLOCK=4000000)
#FUSES XT,NOPROTECT,NOWDT,NOBROWNOUT,NOPUT,NOLVP
#DEFINE USE_PORTB_LCD TRUE
#INCLUDE <LCD.C>
#BYTE PORTC= 7
#DEFINE PULSADOR1 PORTC,0
#DEFINE PULSADOR2 PORTC,1
#DEFINE PULSADOR3 PORTC,2

VOID MAIN()
{
   SET_TRIS_C(0B11111111);                // Define el puerto C como entrada
   LCD_INIT();                            // Inicializa el LCD
   WHILE(TRUE)                            // Haga por siempre
   {
      IF(BIT_TEST(PULSADOR1))             // Si pulsador 1 está activado
      {
         DELAY_MS(200);                   // Esperar 0.2 seg
         LCD_PUTC("\f");                  // Borrar el contenido del LCD
         LCD_GOTOXY(1,1);                 //En la fila 1, columna 1
         LCD_PUTC("SELECCIONE MENU:");    //Mostrar el “SELECCIONE MENU”
      }
 
      IF(BIT_TEST(PULSADOR2))             // Si el pulsador 2 está activado
      {
         DELAY_MS(200);                   // Esperar 0.2 seg
         LCD_PUTC("\f");                  // Borrar el contenido del LCD 
         LCD_GOTOXY(1,2);                 // En la columna 1, fila 2
         LCD_PUTC("MENU 1:");             // Mostrar el mensaje “MENU 1”
      }
 
      IF(BIT_TEST(PULSADOR3))             // Si el pulsador 3 está activado
      {
         DELAY_MS(200);                   // Esperar 0.2 seg
         LCD_PUTC("\f");                  // Borrar el contenido del LCD
         LCD_GOTOXY(1,1);                 // En la columna 1, fila 1
         LCD_PUTC("MENU 2:");             // Mostrar el mensaje “MENU 2”
      }
   }                                      // Cerrar while
}                                         // Cerrar main

