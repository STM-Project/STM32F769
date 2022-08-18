/*
 * variables.h
 *
 *  Created on: 09.09.2020
 *      Author: Elektronika RM
 */

#ifndef VARIABLES_H_
#define VARIABLES_H_

#include "stm32f7xx_hal.h"

#define MAX_GSM_STRENGHT	30
#define   SIZE_TXT         160

enum{
	Var_slider0,
	Var_slider1,
	Var_slider2,
	Var_gsmStrenght,
	Const_STA_ssid,
	Const_STA_pass,
	Const_AP_ssid,
	Const_AP_pass,
	Const_Wifi_mac,
	Const_Wifi_ip,
	Const_Wifi_mask,
	Const_Wifi_gate,
	Const_Wifi_port,
	Const_Wifi_dhcp,
	Const_Wifi_sta,
	Const_Wifi_ap,
	Const_emailSend_IP,
	Const_emailSend_port,
	Const_emailSend_name,
	Const_emailSend_login,
	Const_emailSend_password,
	Const_emailSend_useSSL,
	Const_emailRecv_email
};

void SetVal(int nameVar, int val);
int GetVal(int nameVar);
void SetTabVal(int nameVar, int nrTab, int val);
int GetTabVal(int nameVar,int nrTab);
void SetStr(int nameVar, int nrTab, char *str);
char* GetStr(int nameVar, int nrTab);
void SetVal64(int nameVar, uint64_t val);
uint64_t GetVal64(int nameVar);

#endif /* VARIABLES_H_ */
