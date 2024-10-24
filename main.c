#include "stm32f401xc.h"

static void delay(unsigned long cycles);

int main(void)
{
	/* GPIOC: CLOCK ENABLE */
	RCC->AHB1ENR |= ( 0x01 << 2 );
	
	/* GPIOC13: GENERAL PURPOSE OUTPUT MODE */
	GPIOC->MODER |= ( 0x01 << 26 );
	
	/* GPIOC13: OUTPUT PUSH PULL */
	GPIOC->OTYPER &=~ ( 0x01 << 13 );
	
	/* GPIOC13: Medium speed */
	GPIOC->OSPEEDR |= ( 0x01 << 26 );
	
	/* GPIOC13: NO PULL UP, NO PULL DOWN */
	GPIOC->PUPDR &=~( 0x03 << 26 );
	
	while(1)
	{
		/* GPIOC13: OUTPUT HIGH */
		GPIOC->ODR |= ( 1 << 13 );
		
		/* DELAY */
		delay(1000000);
		
		/* GPIOC13: OUTPUT LOW */
		GPIOC->ODR &=~( 1 << 13 );
		
		/* DELAY */
		delay(1000000);
	}
}

static void delay(unsigned long cycles)
{
	while(cycles--);
}
