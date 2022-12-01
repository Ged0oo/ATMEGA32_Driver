/*
 * UART_SERVICES.h
 *
 * Created: 9/24/2022 5:15:23 AM
 *  Author: Mohamed Nagy
 */ 


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

#include "../../MCAL/UART/UART.h"


void UART_SendString(const uint8 *Str);
void UART_SendString_Asynch(uint8 *Str);
void UART_SendString_Asynch_NocodeInInt(uint8 *Str);

void UART_ReceiveString(uint8 *Str); // Receive until #
void UART_ReceiveString_NoBlock(uint8 *Str);   // Receive until #
void UART_ReceiveString_Asynch(uint8 *Str);

void UART_SendString_MYProtocol(uint8*str);
uint8 UART_ReceiveString_MyProtocol(uint8*str);


#endif /* UART_SERVICES_H_ */