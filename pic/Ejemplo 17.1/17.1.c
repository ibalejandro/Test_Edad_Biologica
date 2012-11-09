//Ejemplo 17.1 Memoria eeprom interna

//Hacer un programa que:
//Si RC3=1, inicializa el contador y la dirección de memoria.
//Si RC0=1, almacena un contador de 0 a 14.
//Si RC2=1, almacena números pares de 0 a 14. 
//Si RC1=1, muestra el valor almacenado
 

#INCLUDE <16F886.H>
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP,WRT
#USE     DELAY(CLOCK=4000000)
#BYTE    PORTC= 7
#BYTE    PORTB= 6
INT CONT,DIRECCION,CONT2;              // Declarar las variable CONT,       
                                       // DIRECCION, CONT2 como un entero
VOID MAIN()
{
   SET_TRIS_C(0B11111111);             // Configura el puerto C como entrada
   SET_TRIS_B(0);                      // Configura el puerto B como salida
   PORTB=0;                            // Poner el puerto B en 0
   CONT=0;                             // Poner la variable CONT en cero
   DIRECCION=0;                        // Poner la variable DIRECCION en cero
   CONT2=2;                            // Poner la variable CONT2 en dos
   WHILE (TRUE)                        // LOOP INFINITO
   {      
      IF(BIT_TEST(PORTC,3))            // Si el bit 3 del puerto C esta en 1
      {
         CONT=0;                       // Poner la variable CONT en cero
         DIRECCION=0;                  // Poner la variable DIRECCION en cero
      }
      
      IF(BIT_TEST(PORTC,0)&&(CONT<15)) // Si RC0=1 y la variable CONT es
                                       //menor que 15
      {
         WRITE_EEPROM(DIRECCION,CONT); // Escribir en eeprom el valor de CONT
         DELAY_MS(500);                // Retardo de 500 milisegundos
         CONT++;                       // Incrementa la variable CONT
         DIRECCION++;                  // Incrementa la variable DIRECCION   
         PORTB=CONT;                   // Lo que hay en CONT llévelo al puerto B
      }
      
      IF(BIT_TEST(PORTC,2)&&(CONT<15)) // Si RC2=1 y la variable CONT es menor que 15
      {
         WRITE_EEPROM(DIRECCION,CONT2);   
         DELAY_MS(500);                // Retardo de 500 milisegundos
         CONT2=CONT2+2;                // Incrementa en dos la variable CONT2 
         CONT++;                       // Incrementa la variable CONT
         DIRECCION++;                  // Incrementa la variable DIRECCION
         PORTB=CONT2;                  // Lo que hay en CONT2 llévelo al puerto B
      }      
      
      IF(BIT_TEST(PORTC,1)&&(CONT<15)) // Si RC1=1 y la variable CONT es menor que 15
      {
         CONT=0;                       // Poner la variable CONT en cero
         DIRECCION=0;                  // Poner la variable DIRECCION en cero
         WHILE(CONT<15)                // Mientras que CONT sea menor a 15
         {
            PORTB=READ_EEPROM(DIRECCION);   
            DELAY_MS(500);             // Retardo de 500 milisegundos
            CONT++;                    // Incrementa la variable CONT
            DIRECCION++;               // Incrementa la variable DIRECCION
         }
      } 
   }
}

