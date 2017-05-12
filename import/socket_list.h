typedef struct SOCKET_LIST
{
	void* value;
	int id;
	SOCKET_LIST *link;
}SOCKET_LIST,*LPSOCKET_LIST;


typedef struct SOCKET_LIST_TYPE
{
	LPSOCKET_LIST head;
	int count;
	bool id_arr[512];
}SOCKET_LIST_TYPE,*LPSOCKET_LIST_TYPE;


LPSOCKET_LIST_TYPE init_list();

LPSOCKET_LIST init_list_node(void* value);

void list_display(LPSOCKET_LIST_TYPE type);

int list_count(LPSOCKET_LIST_TYPE type);


int list_search_id(LPSOCKET_LIST_TYPE type, void* value);
void* list_search_value(LPSOCKET_LIST_TYPE type, int id);
void list_delete_all(LPSOCKET_LIST_TYPE type);
int list_alloc_id(LPSOCKET_LIST_TYPE type, LPSOCKET_LIST new_node);

int list_insert(LPSOCKET_LIST_TYPE type, LPSOCKET_LIST new_node);
int list_delete_value(LPSOCKET_LIST_TYPE type, void* value);
int list_delete(LPSOCKET_LIST_TYPE type, int id);
