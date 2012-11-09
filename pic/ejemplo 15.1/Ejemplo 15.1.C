//Ejemplo 15.1 Teclado telefónico.
//Mostrar en un display 7 segmentos el valor digitado en el teclado.
 
#INCLUDE <16F886.H>
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
#USE     DELAY(CLOCK=4000000)
Byte CONST display[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
#DEFINE  USE_PORTB_KBD
#INCLUDE <KBD.C>
#BYTE    PORTC= 7
#BYTE    PORTB= 6
#BYTE    WPUB=0x95
CHAR K;

VOID MAIN()
{
   PORT_B_PULLUPS(TRUE);         // Habilitar resistencias del puerto B a           
   WPUB=255;                     // positivo
   KBD_INIT();                   // Inicializar la rutina del teclado
   SET_TRIS_C(0);                // Configurar el puerto C como salida
   PORTC=(display[0]);           // Muestra el cero en el display
   
   WHILE (TRUE)
   {
      K=KBD_GETC();              // Captura cualquier tecla oprimida
      IF(K=='0')                 // Si la tecla que se oprime es igual al
                                 // caracter cero
      PORTC=(display[0]);        // Muestre en el display el número cero
      IF(K=='1')                 // Si la tecla que se oprime es igual al 
                                 // caracter uno
      PORTC=( display[1]);       // Muestre en el display el número uno
      IF(K=='2')                 // Tecla que se oprime igual al 
                                 // caracter dos
      PORTC=( display[2]);       // Muestre en el display el número dos
      IF(K=='3' )                // Tecla que se oprime igual al caracter tres
      PORTC=( display[3]);       // Muestre en el display el número tres
      IF(K=='4')                 // Tecla que se oprime igual caracter  
                                 // cuatro
      PORTC=( display[4]);       // Muestre en el display el número cuatro
      IF(K=='5')                 // Tecla que se oprime igual caracter 
                                 // cinco
      PORTC=( display[5]);       // Muestre en el display el número cinco
      IF(K=='6')                 // Tecla que se oprime igual caracter                                 
                                 // seis
      PORTC=( display[6]);       // Muestre en el display el número seis
      IF(K=='7')                 // Tecla que se oprime igual caracter 
                                 // siete
      PORTC=( display[7]);       // Muestre en el display el número siete
      IF(K=='8')                 // Tecla que se oprime igual caracter 
                                 // ocho
      PORTC=( display[8]);       // Muestre en el display el número ocho
      IF(K=='9')                 // Tecla que se oprime igual caracter 
                                 // nueve
      PORTC=( display[9]);       // Muestre en el display el número nueve
   }
}

