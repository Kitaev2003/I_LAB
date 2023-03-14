#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE_LIST 100
#define CIRCLE 1
#define PTR 0xDEDF00D
#define COFFEE 0xC0FFEE

typedef struct List_Element
{
	int next = 0;
	
	int data = 0;
	
	int prev  = 0;
}Element;

typedef struct List
{
	int free = 0;
    
	int head = 0;
    
	int tail = 0;
    
	size_t size = 0;

	Element *elem;
}List_Struct;

//List_Function.cpp
void List_Construct(List_Struct* list);
void List_Free(List_Struct* list);
void List_Linear(List_Struct* list);
void List_Delete(List_Struct* list, const int num);
void List_Push_Front(List_Struct* list, const int val);
void List_Insert(List_Struct* list, const int num, const int val);

//List_Dump.cpp
void List_Dump(List_Struct list);
void Check_Open_File(FILE* file);
void Graphviz_List(List_Struct list);
