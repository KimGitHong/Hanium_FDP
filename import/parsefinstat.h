#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iconv.h>

#include <Windows.h>
#include <string.h>

#pragma comment(lib,"libconv.lib")


char field[32][32]={"�����", "��������", "������ӻ������", "��������", "��������(����)", "��������(������)", "�ڻ��Ѱ�", "��ä�Ѱ�", "�ں��Ѱ�", "�ں��Ѱ�(����)", "�ں��Ѱ�(������)", "�ں���", "����Ȱ�������帧", "����Ȱ�������帧", "�繫Ȱ�������帧", "CAPEX", "FCF", "���ڹ߻���ä", "�������ͷ�", "�����ͷ�", "ROE(%)", "ROA(%)", "��ä����", "�ں�������", "EPS(��)", "PER(��)", "BPS(��)", "PBR(��)", "����DPS(��)", "���ݹ����ͷ�", "���ݹ�缺��(%)", "�����ֽļ�(������)"};

typedef struct CRP_FINSTAT
{

	typedef struct
	{
		int date;
		double field[32];
	}YEAR_INFO;


	YEAR_INFO year_info[8];

}CRP_FINSTAT, *LPCRP_FINSTAT;


__declspec(dllexport) double findVal(char *contents, int index);
__declspec(dllexport) void parsing(char *f_name, char *crp_cd);

