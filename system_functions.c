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
    static bool bandera_blink = FALSE; // Declara una variable boleana estática en FALSE

    if(GPIO_getInputPinValue(BSP_BUTTON1_PORT, BSP_BUTTON1) != BOARD_BUTTON_NORMAL_STATE) // Entra cuando se presiona el botón 1.
    {
        i++;//Incrementar la variable i

        if (i==1)//si se presiona el boton 1 una vez
        {
            if(bandera_blink == FALSE)
                   {
                       bandera_blink = TRUE; // CAMBIA EL ESTADO DE LA VARIABLE ESTATICA
                       GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 1); // LED VERDE ON
                       GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 0); // LED ROJO OFF
                       GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 0); // LED AZUL OFF

                   }
        }


        else
        {
            bandera_blink = FALSE; // REGRESA EL ESTADO DE LA VARIABLE A FALSE

        }

        if (i==2)//si se presiona el boton 1 dos veces
        {
            if(bandera_blink == FALSE)
            {
                bandera_blink = TRUE; // CAMBIA EL ESTADO DE LA VARIABLE ESTATICA
                GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 0); // LED VERDE OFF
                GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 1); // LED ROJO ON
                GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 1); // LED AZUL ON
            }
        }

        else

        {
            bandera_blink = FALSE; // REGRESA EL ESTADO DE LA VARIABLE A FALSE
        }

        if (i==3)//si se presiona el boton 1 tres veces
                {
                    if(bandera_blink == FALSE)
                    {
                        bandera_blink = TRUE; // CAMBIA EL ESTADO DE LA VARIABLE ESTATICA
                        GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 0); // LED VERDE OFF
                        GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 0); // LED ROJO OFF
                        GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 1); // LED AZUL ON
                    }
                }

                else

                {
                    bandera_blink = FALSE; // REGRESA EL ESTADO DE LA VARIABLE A FALSE
                }

        if(i==4)//si se presiona el boton 1 cuatro veces
        {

            i=0; //se les asigna el valor de cero a las variables i,j con la finalidad de reiniciar la cuenta de ambas
            j=0;

            //Parpadea 3 veces
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 0); // LED VERDE OFF
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 0); // LED ROJO OFF
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 1); // LED AZUL ON
            _delay_cycles(5000000);// delay de ciclos

            GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 0); // LED VERDE OFF
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 0); // LED ROJO OFF
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 0); // LED AZUL OFF
            _delay_cycles(5000000);// delay de ciclos

            GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 0); // LED VERDE OFF
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 0); // LED ROJO OFF
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 1); // LED AZUL ON
            _delay_cycles(5000000);// delay de ciclos

            GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 0); // LED VERDE OFF
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 0); // LED ROJO OFF
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 0); // LED AZUL OFF
            _delay_cycles(5000000);// delay de ciclos

            GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 0); // LED VERDE OFF
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 0); // LED ROJO OFF
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 1); // LED AZUL ON
            _delay_cycles(5000000);// delay de ciclos

            GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 0); // LED VERDE OFF
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 0); // LED ROJO OFF
            GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 0); // LED AZUL OFF

            }





        while(GPIO_getInputPinValue(BSP_BUTTON1_PORT, BSP_BUTTON1) != BOARD_BUTTON_NORMAL_STATE);
    }


    if(GPIO_getInputPinValue(BSP_BUTTON2_PORT, BSP_BUTTON2) !=BOARD_BUTTON_NORMAL_STATE) // Entra cuando se presiona el botón 2.
    {

        j++;//Incrementar la variable j

                if (j==1)//si se presiona el boton 2 una vez
                {
                    if(bandera_blink == FALSE)
                           {
                               bandera_blink = TRUE; // CAMBIA EL ESTADO DE LA VARIABLE ESTATICA
                               GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 1); // LED ROJO ON
                               GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 0); // LED VERDE OFF
                               GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 0); // LED AZUL OFF


                           }
                }


                else
                {
                    bandera_blink = FALSE; // REGRESA EL ESTADO DE LA VARIABLE A FALSE

                }

                if (j==2)//si se presiona el boton 2 dos veces
                {
                    if(bandera_blink == FALSE)
                    {
                        bandera_blink = TRUE; // CAMBIA EL ESTADO DE LA VARIABLE ESTATICA
                        GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 1); // LED VERDE ON
                        GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 1); // LED AZUL ON
                        GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 0); // LED ROJO OFF

                    }
                }

                else

                {
                    bandera_blink = FALSE; // REGRESA EL ESTADO DE LA VARIABLE A FALSE
                }

                if (j==3)//si se presiona el boton 2 tres veces
                        {
                            if(bandera_blink == FALSE)
                            {
                                bandera_blink = TRUE; // CAMBIA EL ESTADO DE LA VARIABLE ESTATICA
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 1); // LED VERDE ON
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 1); // LED ROJO ON
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 0); // LED AZUL OFF
                            }
                        }

                        else

                        {
                            bandera_blink = FALSE; // REGRESA EL ESTADO DE LA VARIABLE A FALSE
                        }

                if(j==4)//si se presiona el boton 2 cuatro veces
                {

                                i=0;//se les asigna el valor de cero a las variables i,j con la finalidad de reiniciar la cuenta de ambas
                                j=0;
                                //Parpadea 3 veces
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 1); // LED VERDE ON
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 1); // LED ROJO ON
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 0); // LED AZUL OFF
                                _delay_cycles(5000000);// delay de ciclos

                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 0); // LED VERDE OFF
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 0); // LED ROJO OFF
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 0); // LED AZUL OFF
                                _delay_cycles(5000000);// delay de ciclos

                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 1); // LED VERDE ON
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 1); // LED ROJO ON
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 0); // LED AZUL OFF
                                _delay_cycles(5000000);// delay de ciclos

                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 0); // LED VERDE OFF
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 0); // LED ROJO OFF
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 0); // LED AZUL OFF
                                _delay_cycles(5000000);// delay de ciclos

                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 1); // LED VERDE ON
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 1); // LED ROJO ON
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 0); // LED AZUL OFF
                                _delay_cycles(5000000);// delay de ciclos

                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED3, 0); // LED VERDE OFF
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, 0); // LED ROJO OFF
                                GPIO_setOutput(BSP_LED2_PORT, BSP_LED4, 0); // LED AZUL OFF



                }




                while(GPIO_getInputPinValue(BSP_BUTTON2_PORT, BSP_BUTTON2) != BOARD_BUTTON_NORMAL_STATE);



    }


}
