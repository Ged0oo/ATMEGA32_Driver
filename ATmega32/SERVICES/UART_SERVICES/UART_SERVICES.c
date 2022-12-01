#include "UART_SERVICES.h"

static void Func_TX(void);
static void Send_Int_Function2(void);
static void Receive_Int_Function(void);

static volatile  uint8 flag=1;
static uint8  *Asynch_Send_Str;
static uint8  *Asynch_receive_str;


void UART_SendString(const uint8 *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		UART_SendByte(Str[i]);
		i++;
	}
}



void UART_SendString_Asynch(uint8 *Str)
{
	Asynch_Send_Str=Str;
	UART_SendByte(Str[0]);

	UART_TX_SetCallBack(Func_TX);
	UART_TX_InterruptEnable();
}


static void Func_TX(void)
{
	static uint8 i=1;
	if(Asynch_Send_Str[i] !='\0')
	{
		UART_SendByteNoBlock(Asynch_Send_Str[i]);
		i++;
	}
	else
	{
		i=1;
		UART_TX_InterruptDisable();
	}
}


void UART_SendString_Asynch_NocodeInInt(uint8 *Str)
{
	UART_TX_SetCallBack(Send_Int_Function2);
	UART_TX_InterruptEnable();
	static	uint8 i=0;
	if(flag)
	{
		if(Str[i])
		{
			UART_SendByteNoBlock(Str[i]);
			i++;
			flag=0;
		}
		else
		i=0;
	}

}


static void Send_Int_Function2(void)
{
	flag=1;
}



void UART_ReceiveString(uint8 *Str)       //receive until 'enter'
{
	uint8 i = 0;
	Str[i] = UART_ReceiveByte();
	while(Str[i] != 0x0d)
	{
		i++;
		Str[i] = UART_ReceiveByte();
	}
	Str[i+1] = '\0';
}



void UART_ReceiveString_Asynch(uint8 *Str)
{
	Asynch_receive_str=Str;
	UART_RX_InterruptEnable();
	UART_RX_SetCallBack(Receive_Int_Function);
}


static void Receive_Int_Function(void)
{
	static uint8 i=0;
	Asynch_receive_str[i]=UART_ReceiveByteNoBlock();
	i++;

}


void UART_SendString_MYProtocol(uint8*str)
{
	uint8 i=0,lens=0;
	uint16 sum=0;
	while(str[lens])
	{
		sum+=str[lens];	
		lens++;
	}
	UART_SendByte(lens);
	for(i=0;i<lens;i++)
	{
		UART_SendByte(str[i]);
	}
	UART_SendByte((uint8)sum);
	UART_SendByte((uint8)(sum>>8));
}


uint8 UART_ReceiveString_MyProtocol(uint8*str)
{
	uint8 i=0,lens=0,firstbyte=0,secondbyte=0;
	uint16 sum_send=0,sum_calc=0;
	lens=UART_ReceiveByte();
	for(i=0;i<lens;i++)
	{
		str[i]=UART_ReceiveByte();
		sum_calc+=str[i];
	}
	firstbyte=UART_ReceiveByte();
	secondbyte=UART_ReceiveByte();
	sum_send=firstbyte|(secondbyte<<8);

	if(sum_calc==sum_send)
		return 1;
	else
		return 0;
}

