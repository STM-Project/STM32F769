/*
 * variables.c
 *
 *  Created on: 09.09.2020
 *      Author: Elektronika RM
 */

#include "stm32f7xx_hal.h"
#include <string.h>
#include "variables.h"
#include "sdram.h"
#include "mini_printf.h"

#include "smtp.h"

//-------------- Zmienne NIEzapisywalne -------------------------

#define   _Size__s_Wifi     1



typedef struct
{
   int value[50000];
   int GsmStrenght;


}  s_wartosci;
SDRAM static s_wartosci Var;


//-------------- Zmienne zapisywalne -------------------------

typedef struct __attribute__ ((packed))
{
	uint64_t mac;
	uint32_t ip;
	uint32_t mask;
	uint32_t gate;
	uint16_t port;
	char STA_ssid[SIZE_TXT];
 	char STA_pass[SIZE_TXT];
 	char AP_ssid[SIZE_TXT];
 	char AP_pass[SIZE_TXT];
	uint8_t dhcp;
	uint8_t sta;
	uint8_t ap;
}s_net_wifi;

typedef struct  __attribute__ ((packed))
{

	 s_net_wifi		s_Wifi[_Size__s_Wifi];
	 s_smtp_sender	emailSend[MAX_EMAIL_SENDERS];
	 s_smtp_recipient	emailRecv[MAX_EMAIL_RECIPIENTS];

}Zmienne_zapisywalne;

SRAM static Zmienne_zapisywalne  Const;


void SetVal(int nameVar, int val)
{
	switch(nameVar)
	{
	case Var_slider0:   	Var.value[49990]=val;     break;
	case Var_slider1:   	Var.value[49991]=val;     break;
	case Var_slider2:   	Var.value[49992]=val;     break;
	case Var_gsmStrenght:  	Var.GsmStrenght=val;      break;
	case Const_Wifi_ip:		Const.s_Wifi[0].ip=val;   break;
	case Const_Wifi_mask:	Const.s_Wifi[0].mask=val;   break;
	case Const_Wifi_gate:	Const.s_Wifi[0].gate=val;   break;
	case Const_Wifi_port:	Const.s_Wifi[0].port=val;   break;
	case Const_Wifi_dhcp:	Const.s_Wifi[0].dhcp=val;   break;
	case Const_Wifi_sta:		Const.s_Wifi[0].sta=val;   break;
	case Const_Wifi_ap:		Const.s_Wifi[0].ap=val;   break;
	case Const_emailSend_IP:		Const.emailSend[0].IP=val;   break;
	}
}

int GetVal(int nameVar)
{
	switch(nameVar)
	{
	case Var_slider0:      return Var.value[49990];
	case Var_slider1:      return Var.value[49991];
	case Var_slider2:      return Var.value[49992];
	case Var_gsmStrenght:  return Var.GsmStrenght;
	case Const_Wifi_ip:    return Const.s_Wifi[0].ip;
	case Const_Wifi_mask:    return Const.s_Wifi[0].mask;
	case Const_Wifi_gate:    return Const.s_Wifi[0].gate;
	case Const_Wifi_port:    return Const.s_Wifi[0].port;
	case Const_Wifi_dhcp:    return Const.s_Wifi[0].dhcp;
	case Const_Wifi_sta:     return Const.s_Wifi[0].sta;
	case Const_Wifi_ap:     return Const.s_Wifi[0].ap;
	default:
		return 0;
	}
}

void SetTabVal(int nameVar, int nrTab, int val)
{
	switch(nameVar)
	{
	case Const_emailSend_IP:	 Const.emailSend[nrTab].IP=val;    break;
	case Const_emailSend_port:	 Const.emailSend[nrTab].port=val;  break;
	case Const_emailSend_useSSL:	 Const.emailSend[nrTab].useSSL=val;  break;
	}
}

int GetTabVal(int nameVar,int nrTab)
{
	switch(nameVar)
	{
	case Const_emailSend_IP:     return Const.emailSend[nrTab].IP;
	case Const_emailSend_port:   return Const.emailSend[nrTab].port;
	case Const_emailSend_useSSL:   return Const.emailSend[nrTab].useSSL;
	default:
		return 0;
	}
}

void SetStr(int nameVar, int nrTab, char *str)
{
	char *ptr;
	switch(nameVar)
	{
	case Const_STA_ssid:	str[SIZE_TXT-1]=0; strcpy(Const.s_Wifi[0].STA_ssid,str);	break;
	case Const_STA_pass:	str[SIZE_TXT-1]=0; strcpy(Const.s_Wifi[0].STA_pass,str);	break;
	case Const_AP_ssid:		str[SIZE_TXT-1]=0; strcpy(Const.s_Wifi[0].AP_ssid,str);     break;
	case Const_AP_pass:		str[SIZE_TXT-1]=0; strcpy(Const.s_Wifi[0].AP_pass,str);		break;
	case Const_emailSend_name:
		StrBuffCopylimit(Const.emailSend[nrTab].name,str,sizeof(Const.emailSend[nrTab].name));
		break;
	case Const_emailSend_login:
		StrBuffCopylimit(Const.emailSend[nrTab].login,str,sizeof(Const.emailSend[nrTab].login));
		break;
	case Const_emailSend_password:
		StrBuffCopylimit(Const.emailSend[nrTab].password,str,sizeof(Const.emailSend[nrTab].password));
		break;
	case Const_emailRecv_email:
		StrBuffCopylimit(Const.emailRecv[nrTab].email,str,sizeof(Const.emailRecv[nrTab].email));
		break;
	}
}

char* GetStr(int nameVar, int nrTab)
{
	switch(nameVar)
	{
	case Const_STA_ssid:	return Const.s_Wifi[0].STA_ssid;
	case Const_STA_pass:	return Const.s_Wifi[0].STA_pass;
	case Const_AP_ssid:		return Const.s_Wifi[0].AP_ssid;
	case Const_AP_pass:		return Const.s_Wifi[0].AP_pass;
	case Const_emailSend_name:	 return Const.emailSend[nrTab].name;
	case Const_emailSend_login:	return Const.emailSend[nrTab].login;
	case Const_emailSend_password:	return Const.emailSend[nrTab].password;
	case Const_emailRecv_email:	return Const.emailRecv[nrTab].email;
	default: return 0;
	}
}

void SetVal64(int nameVar, uint64_t val)
{
	switch(nameVar)
	{
	case Const_Wifi_mac:
		Const.s_Wifi[0].mac=val;
		break;
	}
}

uint64_t GetVal64(int nameVar)
{
	switch(nameVar)
	{
	case Const_Wifi_mac:   return Const.s_Wifi[0].mac;
	}
}
