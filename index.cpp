#include "header.h"
#include <stdio.h>
#include <fsinfo.h>

int cal_index(fsinfo fsinfo, INDEX* index)
{
	printf("%lf %lf %lf \n", atof(fsinfo[17]["유동자산"].c_str()), atof(fsinfo[17]["재고자산"].c_str()), atof(fsinfo[17]["유동부채"].c_str()));
	index->checking_rt = ((atof(fsinfo[17]["유동자산"].c_str()) - atof(fsinfo[17]["재고자산"].c_str())) / atof(fsinfo[17]["유동부채"].c_str())) * 100;
	printf("index->checking_rt = %f \n", index->checking_rt);


	printf("%lf %lf %lf \n", atof(fsinfo[17]["유동자산"].c_str()), atof(fsinfo[16]["유동자산"].c_str()), atof(fsinfo[16]["유동자산"].c_str()));
	index->current_asset_gw = ((atof(fsinfo[17]["유동자산"].c_str()) - atof(fsinfo[16]["유동자산"].c_str())) / atof(fsinfo[16]["유동자산"].c_str())) * 100;
	printf("index->current_asset_gw = %f \n", index->current_asset_gw);

	printf("%lf %lf \n", atof(fsinfo[17]["유동부채"].c_str()), atof(fsinfo[17]["자기자본"].c_str()));
	index->current_dept_rt = (atof(fsinfo[17]["유동부채"].c_str()) / atof(fsinfo[17]["자기자본"].c_str())) * 100;
	printf("index->current_dept_rt = %f \n", index->current_dept_rt);

	printf("%lf %lf \n", atof(fsinfo[17]["총부채"].c_str()), atof(fsinfo[17]["자기자본"].c_str()));
	index->dept_rt = (atof(fsinfo[17]["총부채"].c_str()) / atof(fsinfo[17]["자기자본"].c_str())) * 100;
	printf("index->dept_rt = %f \n", index->dept_rt);

	printf("%lf %lf \n", atof(fsinfo[17]["매출액"].c_str()), atof(fsinfo[17]["자기자본"].c_str()));
	index->equity_asset_tort = (atof(fsinfo[17]["매출액"].c_str()) / atof(fsinfo[17]["자기자본"].c_str()));
	printf("index->equity_asset_tort = %f \n", index->equity_asset_tort);

	printf("%lf %lf %lf \n", atof(fsinfo[17]["자기자본"].c_str()), atof(fsinfo[16]["자기자본"].c_str()), atof(fsinfo[16]["자기자본"].c_str()));
	index->equity_gw = ((atof(fsinfo[17]["자기자본"].c_str()) - atof(fsinfo[16]["자기자본"].c_str())) / atof(fsinfo[16]["자기자본"].c_str())) * 100;
	printf("index->equity_gw = %f \n", index->equity_gw);

	printf("%lf %lf \n", atof(fsinfo[17]["금융비용"].c_str()), atof(fsinfo[17]["매출액"].c_str()));
	index->fin_burden_rt = (atof(fsinfo[17]["금융비용"].c_str()) / atof(fsinfo[17]["매출액"].c_str())) * 100;
	printf("index->fin_burden_rt = %f \n", index->fin_burden_rt);

	printf("%lf %lf \n", atof(fsinfo[17]["고정부채"].c_str()), atof(fsinfo[17]["자기자본"].c_str()));
	index->fixed_dept_rt = (atof(fsinfo[17]["고정부채"].c_str()) / atof(fsinfo[17]["자기자본"].c_str())) * 100;
	printf("index->fixed_dept_rt = %f \n", index->fixed_dept_rt);

	printf("%lf %lf \n", atof(fsinfo[17]["유동자산"].c_str()), atof(fsinfo[17]["유동부채"].c_str()));
	index->flow_rt = (atof(fsinfo[17]["유동자산"].c_str()) / atof(fsinfo[17]["유동부채"].c_str())) * 100;
	printf("index->flow_rt = %f \n", index->flow_rt);

	printf("%lf %lf \n", atof(fsinfo[17]["매출총이익"].c_str()), atof(fsinfo[17]["매출액"].c_str()));
	index->gross_pf = (atof(fsinfo[17]["매출총이익"].c_str()) / atof(fsinfo[17]["매출액"].c_str())) * 100;
	printf("index->gross_pf = %f \n", index->gross_pf);

	printf("%lf %lf \n", atof(fsinfo[17]["영업이익"].c_str()), atof(fsinfo[17]["금융비용"].c_str()));
	index->interest_factor = (atof(fsinfo[17]["영업이익"].c_str()) / atof(fsinfo[17]["금융비용"].c_str()));
	printf("index->interest_factor = %f \n", index->interest_factor);

	printf("%lf %lf \n", atof(fsinfo[17]["매출액"].c_str()), atof(fsinfo[17]["재고자산"].c_str()));
	index->inventory_tort = (atof(fsinfo[17]["매출액"].c_str()) / atof(fsinfo[17]["재고자산"].c_str()));
	printf("index->inventory_tort = %f \n", index->inventory_tort);

	printf("%lf %lf %lf \n", atof(fsinfo[17]["총부채"].c_str()), atof(fsinfo[17]["유동자산"].c_str()), atof(fsinfo[17]["자기자본"].c_str()));
	index->net_dept_rt = ((atof(fsinfo[17]["총부채"].c_str()) - atof(fsinfo[17]["유동자산"].c_str())) / atof(fsinfo[17]["자기자본"].c_str())) * 100;
	printf("index->net_dept_rt = %f \n", index->net_dept_rt);

	printf("%lf %lf %lf \n", atof(fsinfo[17]["당기순이익"].c_str()), atof(fsinfo[16]["당기순이익"].c_str()), atof(fsinfo[16]["당기순이익"].c_str()));
	index->net_gw = ((atof(fsinfo[17]["당기순이익"].c_str()) - atof(fsinfo[16]["당기순이익"].c_str())) / atof(fsinfo[16]["당기순이익"].c_str())) * 100;
	printf("index->net_gw = %f \n", index->net_gw);

	printf("%lf %lf \n", atof(fsinfo[17]["당기순이익"].c_str()), atof(fsinfo[17]["매출액"].c_str()));
	index->net_pf = (atof(fsinfo[17]["당기순이익"].c_str()) / atof(fsinfo[17]["매출액"].c_str())) * 100;
	printf("index->net_pf = %f \n", index->net_pf);

	printf("%lf %lf %lf \n", atof(fsinfo[17]["영업이익"].c_str()), atof(fsinfo[16]["영업이익"].c_str()), atof(fsinfo[16]["영업이익"].c_str()));
	index->operating_gw = ((atof(fsinfo[17]["영업이익"].c_str()) - atof(fsinfo[16]["영업이익"].c_str())) / atof(fsinfo[16]["영업이익"].c_str())) * 100;
	printf("index->operating_gw = %f \n", index->operating_gw);

	printf("%lf %lf \n", atof(fsinfo[17]["영업이익"].c_str()), atof(fsinfo[17]["매출액"].c_str()));
	index->operating_pf = (atof(fsinfo[17]["영업이익"].c_str()) / atof(fsinfo[17]["매출액"].c_str())) * 100;
	printf("index->operating_pf = %f \n", index->operating_pf);

	printf("%lf %lf \n", atof(fsinfo[17]["매출액"].c_str()), atof(fsinfo[17]["매출채권"].c_str()));
	index->receivables_tort = (atof(fsinfo[17]["매출액"].c_str()) / atof(fsinfo[17]["매출채권"].c_str()));
	printf("index->receivables_tort = %f \n", index->receivables_tort);

	printf("%lf %lf \n", atof(fsinfo[17]["당기순이익"].c_str()), atof(fsinfo[17]["자산총계"].c_str()));
	index->roa = (atof(fsinfo[17]["당기순이익"].c_str()) / atof(fsinfo[17]["자산총계"].c_str()));
	printf("index->roa = %f \n", index->roa);

	printf("%lf %lf \n", atof(fsinfo[17]["당기순이익"].c_str()), (atof(fsinfo[17]["자기자본"].c_str()) + atof(fsinfo[16]["자기자본"].c_str()))/2);
	index->roe = (atof(fsinfo[17]["당기순이익"].c_str()) / (atof(fsinfo[17]["자기자본"].c_str()) + atof(fsinfo[16]["자기자본"].c_str())) / 2);
	printf("index->roe = %f \n", index->roe);

	printf("%lf %lf %lf \n", atof(fsinfo[17]["매출액"].c_str()), atof(fsinfo[16]["매출액"].c_str()), atof(fsinfo[16]["매출액"].c_str()));
	index->sales_gw = ((atof(fsinfo[17]["매출액"].c_str()) - atof(fsinfo[16]["매출액"].c_str())) / atof(fsinfo[16]["매출액"].c_str())) * 100;
	printf("index->sales_gw = %f \n", index->sales_gw);

	printf("%lf %lf %lf \n", atof(fsinfo[17]["유형자산"].c_str()), atof(fsinfo[16]["유형자산"].c_str()), atof(fsinfo[16]["유형자산"].c_str()));
	index->tangible_asset_gw = ((atof(fsinfo[17]["유형자산"].c_str()) - atof(fsinfo[16]["유형자산"].c_str())) / atof(fsinfo[16]["유형자산"].c_str())) * 100;
	printf("index->tangible_asset_gw = %f \n", index->tangible_asset_gw);

	printf("%lf %lf \n", atof(fsinfo[17]["매출액"].c_str()), atof(fsinfo[17]["유형자산"].c_str()));
	index->tangible_asset_tort = (atof(fsinfo[17]["매출액"].c_str()) / atof(fsinfo[17]["유형자산"].c_str()));
	printf("index->tangible_asset_tort = %f \n", index->tangible_asset_tort);

	printf("%lf %lf %lf \n", atof(fsinfo[17]["총자산"].c_str()), atof(fsinfo[16]["총자산"].c_str()), atof(fsinfo[16]["총자산"].c_str()));
	index->total_asset_gw = ((atof(fsinfo[17]["총자산"].c_str()) - atof(fsinfo[16]["총자산"].c_str())) / atof(fsinfo[16]["총자산"].c_str())) * 100;
	printf("index->total_asset_gw = %f \n", index->total_asset_gw);

	printf("%lf %lf \n", atof(fsinfo[17]["매출액"].c_str()), atof(fsinfo[17]["총자산"].c_str()));
	index->total_asset_tort = (atof(fsinfo[17]["매출액"].c_str()) / atof(fsinfo[17]["총자산"].c_str()));
	printf("index->total_asset_tort = %f \n", index->total_asset_tort);



	return 0;
}

void init_index(INDEX* index)
{
	for (int i = 0; i < INDEX_NUM; i++)
	{
		memset(index, 0, sizeof(INDEX));
	}
}