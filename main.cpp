#include "header.h"
#include <price_info.h>
#include <mysql.h>


int main(int argc, char *argv[])
{
	Crp_Info test;
	MARKET_PRICE test1;
	
	Get_Price_Info("035720", &test1);

	int Crp_cd = 35720;
	char code[7];
	sprintf(code, "%06d", Crp_cd);
	Get_Crp_Info(code, "3bd198be75bb708c098fc74fb63f1e21918b6257", &test);
	printf("\n\n %s \n\n", test.crp_nm_e);

	MYSQL mysql;


	DB_Connection((void*)&mysql, "192.168.0.15", "root", "dblab2108", "db1", 3306);
	Create_Table_Crp_Info((void*)&mysql);
	Insert_Crp_Info((void*)&mysql, test);

	PGNSocketNetwork *network = new PGNSocketNetwork("127.0.0.1", 50000, PGN_OPTION_TCP);
	network->addCommand("exit", -1);
	while (network->getServerState() != -1)
	{
		if (network->peekMessage())
		{
			switch (network->peekMessageTitle())
			{
			case PGN_MSG_CREATE:
				printf("init!!\n");
				break;
			case -1:
				network->setServerState(-1);
				break;
			}
			network->dequeueMessage();
		}
		network->access();
	}

	network->destroy();

	delete network;
}