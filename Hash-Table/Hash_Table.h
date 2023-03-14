#include <iostream>
#include <fstream>
#include "cstring"

typedef struct List
{	
	const char* data;
	List* next;
} List_Struct;

typedef struct Main
{
	List_Struct* head;
	List_Struct* tail;
	
	int hash = 0;// For Hash_Table.cpp
	size_t size = 0;
}List_Main;


//List_Pointer.cpp
List_Struct* List_Insert(List_Main *story, const char* str);
void List_Dump(List_Main story);
void List_Graf(List_Main story);

class Hash_Table
{
	public: 
	Hash_Table();
	~Hash_Table();
	
	bool setPush(const char *word);
	
	bool getSearch(const char* word);
	void getGraf_Dump(int hash);
	void getDump();
	
	private:
	size_t size_ = 100;
	List_Main* table_ = 0;
};
