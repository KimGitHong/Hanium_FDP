#pragma once

typedef struct _index
{
	float gross_pf;
	float operating_pf;
	float net_pf;
	float roe;
	float roa;
	float sales_gw;
	float operating_gw;
	float net_gw;
	float total_asset_gw;
	float current_asset_gw;
	float tangible_asset_gw;
	float equity_gw;
	float dept_rt;
	float current_dept_rt;
	float fixed_dept_rt;
	float net_dept_rt;
	float flow_rt;
	float checking_rt;
	float interest_factor;
	float fin_burden_rt;
	float total_asset_tort;
	float equity_asset_tort;
	float tangible_asset_tort;
	float receivables_tort;
	float inventory_tort;
} INDEX;
#define INDEX_NUM 25

//#pragma comment(lib, "ParseFinstat.lib")

#pragma comment(lib, "SQL.lib")
#pragma comment(lib, "PriceInfo.lib")


#include <SQL.h>


#include <PGNNetwork.h>
#pragma comment(lib, "PatGetNetWork.lib")
#pragma comment(lib, "ParseCrpInfo.lib")
#include <ParseCrpInfo.h>
#include <fsinfo.h>

//#include <parsefinstat.h>

int cal_index(fsinfo fsinfo, INDEX* index);
void init_index(INDEX* index);

