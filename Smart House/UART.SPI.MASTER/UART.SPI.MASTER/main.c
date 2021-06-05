/*
 * F19_UART_Driver.c
 *
 * Created: 4/23/2021 1:56:38 PM
 * Author : Ali
 */ 


#include "UART.h"
#include "SPI.h"
#define F_CPU 16000000
#include <util/delay.h>

int main(void)
{
uint8 tx_data = 0;


UART_Init();
SPI_Master_Init();
SPI_Master_InitTrans();
_delay_ms(1000);
    while (1) 
    {
		tx_data = UART_Rx();
		
		if(tx_data)
		{
			SPI_TranSiver(tx_data);
			
		}
		
    }
}

