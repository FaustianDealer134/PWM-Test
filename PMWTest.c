//******************************************************************************
// PROJETO: Teste de Modulo PWM
//
// Controle de Vers�o: V1.0
// Autor: Gaiotto
// Num | Evento | Data | Observa��es
// 1� | Cria��o do c�digo| 30/08/2017| Teste de modulo PWM
//******************************************************************************
//********************* �REA DE INCLUS�O DE BIBLIOTECAS ************************
#include <p18f4550.h> // biblioteca do microcontrolador
#include <delays.h> //Adiciona a biblioteca de delay.
#include <pwm.h>
#include <timers.h>

//********************* �REA DE DEFINES - APELIDOS *****************************
//********************* �REA DE AJUSTE DOS BITS DE CONFIGURA��O ****************
#pragma config FOSC = INTOSC_EC // Habilita o oscilador interno
#pragma config WDT = OFF //Desabilita o Watchdog Timer (WDT).
#pragma config PWRT = ON //Habilita o Power-up Timer (PWRT).
#pragma config BOR = OFF //Brown-out Reset (BOR) desabilitado.
#pragma config PBADEN = OFF //RB0,1,2,3 e 4 configurado como I/O digital.
#pragma config LVP = OFF //Desabilita o Low Voltage Program.
//********************* �REA DE VARIAVEIS GLOBAIS *****************************
unsigned char period = 150;//
unsigned int duty_cycle = 0;
//********************* �REA DO PROGRAMA PRINCIPAL *****************************
void main(void)
{
	unsigned int valor;
 	TRISC = 0b10000000;
 	TRISD = 0b00000000;
 	ADCON1 = 0X0f;
 	OSCCON = 0xF2; // configura oscilador interno para 8 MHz

 	OpenTimer2(TIMER_INT_OFF & T2_PS_1_1 & T2_POST_1_1); // configura��o do TIMER 2
 	OpenPWM1 (period); // configura��o do M�dulo CCP 1 como PWM1
 	OpenPWM2 (period); // configura��o do M�dulo CCP 2 como PWM2

 	while (1)
 	{
 		for(duty_cycle = 0; duty_cycle < 1023; duty_cycle++)
 		{
 			SetDCPWM1 (duty_cycle);
 			SetDCPWM2 (duty_cycle);
 			Delay10KTCYx(5);// atraso
 		}
 	}
} 	
 