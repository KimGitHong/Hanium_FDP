#include "header.h"
#include <price_info.h>
#include <mysql.h>
#include <stdio.h>
#include <fsinfo.h>

using namespace std;

#pragma comment(lib,"libFSiInfo.lib")
char arr[][36] = { "매출총이익", "매출액", "영업이익", "당기순이익", "자기자본","자산총계", "총자산", "유동자산", "유형자산", "매출채권", "재고자산", "유동부채", "고정부채", "총부채", "금융비용", "이자비용" };


int main(int argc, char *argv[])
{
	Crp_Info test;
	MARKET_PRICE test1;
	fsinfo fsinfo = fsinfo::getInstance();
	fsinfo.setAuth("3bd198be75bb708c098fc74fb63f1e21918b6257");
	fsinfo.clear();
	fsinfo.init("005930", "16-17");
	for (int i = 0; i < 16; i++) {
		fsinfo[17].load(arr[i]);
		printf("%s : %s\n", arr[i], fsinfo[17][arr[i]].c_str());
	}
	printf("%s %s \n ", fsinfo[17]["영업이익"].c_str(), fsinfo[17]["당기순이익"].c_str());
	printf("%lld %lld \n", atoll(fsinfo[17]["영업이익"].c_str())), atoll(fsinfo[17]["당기순이익"].c_str());
	
	INDEX index;
	init_index(&index);
	cal_index(fsinfo, &index);
	int a = 1;


	
	printf("a");
	/*
	Get_Price_Info("035720", &test1);

	int Crp_cd = 35720;
	char code[7];
	sprintf(code, "%06d", Crp_cd);
	Get_Crp_Info(code, "3bd198be75bb708c098fc74fb63f1e21918b6257", &test);
	printf("\n\n %s \n\n", test.crp_nm_e);

	MYSQL mysql;


	DB_Connection((void*)&mysql, "192.168.0.15", "root", "dblab2108", "db1", 3306);
	Create_Table_Crp_Info((void*)&mysql);
	Insert_Crp_Info((void*)&mysql, test);*/

	//PGNSocketNetwork *network = new PGNSocketNetwork("127.0.0.1", 50000, PGN_OPTION_TCP);
	//network->addCommand("exit", -1);
	//while (network->getServerState() != -1)
	//{
	//	if (network->peekMessage())
	//	{
	//		switch (network->peekMessageTitle())
	//		{
	//		case PGN_MSG_CREATE:
	//			printf("init!!\n");
	//			break;
	//		case -1:
	//			network->setServerState(-1);
	//			break;
	//		}
	//		network->dequeueMessage();
	//	}
	//	network->access();
	//}

	//network->destroy();

	//delete network;
}