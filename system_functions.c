 // FileName:        system_functions.c
 // Dependencies:    system.h
 // Processor:       MSP432
 // Board:           MSP43P401R
 // Program Version: CCS V8.3 TI
 // Company:         Texas Instruments
 // Authors:         José Luis Chacón M. y Jesús Alejandro Navarro Acosta.
 // Updated:         12/2018

#include "system.h"

void System_InicialiceIO(void)
{
    GPIO_init_board();
}

void System_InicialiceUART (void)
{
    UART_init();
}

void funcion_inicial (void)
{
    GPIO_setOutput(BSP_LED1_PORT,  BSP_LED1,  1);
    GPIO_setOutput(BSP_LED2_PORT,  BSP_LED2,  0);
    GPIO_setOutput(BSP_LED3_PORT,  BSP_LED3,  0);
    GPIO_setOutput(BSP_LED4_PORT,  BSP_LED4,  0);
    UART_putsf(MAIN_UART, "Hola version 8.\r\n");
    printf("\nLaboratorio 1 de la Unidad 2\n");
    printf("Equipo 1\n");
    printf("Sebastian De la Cruz Delgado\n");
    printf("Julian Emilio Gutierrez Loya\n");
    printf("Abril / 2023\n");
}

/*FUNCTION******************************************************************************
*
* Function Name    : process_events
* Returned Value   : None.
* Comments         :
*
*END***********************************************************************************/
uint8_t i = 0;
uint8_t j = 0;
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
