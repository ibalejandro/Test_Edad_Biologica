//Ejemplo 15.3 LCD.

//Mostrar un mensaje fijo en el LCD que en la primera fila “GUIA EN PIC C” 
//y en la segunda “EAFIT”.
 

#INCLUDE <16F886.H>
#USE     DELAY(CLOCK=4000000)
#DEFINE  USE_PORTB_LCD TRUE
#INCLUDE <LCD.C>
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP,WRT
#BYTE    PORTB= 6
         
VOID MAIN()
{
   SET_TRIS_B(0);                         // Define el puerto B como salida
   PORTB=0;                               // Inicializa el puerto B en cero
   LCD_INIT();                            // Inicializa el LCD
   LCD_PUTC("\f");                        // Borrar el contenido del LCD
  
   WHILE(TRUE)
   {
       LCD_GOTOXY(1,1);                   // En la fila 1
       LCD_PUTC(" GUIA EN PIC C  ");      // Muestre el mensaje “GUIA EN 
       LCD_GOTOXY(1,2);                   // Ubicarse en la columna 1 fila 2
       LCD_PUTC("      EAFIT     ");      // Sacar el mensaje “EAFIT”
   }                                      //Cierra while true
}   

