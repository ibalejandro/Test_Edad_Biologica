//Ejemplo 15.6  LCD y teclado.

//Mostrar en el LCD los n�meros digitados por el teclado telef�nico, 
//hasta completar 16 n�meros.


#INCLUDE <16F886.h>
#USE     DELAY(CLOCK=4000000)
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,NOPUT,NOLVP
#DEFINE  USE_PORTB_LCD TRUE
#DEFINE  USE_PORTB_KBD     // Por defecto el teclado se conecta al puerto D, 
                           // como el microcontrolador que se esta usando 
                           // no tiene  puerto D se conecta al puerto B.*/
#INCLUDE <LCD.C>
#INCLUDE <KBD.C>           // Incluir en el encabezado el driver para 
                           // manejar el teclado telef�nico:*/
#BYTE    PORTC= 7
#DEFINE  INC PORTC,0
#DEFINE  DEC PORTC,1
#DEFINE  START PORTC,2
CHAR K;
INT DIR;

VOID MAIN()
{
   port_b_pullups(TRUE);   // En el programa principal habilitar las 
                           // resistencias pullup del puerto B, con esto          
                           // simplemente se habilitan  internamente  unas 
                           // resistencias del puerto B a +V.*/
   SET_TRIS_C(255);
   LCD_INIT();
   KBD_INIT();             // Inicializar el driver del teclado en el 
                           // programa principal
   LCD_PUTC("\f");
   
   WHILE(TRUE)
   {
   DIR=0;
   LCD_PUTC("\f");
   
      while (DIR<17)
      {
         k=kbd_getc();     // Llamar la funci�n del teclado y almacenar el 
                           // valor digitado en una variable tipo car�cter. Si 
                           // no se oprime ninguna tecla el teclado
                           // retornara el car�cter nulo.*/
         WHILE( (k=='\0')) // si no se oprime ninguna tecla sigue 
                           // llamando al teclado.
         {
            k=kbd_getc();
         }
         
         if( (k!='*')&&(k!='#'))
         {
            lcd_putc(k);
            DIR++;
         }
      }
   }
}

