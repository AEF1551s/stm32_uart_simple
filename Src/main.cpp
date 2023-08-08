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
#include <uart.h>

// DEBUG
#include <debug_functons.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// Pin declaration
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
  /******USART PINS******/
  usart_tx_pa9 = pin_setup(GPIOA, PIN9, ALTERNATE);
  // Set AF
  SET_BIT(usart_tx_pa9.GPIOx->AFR[1], GPIO_AFRH_AFSEL9_0 | GPIO_AFRH_AFSEL9_1 | GPIO_AFRH_AFSEL9_2); // AF7 = 0b0111

  usart_rx_pa10 = pin_setup(GPIOA, PIN10, ALTERNATE);
  // Set AF
  SET_BIT(usart_rx_pa10.GPIOx->AFR[1], GPIO_AFRH_AFSEL10_0 | GPIO_AFRH_AFSEL10_1 | GPIO_AFRH_AFSEL10_2); // AF7 = 0b0111
  /*********************/
}

int main(void)
{
  /* Loop forever */
  clock_init();
  pin_init();
  uart1_init();

  while (true)
  {
    uart1_write('h');
    const char data = uart1_read();
    printf("%c", data);
  }
}
