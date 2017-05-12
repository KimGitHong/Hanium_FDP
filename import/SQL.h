#pragma once


#include <ParseCrpInfo.h>



__declspec(dllexport) void DB_Connection(void* mysql_, char* ip_adr, char* id, char* passwd, char* table_name, int port);
__declspec(dllexport) void Create_Table_Crp_Info(void* mysql);
__declspec(dllexport) void Insert_Crp_Info(void* mysql_, Crp_Info test);