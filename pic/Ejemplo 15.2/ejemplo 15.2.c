//Ejemplo15.2 Teclado telefónico.

//Mostrar el numero digitado por el teclado en el display y cuando se oprima la
// tecla #, el display comienza a decrementar cada segundo hasta llegar a cero.

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
INT CONT;

VOID MAIN()
{
   PORT_B_PULLUPS(TRUE);               // Habilitar resistencias del puerto B a           
   WPUB=255;                           // positivo
   
   KBD_INIT();                         // Inicializar la rutina del teclado
   SET_TRIS_C(0B00000000);             // Configurar el puerto C como salida
   CONT=0;                             // Carga el contador con cero
   PORTC=(display[CONT]);              // Muestra el cero en el display
   
   WHILE (TRUE)
   {
      K=KBD_GETC();
      IF(K=='0')                       // Si la tecla que se oprime es
                                       // igual al caracter uno
      {
         CONT=0;      
         PORTC=( display [CONT]);      // Muestre en el display el uno
      } 
      IF(K=='1')                       // Si la tecla que se oprime es igual al 
                                       // caracter uno
      {
         CONT=1;      
         PORTC=( display [CONT]);      // Muestre en el display el número uno
      } 
      IF(K=='2')                       // Si la tecla que se oprime es igual 
                                       // al caracter dos
      {
         CONT=2;      
         PORTC=( display [CONT]);      // Muestre en el display el número dos
      } 
      IF(K=='3')                       // Si la tecla que se oprime es igual a
                                       // al caracter tres
      {
         CONT=3;       
         PORTC=( display [CONT]);      // Muestre en el display el número tres

      } 
      IF(K=='4')                       // Si la tecla que se oprime es igual 
                                       // al caracter cuatro
      {
         CONT=4;      
         PORTC=( display [CONT]);      // Muestre en el display el número cuatro
      } 
      IF(K=='5')                       // Si la tecla que se oprime es igual al 
                                       // caracter cinco
      {
         CONT=5;       
         PORTC=( display [CONT]);      // Muestre en el display el número cinco

      }
      IF(K=='6')                       // Si la tecla que se oprime es igual 
                                       // al caracter seis
      {
         CONT=6;       
         PORTC=( display [CONT]);      // Muestre en el display el seis
      } 
      IF(K=='7')                       // Si la tecla que se oprime es igual 
                                       // al caracter siete
      {
         CONT=7;       
         PORTC=( display [CONT]);      // Muestre en el display el número
                                       // siete
      } 
      IF(K=='8')                       // Si la tecla que se oprime es igual 
                                       // al caracter ocho
      {
         CONT=8;      
         PORTC=( display [CONT]);      // Muestre en el display el número ocho
      } 
      IF(K=='9')                       // Si la tecla que se oprime es igual 
                                       // al caracter nueve
      {
         CONT=9;      
         PORTC=( display [CONT]);      // Muestre en el display el número nueve   
      }
      IF(K=='#')                       // Si la tecla que se oprime es igual
                                       // al caracter #
      {
         WHILE(CONT>0)                 // Mientras el contador sea mayor a cero
         {
            DELAY_MS(1000);            // Llama retardo de un segundo
            CONT--;                    // Decrementa el contador
            PORTC=( display [CONT]);   // Muestra el contador en el display.
         }
      }
   }
}
