
#include <winsock2.h>

#include "queue.h"
#include "socket_list.h"

#include <stdarg.h>
#pragma comment(lib, "ws2_32.lib")

#define READ 3
#define WRITE 5
#define BUFSIZ 512

#define PGN_OPTION_TCP 0
#define PGN_OPTION_UDP 1
#define PGN_OPTION_PRINTINFO 2 //정보출력
#define PGN_OPTION_THREAD 4
#define PGN_OPTION_CLIENT 8


#define PGN_MSGBUF 5012 

#define PGN_CMD 1000
#define PGN_CMD_EXIT 1001
#define PGN_CMD_USERCOUNT 1002
#define PGN_CMD_SEND 1003
#define PGN_CMD_SENDALL 1004




#define PGN_ERROR -1 


#define PGN_MSG_DESTORY -1 //서버 파괴
#define PGN_MSG_ACCEPT 0 //접속
#define PGN_MSG_CLOSE 1 //접속 해제
#define PGN_MSG_LOGIN 2 //로그인
#define PGN_MSG_CHAT 3 //채팅
#define PGN_MSG_CREATE 3 //채팅



typedef UINT_PTR PGNSOCKET;
typedef struct{
	PGNSOCKET hClntSock;
	SOCKADDR_IN clntAdr;
	LPSOCKET_LIST_TYPE clntlist;
} PER_HANDLE_DATA, *LPPER_HANDLE_DATA;

typedef struct
{
	OVERLAPPED overlapped;
	WSABUF wsaBuf;
	char buffer[BUFSIZ];
	int rwMode;
} PER_IO_DATA, *LPPER_IO_DATA;

typedef struct
{
	HANDLE hComPort;
	LPQueueType msgQue;
} THREAD_ARG, *LPTHREAD_ARG;

typedef struct
{
	SOCKET sock;
	short *servstate;
	LPQueueType msgQue;
} THREAD_CLT_ARG, *LPTHREAD_CLT_ARG;

typedef struct
{
	LPVOID sock;
	void (*func)(LPVOID);
} PGNThread_ARG;




void ErrorHandling(char *message);


typedef struct
{
	OVERLAPPED overlapped;
	WSABUF wsaBuf;
}PER_SEND_DATA, *LPPER_SEND_DATA;

typedef struct
{
	char str[32];
	int title;

}PGN_COMMAND,*LPPGN_COMMAND;


unsigned WINAPI EchoThreadMain(LPVOID CompletionPortIO);
unsigned WINAPI EchoThreadMain2(LPVOID CompletionPortIO);

class PGNSocketNetwork
{
private:
	WSABUF buf_;
	WSADATA wsaData;
	LPTHREAD_ARG threadarg;
	LPTHREAD_CLT_ARG threadcltarg;

	HANDLE thread_serv_hd[4];

	HANDLE thread_clt_hd;
	SYSTEM_INFO sysInfo;


	LPPER_IO_DATA ioInfo;
	LPPGN_COMMAND command[BUFSIZ];//명령어-타이틀 대치 구조체. 
	int pgn_opt;
	int command_size;
	
	char **cmd;
	int cmd_size;


	LPPER_HANDLE_DATA handleInfo; 
	LPQueueType main_Que;
	
	BOOL default_thread;//쓰레드 사용 여부
	LPSOCKET_LIST_TYPE clnt_list;

	//PER_SEND_DATA *clntSocks_ioInfo;


	PGNSOCKET hServSock;
	SOCKADDR_IN servAdr;

	
	fd_set reads,cpy_reads; // 멀티플렉싱
	TIMEVAL timeout; // 멀티플렉싱 타임아웃
	
	 

	int semaph;
	int recvBytes, i, flags;
	void command_init(); //초기 명령어 초기화.
public:
	short servState;//0기본 -1종료
	__declspec(dllexport) int command_info(char *str);
	__declspec(dllexport) int getClientCount();
	__declspec(dllexport) int addCommand(char *str, int title);
	__declspec(dllexport) int run();
	__declspec(dllexport) PGNSocketNetwork(char *ip, u_short port, short opt);
	__declspec(dllexport) ~PGNSocketNetwork();
	__declspec(dllexport) void ThreadRegistration(void (*func)(LPVOID));
	__declspec(dllexport) void dequeueMessage();
	__declspec(dllexport) void enqueueMessage(int title, char *contents, void* sock);
	__declspec(dllexport) LPQueueNode peekMessage();
	__declspec(dllexport) void disconnectAll();
	__declspec(dllexport) int peekMessageTitle();

	__declspec(dllexport) int getServerState();
	__declspec(dllexport) int getClientId();

	__declspec(dllexport) void setServerState(int value);
	

	__declspec(dllexport) void destroy();
	__declspec(dllexport) short access();
	__declspec(dllexport) int sendmsg(int id, int msg, char *buf);
	__declspec(dllexport) int sendFormat(int id, int msg, const char *Format, ...);
	__declspec(dllexport) int sendFormat(int msg, const char *Format, ...);
	__declspec(dllexport) int sendmsg(int msg, char *buf);
	__declspec(dllexport) int sendAll(int msg, char *buf);
	__declspec(dllexport) void Clean();


};

__declspec(dllexport) void PGNaddCommand(PGNSocketNetwork *sock, char *str, int title);