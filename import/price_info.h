#pragma once
#include <stdio.h>
#include <string.h>
#include <Windows.h>
typedef struct _market_price {
	char crp_nm[128];
	char stock_cd[128];
	char crp_cls[128];
	char now_price[128];
	char ytd_price[128];
	char diff_price[128];
	float diff_rate;
	char start_price[128];
	char high_price[128];
	char low_price[128];
	char max_price[128];
	char min_price[128];
	char trade_volume[128];
	char trade_cost[128];
}MARKET_PRICE, *LPMARKET_PRICE;



__declspec(dllexport) void Get_Price_Info(char *crp_cd, MARKET_PRICE* ab);