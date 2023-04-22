 // FileName:        UART_MSP432.c
 // Dependencies:    system.h
 // Processor:       MSP432
 // Board:			 MSP432P401R
 // Program version: CCS V8.3 TI
 // Company:         Texas Instruments
 // Description:     Definici�n de funciones del m�dulo UART, siendo imprescindible el uso de UART_init().
 // Authors:         Jos� Luis Chac�n M. y Jes�s Alejandro Navarro Acosta.
 // Updated:         11/2018

#include "system.h"     // Configuraci�n del sistema.


const uint32_t BRX[]  = {78, 19, 6};                    // Constantes para la determinaci�n del Baud Rate.
const uint32_t BRFX[] = {2,  8,  8};                    // (Technical Reference Manual - Pag 918).
const uint32_t BRS[]  = {0x0000, 0x0065, 0x0020};       // Definido para 12 MHz (BRCLK). CAMBIE SEGUN DISE�O.


/**************************************/
/* FUNCIONES QUE CONFIGURAN EL UART.  */
/**************************************/

/*****************************************************************************
 * Function: UART_data_bits
 * Preconditions: None.
 * Overview: Establece el n�mero de bits de datos.
 * Input:  Bool del numero de bits deseados (0 para 8 bits, 1 para 7 bits).
 * Output: None.
 *****************************************************************************/
void UART_data_bits(bool data_bits)
{
    BITBAND_PERI(EUSCI_A_CMSIS(EUSCI_A0)-> CTLW0, UC7BIT) = data_bits;
}

/*****************************************************************************
 * Function: UART_clck_source
 * Preconditions: None.
 * Overview: Establece de donde se toma el reloj del puerto.
 * Input:  Enum con la selecci�n del reloj.
 * Output: None.
 *****************************************************************************/
void UART_clck_source(Clk_source source)
{
    switch(source)
    {
        case U_CLK:  EUSCI_A_CMSIS(EUSCI_A0) -> CTLW0 = (EUSCI_A_CMSIS(EUSCI_A0) -> CTLW0 & ~UCSSEL_3) | EUSCI_A_CTLW0_SSEL__UCLK;  break;
        case A_CLK:  EUSCI_A_CMSIS(EUSCI_A0) -> CTLW0 = (EUSCI_A_CMSIS(EUSCI_A0) -> CTLW0 & ~UCSSEL_3) | EUSCI_A_CTLW0_SSEL__ACLK;  break;
        case SM_CLK: EUSCI_A_CMSIS(EUSCI_A0) -> CTLW0 = (EUSCI_A_CMSIS(EUSCI_A0) -> CTLW0 & ~UCSSEL_3) | EUSCI_A_CTLW0_SSEL__SMCLK; break;
        default: break;
    }
}

/*****************************************************************************
 * Function: UART_mode
 * Preconditions: None.
 * Overview: Establece de donde se toma el reloj del puerto.
 * Input:  Bool que indique modo s�ncrono (1) o as�ncrono (0).
 * Output: None.
 *****************************************************************************/
void UART_mode(bool synchronization)
{
    BITBAND_PERI(EUSCI_A_CMSIS(EUSCI_A0) -> CTLW0, EUSCI_A_CTLW0_SYNC) = synchronization;
}

/*****************************************************************************
 * Function: UART_B_char_IE
 * Preconditions: None.
 * Overview: Pone en alto la interrupci�n por car�cteres 'break'.
 * Input:  Bool que indique si la interrupci�n se habilita (1) o no (0).
 * Output: None.
 *****************************************************************************/
void UART_B_char_IE(bool interruption)
{
    BITBAND_PERI(EUSCI_A_CMSIS(EUSCI_A0) -> CTLW0, EUSCI_A_CTLW0_RXEIE_OFS) = interruption;
}


/*****************************************************************************
 * Function: UART_E_char_IE
 * Preconditions: None.
 * Overview: Pone en alto la interrupci�n por car�cteres err�neos.
 * Input:  Bool que indique si la interrupci�n se habilita (1) o no (0).
 * Output: None.
 *****************************************************************************/
void UART_E_char_IE(bool interruption)
{
    BITBAND_PERI(EUSCI_A_CMSIS(EUSCI_A0) -> CTLW0, EUSCI_A_CTLW0_BRKIE_OFS) = interruption;
}


/*****************************************************************************
 * Function: UART_set_oversampling
 * Preconditions: None.
 * Overview: Establece si se debe contemplar sobremuestreo.
 * Input:  Bool que indique si se contempla sobremuestreo.
 * Output: None.
 *****************************************************************************/
void UART_set_oversampling(bool oversampling)
{
    BITBAND_PERI(EUSCI_A_CMSIS(EUSCI_A0) -> MCTLW, EUSCI_A_MCTLW_OS16_OFS) = oversampling;
}


/*****************************************************************************
 * Function: UART_set_parity
 * Preconditions: None.
 * Overview: Establece tipo de paridad.
 * Input:  Char que indique tipo de paridad; viene definida como un enum.
 * Output: None.
 *****************************************************************************/
void UART_set_parity(char parity)
{
    if(parity > 0)
    {
        BITBAND_PERI(EUSCI_A_CMSIS(EUSCI_A0)-> CTLW0, UCPEN_OFS) = 1;
        BITBAND_PERI(EUSCI_A_CMSIS(EUSCI_A0)-> CTLW0, UCPAR_OFS) = parity-1;
    }
    else
        BITBAND_PERI(EUSCI_A_CMSIS(EUSCI_A0)-> CTLW0, UCPEN_OFS) = 0;
}


/*****************************************************************************
 * Function: UART_set_stop_bits
 * Preconditions: None.
 * Overview: Establece el numero de bits de paro en la comunicaci�n.
 * Input:  Bool que indique el n�mero de bits de paro,
 *         (1 bit si est� en 0, 2 bits si est� en 1).
 * Output: None.
 *****************************************************************************/
void UART_set_stop_bits(bool stop_bits)
{
    BITBAND_PERI(EUSCI_A_CMSIS(EUSCI_A0)-> CTLW0, UCSPB_OFS) = stop_bits;
}


/*****************************************************************************
 * Function: UART_set_transmision_dir
 * Preconditions: None.
 * Overview: Establece si se debe contemplar sobremuestreo.
 * Input:  Bool que indique si se debe imprimir primero LSB (0) o MSB (1).
 * Output: None.
 *****************************************************************************/
void UART_set_transmision_dir(bool direction)
{
    BITBAND_PERI(EUSCI_A_CMSIS(EUSCI_A0)-> CTLW0, UCMSB_OFS) = direction;
}


/*****************************************************************************
 * Function: UART_set_location_pin
 * Preconditions: None.
 * Overview: Establece los pines sobre los cuales se transmitir� y recibir�.
 * Input:  Puerto (int), seguido de los pines en una sola variable.
 * Output: None.
 *****************************************************************************/
void UART_set_location_pin(uint32_t selected_port, uint32_t selected_pins)
{
    HWREG16(selected_port + OFS_PADIR) &= ~(selected_pins);
    HWREG16(selected_port + OFS_PASEL0) |= (selected_pins);
    HWREG16(selected_port + OFS_PASEL1) &= ~(selected_pins);
}


/****************************************************************************
 * Function: UART_set_baud_rate
 * Preconditions: None.
 * Overview: Establece un baud rate de las opciones disponibles.
 * Input:  Valor entero con las opciones diferentes (que est�n en un enum).
 *         Estan contemplados para 12 MHz.
 * Output: None.
 *****************************************************************************/
void UART_set_baud_rate(uint8_t standard)
{
    if(standard < MAX_BAUD_RATE_CHANNELS)
    {
       EUSCI_A_CMSIS(EUSCI_A0)-> BRW = BRX[standard];
       EUSCI_A_CMSIS(EUSCI_A0)-> MCTLW = ((BRS[standard] << 8)  + (BRFX[standard] << 4) +  EUSCI_A_MCTLW_OS16);
    }
}

/*******************************************************************************************************
 * Function: UART_init
 * Preconditions: None.
 * Overview: Inicializaci�n y configuraci�n del m�dulo para su uso posterior.
 *           Algunas de las configuraciones incluyen los pines de uso, la fuente de reloj, bits de paro,
 *           paridad, baudrate, sobremuestreo, etc. Configuracion default.
 * Input: None.
 * Output: None.
 *********************************************************************************************************/

void UART_init(void)
{
        UART_den(MAIN_UART);

        /* Forma gen�rica para limpiar interrupciones, sleep, y otros registros inicialmente. */
        EUSCI_A_CMSIS(EUSCI_A0)-> CTLW0 = (EUSCI_A_CMSIS(EUSCI_A0)-> CTLW0 & ~( UCRXEIE | UCBRKIE | UCDORM | UCTXADDR | UCTXBRK)) | EUSCI_A_CTLW0_MODE_0;

        UART_set_location_pin(PORT_1, PINES_PORT_1_UART);         /* Selecci�n de pines. */
        UART_clck_source(SM_CLK);                                 /* Selecci�n de la fuente de reloj. (Bit SMCLK). */
        UART_set_transmision_dir(LSB_FIRST);                      /* Selecci�n de MSB o LSB en orden de transmisi�n (0 para LSB, 1 para MSB). */
        UART_set_stop_bits(ONE_STOP_BIT);                         /* N�mero de bits de paro; UCSPB = 0(1 stop bit) OR 1(2 stop bits). */
        UART_set_parity(NO_PARITY);                               /* Sin paridad entre la comunicaci�n. */

        /* BaudRate trabajar� a 115200. */
        UART_set_baud_rate((uint8_t) BR_115200);
        UART_data_bits(EIGHT_BITS);             /* Seleccion de caracter 8 bits. */
        UART_mode(ASYNCHRONOUS);                /* M�do As�ncrono habilitado.    */
        UART_set_oversampling(OVERSAMPLE);      /* Sobremuestreo (Oversampling). */

        UART_E_char_IE(NO_INTERRUPTION);        /* No hay interrupci�n por caracteres erroneos.  */
        UART_B_char_IE(NO_INTERRUPTION);        /* No hay interrupci�n por caracteres 'break'.   */

        UART_en(MAIN_UART);         /* Habilita el m�dulo. */
}

/*******************************/
/* FUNCIONES QUE USAN EL UART. */
/*******************************/

/*****************************************************************************
 * Function: UART_en
 * Preconditions: uart_main_init()
 * Overview: Est� dise�ada para habilitar el uso del m�dulo UART
 *           poniendo en 0 el valor de reset.
 * Input: uint32_t moduleInstance. (Ejem EUSCI_A0 o EUSCI_A0_BASE).
 * Output: None.
 *
 *****************************************************************************/
void UART_en(uint32_t moduleInstance)
{
    BITBAND_PERI(EUSCI_A_CMSIS(moduleInstance) -> CTLW0 , EUSCI_A_CTLW0_SWRST_OFS) = 0;
}


/*****************************************************************************
 * Function: UART_den
 * Preconditions: uart_main_init()
 * Overview: Est� dise�ada para deshabilitar el uso del m�dulo UART
 *           poniendo en 1 el valor de reset.
 * Input: uint32_t moduleInstance. (Ejem EUSCI_A0 o EUSCI_A0_BASE)
 * Output: None.
 *
 *****************************************************************************/
void UART_den(uint32_t moduleInstance)
{
    BITBAND_PERI(EUSCI_A_CMSIS(moduleInstance) -> CTLW0, EUSCI_A_CTLW0_SWRST_OFS) = 1;
}

/*****************************************************************************
 * Function: UART_send_byte
 * Preconditions: uart_main_init()
 * Overview: Env�o de un unico byte a traves de registros.
 * Input: uint32_t moduleInstance, char *s.
 * Output: None.
 *
 *****************************************************************************/

void UART_sendByte(uint32_t moduleInstance, char c)
{
    /* Funciona mediante interrupciones para la trasmisi�n. */
    if (!BITBAND_PERI(EUSCI_A_CMSIS(moduleInstance) -> IE, EUSCI_A_IE_TXIE_OFS))
         while (!BITBAND_PERI(EUSCI_A_CMSIS(moduleInstance) -> IFG, EUSCI_A_IFG_TXIFG_OFS));
    /* Mientras no se desactive la bandera, seguir� corriendo. */

    /* Realiza la transmisi�n bit a bit. */
     EUSCI_A_CMSIS(moduleInstance)->TXBUF = c;
}

/*****************************************************************************
 * Function: UART_putsf
 * Preconditions: uart_main_init()
 * Overview: Env�o concatenado de datos byte a byte usando un apuntador.
 * Input: uint32_t moduleInstance, char *s.
 * Output: None.
 *
 *****************************************************************************/

void UART_putsf(uint32_t moduleInstance, char *s)
{
    char c;

    while (c = *s++)    // El apuntador va cambiando su valor.
        UART_sendByte(moduleInstance, c);
}

/****************************************************************************************************
 * Function: UART_NumToString
 * Preconditions: None
 * Overview: Transforma un numero flotante o entero (el entero se manda con operando cast (float)) a
 *           una cadena que recibe directamente los valores a trav�s de un apuntador.
 *           Tiene caracteristicas como digitos totales, precision de valores despues del punto
 *           y si es entero (1) o no (0).
 *
 *           NOTA: ES PREFERIBLE USAR SPRINTF(), PERO AQUI SE DEMUESTRA
 *           COMO PODRIA HACERSE UNA PROPIA FUNCI�N DE ESTE ESTILO.
 *
 * Input: float result, char* buffer, int digitos_totales, int max_after_dot_values, int entero.
 * Output: None.
 *
 ******************************************************************************************************/

void UART_NumToString (float result, char* buffer, int digitos_totales, int max_after_dot_values, int entero)
{
    long int value;
    int temp, dot_pos, after_dot_values;
    int scale, scale2, iteration, forcing = 0;
    int restante, division;

    value = (int) (result);     // Usaremos el resultado flotante y el resultado forzado entero.

    // Ciclo para determinar el n�mero de datos antes del punto.
    for(scale = 1, dot_pos = 0; ; dot_pos++, scale *= 10)
    {
        if(value == 0) {break;} // Si el valor ya es cero, se sale del ciclo.
        if(value/scale == 0) {scale /= 10; break;}
    }

    // Ciclo para determinar el n�mero de datos despu�s del punto considerando la precisi�n deseada.
    for(scale2 = 1, after_dot_values = 0; ; after_dot_values++, scale2 *= 10)
    {
        value = (int) (result*scale2);
        if(((value*10) == (int) (result * scale2 * 10)) || after_dot_values >= (max_after_dot_values)) {break;}
    }

    // El escalamiento del siguiente 'for' se hace en base al n�mero de digitos.
    division = (scale*scale2);


    if(dot_pos == 0)
        if(entero == FLOAT_SENDING)
            {*buffer++ = '0'; *buffer++ = '.';} // Asignaci�n del prefijo '.0' si es necesario.

    if((after_dot_values + dot_pos) < digitos_totales)  // Si la precisi�n deseada es mayor a la introducida, se a�aden ceros.
    {
        forcing = digitos_totales - (after_dot_values + dot_pos);
        for(iteration = 0; iteration < forcing; iteration++)
         {
            digitos_totales--;
            if(entero == INTEGER_SENDING)
                *buffer++ = '0';
         }
    }

    else if(digitos_totales < dot_pos)  // Pero si se desea imprimir un n�mero de digitos menores a los
        digitos_totales = dot_pos;      // de despu�s del punto, se forzar� a imprimirlo todo.


    else if(digitos_totales == NO_DIGITS_FORCEMENT)       // Si no se desea forzamiento, simplemente se imprimen todos los d�gitos posibles.
        digitos_totales = after_dot_values + dot_pos;

    /*  Iteraci�n sobre la cual se imprimen los valores en la cadena.  */
    for(iteration = 0; iteration < (digitos_totales); iteration++, division /= 10)
    {
        if(iteration == 0)                      // La primera iteraci�n es distinta.
        {
            temp = value/division;              // Se hace mediante el valor de entrada que se quiere imprimir.
            restante = value - division*temp;
        }

        else
        {
            temp = restante/division;           // Se hace mediante el restante que qued� de la iteraci�n anterior.
            restante -= division*temp;
        }

        *buffer++ = (char) (temp + '0');       // Impresi�n en la cadena.
        if(dot_pos == (iteration+1) && entero == FLOAT_SENDING) {*buffer++ = '.';}  // Evaluaci�n de donde poner el punto.
    }

    if(entero == FLOAT_SENDING)                          // Fuerza a un n�mero de digitos si el numero es flotante.
    for(iteration = 0; iteration < forcing; iteration++) // Se a�aden ceros despues del punto para acompletar el numero de digitos deseados.
        *buffer++ = '0';
}
