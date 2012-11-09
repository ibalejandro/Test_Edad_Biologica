//Ejemplo 16.5  LCD y teclado.

//Digitar una clave en el teclado telef�nico, en el LCD mostrar si es correcta 
//o incorrecta. En el momento de estar digitando la clave en el LCD se 
//muestran asteriscos en vez de los n�meros.

#INCLUDE <16f886.h>
#USE     DELAY(CLOCK=4000000)
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,NOPUT,NOLVP
#DEFINE  USE_PORTB_LCD TRUE
#DEFINE  USE_PORTB_KBD           // Se a�ade esta instrucci�n porque por defecto 
                                 // el teclado se conecta al puerto D en este 
                                 // caso se esta usando el  puerto B.*/
#INCLUDE<KBD.C>                  // Incluir en el encabezado el driver para 
                                 // manejar el teclado telef�nico:*/
#INCLUDE<LCD.C>
#BYTE    PORTC= 7
#BYTE    PORTB= 6
#BYTE    WPUB=0x95
#DEFINE  LED1  PORTC,7
#DEFINE  LED2  PORTC,4

INT CONT;
BYTE J=16;
CHAR K;
INT MIL,CEN,DEC,UNI,VAL;

VOID TECLADO()
{
   k=kbd_getc();                 // Llamar la funci�n del teclado y almacenar 
                                 // el valor digitado en una variable tipo 
                                 // caracter. Si no se oprime ninguna tecla el 
                                 // teclado retornara el car�cter nulo.*/
   WHILE(k=='\0')                // si no se oprime ninguna tecla sigue 
                                 // llamando al teclado.
   {
      k=kbd_getc();
   }
   IF( (k!='\0'))         
   {
   IF(K=='0')                    // Si K es igual a cero 
      VAL=0;                     // Val es igual a cero
   IF(K=='1')
      VAL=1;
   IF(K=='2')
      VAL=2;
   IF(K=='3')
      VAL=3;
   IF(K=='4')
      VAL=4;
   IF(K=='5')
      VAL=5;
   IF(K=='6')
      VAL=6;
   IF(K=='7')
      VAL=7;
   IF(K=='8')
      VAL=8;
   IF(K=='9')
      VAL=9;
  }
}

VOID MAIN()
{
   PORT_B_PULLUPS(TRUE);         // En el programa principal habilitar las 
                                 // resistencias pullup del puerto B, con esto    
                                 // simplemente se habilitan internamente unas 
                                 // resistencias del puerto B a +V.*/
   WPUB=255;   
   SET_TRIS_C(0B00000000);
   KBD_INIT();                   // Inicializar el driver del teclado en el 
                                 // programa principal
   LCD_INIT();
   PORTC=0;
   
   WHILE(TRUE)
   {
      LCD_GOTOXY(1,1);
      LCD_PUTC("   BIENVENIDOS  ");
      LCD_GOTOXY(1,2);
      LCD_PUTC(" DIGITE  CLAVE  ");
      DELAY_MS(1000);

      TECLADO();
      LCD_PUTC("\f");
      LCD_GOTOXY(1,1);

      IF((k!='#')&&(k!='*'))
      {
         lcd_putc('*');
         UNI=VAL;
      }
      TECLADO();

      IF((k!='#')&&(k!='*'))
      {
         lcd_putc('*');
         DEC=VAL;
      }
      TECLADO();
      
      IF((k!='#')&&(k!='*'))
      {
         lcd_putc('*');
         CEN=VAL;
      }
      TECLADO();
      
      IF((k!='#')&&(k!='*'))
      {
         lcd_putc('*');
         MIL=VAL;
      }
      
      TECLADO();
      
      WHILE((k!='#'))
      {
         TECLADO();
      }
    
      IF((UNI==1)&&(DEC==2)&&(CEN==3)&&(MIL==4))  // Aqu� se compara si
                                                  // los n�meros digitados 
                                                  // est�n correctos.*/
      {
         LCD_PUTC("\f");                          // Se borra LCD
         LCD_GOTOXY(1,1);                         // Se ubica en la posici�n 1,1
         LCD_PUTC(" CLAVE CORRECTA ");
         BIT_SET(LED1);
         DELAY_MS(2000);
         BIT_CLEAR(LED1);
      }
    
      ELSE
      {
         LCD_PUTC("\f");
         LCD_GOTOXY(1,2);
         LCD_PUTC(" CLAVE INVALIDA ");
         BIT_SET(LED2);
         DELAY_MS(4000);
         BIT_CLEAR(LED2);
      }
   }
}

