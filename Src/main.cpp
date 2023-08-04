// System includes
#include <stm32f410rx.h>
#include <stm32f4xx.h>

// User includes
#include <user_types.h>
#include <user_functions.h>
#include <delay.h>
#include <timer.h>
#include <ultrasonic_sensor.h>
#include <stdint.h>

// DEBUG
#include <debug_functons.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//Pin declaration
pin_struct_TypeDef usart_tx_pa9;
pin_struct_TypeDef usart_rx_pa10;


// Functions
void clock_init()
{
  // Enable AHB1 clock for GPIOA
  SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);  

  // Enable APB2 clock for USART1
  SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);
}
void pin_init()
{
  usart_tx_pa9 = pin_setup(GPIOA, PIN9, ALTERNATE);
  usart_rx_pa10 = pin_setup(GPIOA, PIN10, ALTERNATE);
}

int main(void)
{
  /* Loop forever */

  while (true)
  {
  }
}
