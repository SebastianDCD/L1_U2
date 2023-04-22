 // FileName:        TIMER32_MSP432.h
 // Dependencies:    system.h
 // Processor:       MSP432
 // Board:		     MSP432P401R
 // Program Version: CCS V8.3 TI
 // Company:         Texas Instruments
 // Description:     Descripci�n general de constantes, macros y configuraciones del m�dulo TIMER32.
 // Authors:         Jos� Luis Chac�n M. y Jes�s Alejandro Navarro Acosta.
 // Updated:         12/2018.

#ifndef TIMER32_MSP432_H_
#define TIMER32_MSP432_H_

/* Definici�n de macros. */

// Modos de funcionamiento.
#define TIMER32_FreeRunningMode     ((uint32_t)0x00000000)
#define TIMER32_PeriodicMode        ((uint32_t)0x00000040)
#define TIMER32_OneShotMode         ((uint32_t)0x00000001)

// Tipos de prescaler (divisor de tiempos).
#define TIMER32_PrescaleDiv_1       ((uint32_t)0x00000000)
#define TIMER32_PrescaleDiv_16      ((uint32_t)0x00000004)
#define TIMER32_PrescaleDiv_256     ((uint32_t)0x00000008)

// Tama�o del timer.
#define TIMER32_16BitSize           ((uint32_t)0x00000000)
#define TIMER32_32BitSize           ((uint32_t)0x00000002)

// Encendido o apagado.
#define TIMER32_Enabled             1
#define TIMER32_Disabled            0

// Encendido del m�dulo timer32_1.
extern void T32_Init1(void);
// Encendido del m�dulo timer32_2.
extern void T32_Init2(void);
// Habilita la interrupci�n del m�dulo timer32_1.
extern void T32_EnableInterrupt1(void);
// Habilita la interrupci�n del m�dulo timer32_2.
extern void T32_EnableInterrupt2(void);
// Deshabilita la interrupci�n del m�dulo timer32_1.
extern void T32_DisableInterrupt1(void);
// Deshabilita la interrupci�n del m�dulo timer32_2.
extern void T32_DisableInterrupt2(void);
// Configura el modo, divisor de tiempo y tama�o del m�dulo timer32_1.
extern void T32_Configure1(uint32_t Mode, uint32_t Prescale, uint32_t Size);
// Configura el modo, divisor de tiempo y tama�o del m�dulo timer32_2.
extern void T32_Configure2(uint32_t Mode, uint32_t Prescale, uint32_t Size);
// Brinda el valor al que debe cargarse el modulo del timer32_1.
extern void T32_SetLoadValue1(uint32_t LoadValue);
// Brinda el valor al que debe cargarse el modulo del timer32_2.
extern void T32_SetLoadValue2(uint32_t LoadValue);
// Habilita el m�dulo timer32_1.
extern void T32_EnableTimer1(void);
// Habilita el m�dulo timer32_2.
extern void T32_EnableTimer2(void);
// Deshabilita el m�dulo timer32_1.
extern void T32_DisableTimer1(void);
// Deshabilita el m�dulo timer32_2.
extern void T32_DisableTimer2(void);
// Limpia la bandera de interrupci�n del m�dulo timer32_1.
extern void T32_ClearInterruptFlag1(void);
// Limpia la bandera de interrupci�n del m�dulo timer32_2.
extern void T32_ClearInterruptFlag2(void);

#endif /* TIMER32_MSP432_H_ */
