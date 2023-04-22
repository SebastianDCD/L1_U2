 // FileName:        system_Thread.c
 // Dependencies:    system.h
 // Processor:       MSP432
 // Board:           MSP43P401R
 // Program Version: CCS V8.3 TI
 // Company:         Texas Instruments
 // Description:     Definici�n de las funciones del thread System_Thread().
 // Authors:         Jos� Luis Chac�n M. y Jes�s Alejandro Navarro Acosta.
 // Updated:         12/2018


/* EXPLICACION DEL PROGRAMA DE LA PLANTILLA.
 *  Plantilla de ejemplo: Enciende el led rojo del pin 1.0.
 *  imprime "Hello World" y ejecuta constantemente process_events(),
 *  que espera que se presione el bot�n de la izquierda del pin 1.1,
 *  haciendo un toggle cada vez que se presiona prendiendo
 *  y apagando el led rojo del pin 2.0.
 */


#include "system.h"

void *System_Thread(void *arg0);

/*********************************THREAD*************************************
 * Function: System_Thread
 * Preconditions: None.
 * Input:  Apuntador vac�o que puede referenciarse a cualquier tipo de dato.
 * Output: None.
 *
 *****************************************************************************/

void *System_Thread(void *arg0)
{
   bool flag = TRUE;

   /* Inicia el sistema (funci�n predeterminada). */
   SystemInit();

   /* Inicializa drivers de objetos. */
   System_InicialiceIO();
   System_InicialiceUART();

   if(flag != TRUE)
   {
       printf("Error al crear archivos. Cierre del programa\r\n");
       exit(1);
   }

   funcion_inicial();

   /* M�quina de estados sincronizada. */
   while(TRUE)
   {
       process_events();
       usleep(1000);
   }
}
