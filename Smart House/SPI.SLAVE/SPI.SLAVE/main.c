/*
 * F19_SPI_Driver.c
 *
 * Created: 4/24/2021 11:50:28 AM
 * Author : Ali
 */ 

#include "SPI.h"
#define F_CPU 16000000
#include <util/delay.h>

int main(void)
{
	uint8 rx_data = 0;
	uint8 tx_data=0;
	
	DIO_SetPinDir(DIO_PORTC , DIO_PIN1 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTC , DIO_PIN2 , DIO_PIN_OUTPUT);
	SPI_Slave_Init();
	
    while (1) 
    {
		rx_data = SPI_TranSiver(tx_data);
		
		if(rx_data == 49)
		{
			DIO_TogglePin(DIO_PORTC , DIO_PIN1);
			rx_data = 0;
		}
		else if(rx_data == 50)
		{
			DIO_TogglePin(DIO_PORTC , DIO_PIN2);
			rx_data = 0;
		}
		
		
    }
}

