 // FileName:        system_functions.c
 // Dependencies:    system.h
 // Processor:       MSP432
 // Board:           MSP43P401R
 // Program Version: CCS V8.3 TI
 // Company:         Texas Instruments
 // Authors:         José Luis Chacón M. y Jesús Alejandro Navarro Acosta.
 // Updated:         12/2018

#include "system.h"

/* EXPLICACION DEL PROGRAMA DE LA PLANTILLA.
 *  Plantilla de ejemplo: Enciende el led rojo del pin 1.0.
 *  imprime "Hello World" y ejecuta constantemente process_events(),
 *  que espera que se presione el botón de la izquierda del pin 1.1,
 *  haciendo un toggle cada vez que se presiona prendiendo
 *  y apagando el led rojo del pin 2.0.
 */


/*FUNCTION*********************************************************************************
*
* Function Name    : System_InicialiceIO
* Returned Value   : None.
* Comments         :
*
*END****************************************************************************************/

void System_InicialiceIO(void)
{
    GPIO_init_board();
}

/*FUNCTION******************************************************************************
*
* Function Name    : System_InicialiceUART
* Returned Value   : None.
* Comments         :
*
*END***********************************************************************************/
void System_InicialiceUART (void)
{
    UART_init();
}

/*FUNCTION******************************************************************************
*
* Function Name    : funcion_inicial
* Returned Value   : None.
* Comments         :
*
*END***********************************************************************************/

void funcion_inicial (void)
{
    GPIO_setOutput(BSP_LED1_PORT,  BSP_LED1,  1);
    GPIO_setOutput(BSP_LED2_PORT,  BSP_LED2,  0);
    GPIO_setOutput(BSP_LED3_PORT,  BSP_LED3,  0);
    GPIO_setOutput(BSP_LED4_PORT,  BSP_LED4,  0);
    UART_putsf(MAIN_UART, "Hola version 8.\r\n");
    printf("Hello\n");
}

/*FUNCTION******************************************************************************
*
* Function Name    : process_events
* Returned Value   : None.
* Comments         :
*
*END***********************************************************************************/

void process_events(void)
{
    static bool bandera_blink = FALSE;

    if(GPIO_getInputPinValue(BSP_BUTTON1_PORT, BSP_BUTTON1) != BOARD_BUTTON_NORMAL_STATE) // Entra cuando se presiona el botón 1.
    {
        if(bandera_blink == FALSE)
        {
            bandera_blink = TRUE;
            GPIO_setOutput(BSP_LED2_PORT,  BSP_LED2,  1);
        }

        else
        {
            bandera_blink = FALSE;
            GPIO_setOutput(BSP_LED2_PORT,  BSP_LED2,  0);
        }

        while(GPIO_getInputPinValue(BSP_BUTTON1_PORT, BSP_BUTTON1) != BOARD_BUTTON_NORMAL_STATE);
    }
}
