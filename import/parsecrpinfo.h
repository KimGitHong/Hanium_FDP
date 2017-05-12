#pragma once

#include <libxml/parser.h>
#include <string.h>
#include <stdlib.h>

#pragma comment(lib,"libxml2.lib")

#define BUFSIZE 512

typedef struct _crp_info
{
	char err_code[BUFSIZE];
	char err_msg[BUFSIZE];
	char crp_nm[BUFSIZE];
	char crp_nm_e[BUFSIZE];
	char crp_nm_i[BUFSIZE];
	char stock_cd[BUFSIZE];
	char ceo_nm[BUFSIZE];
	char crp_cls[BUFSIZE];
	char crp_no[BUFSIZE];
	char bsn_no[BUFSIZE];
	char adr[BUFSIZE];
	char hm_url[BUFSIZE];
	char ir_url[BUFSIZE];
	char phn_no[BUFSIZE];
	char fax_no[BUFSIZE];
	char ind_cd[BUFSIZE];
	char est_dt[BUFSIZE];
	char acc_mt[BUFSIZE];

} Crp_Info;

__declspec(dllexport) void Get_Crp_Info(char* Crp_cd, char* Auth, Crp_Info* test);


