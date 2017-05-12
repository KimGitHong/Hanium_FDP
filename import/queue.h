
#define BUF_SIZE 5120

typedef char element;


typedef struct QueueNode
{
	element contents[512];
	int title;
	void* sock;
	QueueNode *link;
}QueueNode, *LPQueueNode;

typedef struct QueueType
{
	QueueNode* front;
	QueueNode* rear;
	char *msg;// 버퍼저장용
}QueueType, *LPQueueType;
void destroyQueue(QueueType* que);

int is_empty(LPQueueType que);

QueueType* InitQueue();

LPQueueNode InitNode(int title, element *contents, void *sock);
LPQueueNode InitNode(int title, int contents, void *sock);

void enqueue(QueueType* que, QueueNode* data);

int dequeue(QueueType* que);
LPQueueNode peek(QueueType* que);
void display(QueueType *que);

int addque(char **msg, LPQueueType queue, void* sock);
