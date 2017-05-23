#pragma once


#include <string.h>
#include <vector>

using namespace std;





class fsinfo
{


private:

	class fsinfo_inner
	{
	private:
		int date;
		typedef struct YEAR_INFO
		{
			std::string field;
			string value;
			YEAR_INFO(std::string field_, string value_);
		}YEAR_INFO;
		std::vector<YEAR_INFO*> data;
	public:
		__declspec(dllexport) int getDate();
	public:
		__declspec(dllexport) fsinfo_inner();
		__declspec(dllexport) fsinfo_inner(int date);
		__declspec(dllexport) fsinfo_inner& load(std::string str);
		__declspec(dllexport) string operator[](std::string str);
		__declspec(dllexport) void clear();
		__declspec(dllexport) void remove();
	};



private:
	double field[32];

	std::vector<fsinfo_inner*> data;
private:
	static fsinfo* instance;
	fsinfo();


private:
	std::string auth;
	std::string name;
	std::string rcp_no;
	int dcmNo;
	int eleId;
	int offset;
	int length;
	std::string dtd;

public:
	__declspec(dllexport) string getName();
	__declspec(dllexport) void setAuth(std::string auth);
	__declspec(dllexport) void setOption(int option);
	__declspec(dllexport) void init(std::string str, std::string period);

	__declspec(dllexport) void init_(std::string str, int period);
	
	__declspec(dllexport) static fsinfo& getInstance();
	__declspec(dllexport) fsinfo_inner& operator[](int date);


public:
	__declspec(dllexport) void clear();
	__declspec(dllexport) void remove();
};



