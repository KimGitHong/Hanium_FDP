#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iconv.h>

#include <Windows.h>
#include <string.h>

#pragma comment(lib,"libconv.lib")


char field[32][32]={"매출액", "영업이익", "세전계속사업이익", "당기순이익", "당기순이익(지배)", "당기순이익(비지배)", "자산총계", "부채총계", "자본총계", "자본총계(지배)", "자본총계(비지배)", "자본금", "영업활동현금흐름", "투자활동현금흐름", "재무활동현금흐름", "CAPEX", "FCF", "이자발생부채", "영업이익률", "순이익률", "ROE(%)", "ROA(%)", "부채비율", "자본유보율", "EPS(원)", "PER(배)", "BPS(원)", "PBR(배)", "현금DPS(원)", "현금배당수익률", "현금배당성향(%)", "발행주식수(보통주)"};

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

