/** ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Cpu.c
**     Project     : ProcessorExpert
**     Processor   : MK64FN1M0VLL12
**     Component   : MK64FN1M0LL12
**     Version     : Component 01.046, Driver 01.00, CPU db: 3.00.000
**     Repository  : Kinetis
**     Datasheet   : K64P144M120SF5RM, Rev.2, January 2014
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-07-11, 19:00, # CodeGen: 9
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         No public methods
**
**     (c) Freescale Semiconductor, Inc.
**     2004 All Rights Reserved
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file Cpu.c
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

/* MODULE Cpu. */

#include "FreeRTOS.h" /* FreeRTOS interface */
#include "Cpu.h"
#include "Events.h"
#include "Init_Config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
** ===================================================================
**     Method      :  Common_Init (component MK64FN1M0LL12)
**     Description :
**         Initialization of registers for that there is no 
**         initialization component.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#if CPU_COMMON_INIT
void Common_Init(void)
{
  /* Common initialization of registers which initialization is required 
     for proper functionality of components in the project but initialization
     component which would be configuring these registers is missing 
     in the project. 
     Add associated initialization component to the project to avoid 
     initialization of registers in the Common_Init().
     Also, after reset value optimization property affects initialization of 
     registers in this method (see active generator configuration 
     Optimizations\Utilize after reset values property or enabled processor 
     component Common settings\Utilize after reset values property) */
  /* Enable clock gate of peripherals initialized in Common_Init() */
  /* SIM_SCGC5: PORTB=1 */
  SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;

  /* SIM_CLKDIV2: USBDIV=4,USBFRAC=1 */
  SIM_CLKDIV2 = (uint32_t)((SIM_CLKDIV2 & (uint32_t)~(uint32_t)(
                 SIM_CLKDIV2_USBDIV(0x03)
                )) | (uint32_t)(
                 SIM_CLKDIV2_USBDIV(0x04) |
                 SIM_CLKDIV2_USBFRAC_MASK
                ));
  /* SIM_SCGC4: USBOTG=1 */
  SIM_SCGC4 |= SIM_SCGC4_USBOTG_MASK;
  /* SIM_SOPT2: USBSRC=1 */
  SIM_SOPT2 |= SIM_SOPT2_USBSRC_MASK;
  /* NVICIP53: PRI53=0 */
  NVICIP53 = NVIC_IP_PRI53(0x00);
  /* PORTB_PCR10: ISF=0,MUX=1 */
  PORTB_PCR10 = (uint32_t)((PORTB_PCR10 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_MUX(0x06)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x01)
                ));
  /* PORTB_PCR2: ISF=0,MUX=1 */
  PORTB_PCR2 = (uint32_t)((PORTB_PCR2 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x06)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x01)
               ));
  /* PORTB_PCR3: ISF=0,MUX=1 */
  PORTB_PCR3 = (uint32_t)((PORTB_PCR3 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x06)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x01)
               ));

  /* Disable clock gate of peripherals initialized in Common_Init() */
  /* SIM_SCGC5: PORTB=0 */
  SIM_SCGC5 &= (uint32_t)~(uint32_t)(SIM_SCGC5_PORTB_MASK);
}

#endif /* CPU_COMMON_INIT */

/*
** ===================================================================
**     Method      :  Components_Init (component MK64FN1M0LL12)
**     Description :
**         Initialization of components (with exception for Peripheral
**         Initialization Components which are initialized in 
**         Peripherals_Init() method).
**         For example, if automatic initialization feature 
**         is enabled in LDD component then its Init method call 
**         is executed in Components_Init() method.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#if CPU_COMPONENTS_INIT
void Components_Init(void)
{
  MCUC1_Init(); /* ### McuLibConfig "MCUC1" init code ... */
  UTIL1_Init(); /* ### Utility "UTIL1" init code ... */
  CS1_Init(); /* ### CriticalSection "CS1" init code ... */
  /* ### Asynchro serial "AS1" init code ... */
  AS1_Init();
  /* PEX_RTOS_INIT() is a macro should already have been called either from main()
     or Processor Expert startup code. So we don't call it here again. */
  /* PEX_RTOS_INIT(); */ /* ### FreeRTOS "FRTOS1" init code ... */
  /* ### KinetisTools "KIN1" init code ... */
  WAIT1_Init(); /* ### Wait "WAIT1" init code ... */
  XF1_Init(); /* ### XFormat "XF1" init code ... */
  CLS1_Init(); /* ### Shell "CLS1" init code ... */
  /* ### BitIO_LDD "BitIoLdd1" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd1_Init(NULL);
  LED1_Init(); /* ### LED "LED1" init code ... */
  /* ### BitIO_LDD "BitIoLdd2" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd2_Init(NULL);
  LED2_Init(); /* ### LED "LED2" init code ... */
  /* ### BitIO_LDD "BitIoLdd3" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd3_Init(NULL);
  LED3_Init(); /* ### LED "LED3" init code ... */
  /* ### HardFault "HF1" init code ... */
  HF1_Init();
  /* ### TimerInt_LDD "TimerIntLdd1" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)TimerIntLdd1_Init(NULL);
  /* ### TimerInt "TI1" init code ... */
  /* ### Asynchro serial "Serial1" init code ... */
  Serial1_Init();
  /* ### Bluetooth_EGBT "BT1" init code ... */
  BT1_Init();
  GI2C1_Init(); /* ### GenericI2C "GI2C1" init code ... */
  /* ### FXOS8700CQ "FX1" init code ... */
  /* Write code here ... */
  /* ### GenericTimeDate "TmDt1" init code ... */
#if TmDt1_INIT_IN_STARTUP
  (void)TmDt1_Init();
#endif
  /* ### SPIMaster_LDD "SM2" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)SM2_Init(NULL);
  /* ### Timeout "TMOUT1" init code ... */
  TMOUT1_Init();
  /* ### BitIO_LDD "SS1" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)SS1_Init(NULL);
  /* ### BitIO_LDD "CD2" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)CD2_Init(NULL);
  /* ### SD_Card "FATM1" init code ... */
  /* ### FAT_FileSystem "FAT1" init code ... */
  /* ### minIni "MINI1" init code ... */
  /* ### Trigger "TRG1" init code ... */
  TRG1_Init();
  /* ### BitIO_LDD "BitIoLdd8" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd8_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd9" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd9_Init(NULL);
  /* ### Key "KEY1" init code ... */
  KEY1_Init();
  Tx1_Init(); /* ### RingBuffer "Tx1" init code ... */
  Rx1_Init(); /* ### RingBuffer "Rx1" init code ... */
  (void)USB1_Init();
  RTT1_Init(); /* ### SeggerRTT "RTT1" init code ... */
  SYS1_Init(); /* ### SeggerSystemView "SYS1" init code ... */
  /* ### BitIO_LDD "BitIoLdd17" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd17_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd16" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd16_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd19" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd19_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd20" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd20_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd22" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd22_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd23" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd23_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd24" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd24_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd21" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd21_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd26" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd26_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd25" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd25_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd18" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd18_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd15" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd15_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd28" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd28_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd27" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd27_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd30" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd30_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd29" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd29_Init(NULL);
}
#endif /* CPU_COMPONENTS_INIT */

/*
** ===================================================================
**     Method      :  Cpu_INT_NMIInterrupt (component MK64FN1M0LL12)
**
**     Description :
**         This ISR services the Non Maskable Interrupt interrupt.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(Cpu_INT_NMIInterrupt)
{
  Cpu_OnNMI();
}


#ifdef __cplusplus
}
#endif

/* END Cpu. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
