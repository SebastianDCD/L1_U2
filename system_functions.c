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
    //----------------------------------------//
    printf("//-------------------------//\n\tInstrucciones:\n");
    printf("Dos veces boton 1, LED ROJO\n");
    printf("Una vez boton 2, LED AZUL\n");
    printf("Dos veces boton 2, LED AMARILLO\n");
    printf("Tres veces cualquier boton, LED OFF, Cuentas reiniciadas");
}

//Declaracion de variables para contadores de pulsaciones de cada Switch/Push B
uint8_t SW_1 = 0;
uint8_t SW_2 = 0;

void process_events(void)
{
static bool bandera_blink = FALSE;
    //---------Control_PB_1------------//
    if(GPIO_getInputPinValue(BSP_BUTTON1_PORT, BSP_BUTTON1) != BOARD_BUTTON_NORMAL_STATE) // Entra cuando se presiona el botón 1.
    {
        SW_1 = SW_1 + 1;    //Incrementamos en 1 el contador cada que el Switch 1 sea pulsado

        //Caso 1, con un pulso en Switch 1, no realiza nada

        //Caso 2, con dos pulsos en SW 2, Enciende color Rojo
        if( SW_1 == 2)
        {
            if(bandera_blink == FALSE)
            {
                bandera_blink = TRUE;   //Cambiamos estado de la bandera
                GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 1); //RGB_RED_OFF
                GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 0); //RGB_GREEN_OFF
                GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 0); //RGB_BLUE_OFF
            }
        }
        else
        {
            bandera_blink = FALSE; // REGRESA EL ESTADO DE LA VARIABLE A FALSE
        }


        while(GPIO_getInputPinValue(BSP_BUTTON1_PORT, BSP_BUTTON1) != BOARD_BUTTON_NORMAL_STATE);
    }
    //---------Control_PB_2------------//
    if(GPIO_getInputPinValue(BSP_BUTTON2_PORT, BSP_BUTTON2) !=BOARD_BUTTON_NORMAL_STATE) // Entra cuando se presiona el botón 2.
    {
    SW_2 = SW_2 + 1;    //Incrementamos en 1 cada que el Switch 2 es pulsado

    //Caso 1 con un pulso enciende RGB_AZUL:
    if( SW_2 == 1)
    {
        if(bandera_blink == FALSE)
        {
            bandera_blink = TRUE;   //Cambiamos estado de la bandera
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 0); //RGB_RED_OFF
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 0); //RGB_GREEN_OFF
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 1); //RGB_BLUE_ON
        }
    }
    else
    {
        bandera_blink = FALSE; // REGRESA EL ESTADO DE LA VARIABLE A FALSE
    }
    //Caso 3 con un pulso enciende RGB_AMARILLO:
    if( SW_2 == 2)
            {
                if(bandera_blink == FALSE)
                {
                    bandera_blink = TRUE;   //Cambiamos estado de la bandera
                    GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 1); //RGB_RED_ON
                    GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 1); //RGB_GREEN_ON
                    GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 0); //RGB_BLUE_OFF
                }
            }
            else
            {
                bandera_blink = FALSE; // REGRESA EL ESTADO DE LA VARIABLE A FALSE
            }
    while(GPIO_getInputPinValue(BSP_BUTTON2_PORT, BSP_BUTTON2) != BOARD_BUTTON_NORMAL_STATE);
    }
}
