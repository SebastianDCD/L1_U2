 // FileName:        Threads.c
 // Dependencies:    system.h
 // Processor:       MSP432
 // Board:           MSP43P401R
 // Program Version: CCS V8.3 TI
 // Company:         Texas Instruments
 // Description:     Activa las funciones del hilo System_Thread.
 //                  Main del proyecto.
 // Authors:         Jos� Luis Chac�n M. y Jes�s Alejandro Navarro Acosta.
 // Updated:         12/2018

#include "system.h"

extern void *System_Thread(void *arg0);   // Funciones de threads que arrancar�n inicialmente.

int main(void)
 {
    pthread_t           system_thread;
    pthread_attr_t      pAttrs;
    struct sched_param  priParam;
    int                 retc;
    int                 detachState;

   pthread_attr_init(&pAttrs);                                  /* Reinicio de par�metros. */

   detachState = PTHREAD_CREATE_DETACHED;                       // Los recursos se liberar�n despu�s del t�rmino del thread.
   retc = pthread_attr_setdetachstate(&pAttrs, detachState);    // Adem�s, al hilo no se le puede unir otro (join).
   if (retc != 0) { while (1); }

   /**********************
   ** Thread principal. **
   **********************/

   priParam.sched_priority = 1;                                         // Prioridad de la tarea principal.
   retc |= pthread_attr_setstacksize(&pAttrs, THREADSTACKSIZE1);        // As� se determinar�a el tama�o del stack.
   if (retc != 0) { while (1); }
   pthread_attr_setschedparam(&pAttrs, &priParam);
   retc = pthread_create(&system_thread, &pAttrs, System_Thread, NULL); // Creaci�n del thread.
   if (retc != 0) { while (1); }

   /* Arranque del sistema. */
   BIOS_start();
   return (0);
}
