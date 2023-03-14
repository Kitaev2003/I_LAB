#include "List_Headers.h"


void List_Construct(List_Struct* list)
{
	int i = -1;
	int k =  1;	
	
	list->elem = (Element*) calloc(SIZE_LIST, sizeof(Element));
	
	list->head = 0;
	
	list->tail = 1;
	
	list->free = 1;
	
	list->elem[0].data = PTR;
	
	list->elem[0].next = PTR;
	
	list->elem[0].prev = PTR;
	
	while(k < SIZE_LIST)
	{
		list->elem[k].next = i - 1;
		
		list->elem[k].prev = i;
		
		list->elem[k].data = -1;
		
		i--;
		k++;
	}
}

void List_Resize(List_Struct* list)
{
	list->elem = (Element*) realloc(list->elem, SIZE_LIST * 3 * sizeof(int*));
}

void List_Free(List_Struct* list)
{
	free(list->elem);
	
	list->free = 0;
	
	list->size = 0;
	
	list->head = 0;
}

void List_Push_Front(List_Struct* list, const int val)
{
	int future_free = abs(list->elem[list->free].next);
	
	list->elem[list->free].data = val;
	
	list->elem[list->free].next = list->free + 1;
	
	list->elem[list->free].prev = list->free - 1;

	list->free++;
	
	list->size++;

	if(list->size == SIZE_LIST)
	{
		List_Resize(list);
	}
	
	list->free = future_free;
}

void List_Insert(List_Struct* list,  const int num, const int val)
{
	int future_free = abs(list->elem[list->free].next);

	list->elem[list->free].data = val;
	
	list->elem[list->free].next = list->elem[num].next;
	
	list->elem[num].next = list->free;
	
	if(list->elem[num+1].prev < 0)
	{
		list->elem[list->free].prev = list->elem[num+1].prev;

		list->elem[num+1].prev =list->elem[num].next - 1;
	}
	
	else
	{
		list->elem[list->free].prev = list->elem[num+1].prev;

		list->elem[num+1].prev =list->elem[num].next;
	}

	if(list->tail > num)
	{
		list->tail = num;
	}
	
	if(list->head < num)
	{
		list->head = num;
	}

	list->size++;

	list->free = future_free;
	
	if(list->size == SIZE_LIST)
	{
		List_Resize(list);
	}
}

void List_Delete(List_Struct* list, int num)
{	
	if(list->tail == num)
	{
		list->tail = list->elem[num].next; 
	}
	
	if(list->head == num)
	{
		list->head = list->elem[num].prev;
	}
	
	int prev = list->elem[num].prev;
	
	int next = list->elem[num].next;
	
	list->elem[prev].next = list->elem[num].next;
	
	list->elem[next].prev = list->elem[num].prev;
	
	list->size--;
	
	list->elem[num].next = -1*(list->free);
	
	list->elem[num].prev = -1*num;
	
	list->elem[num].data = -1;

	list->free = num;
}

void List_Linear(List_Struct* list)
{
	printf("Warning: The List_Linear function slows down the list greatly, we recommend you stop using it, otherwise enter: \"List_Linear\": ");
	
	char str[15] {}; 
	scanf("%s", str);
	
	if (strcmp(str, "List_Linear") != 0)
	{
		printf("Invalid password");
		exit(1);
	}
	
	size_t i = 1;
	int k = -1*(list->size);
	int val = 0;

	while(i <= list->size)
	{	
		list->elem[i].prev = list->elem[list->tail].data;
		
		val = list->elem[list->tail].next;
		
		list->tail = val;
		
		i++; 
	}
	
	i = 1;
	while(i < (list->size + 1))
	{
		list->elem[i].data = list->elem[i].prev;
		list->elem[i].prev = (i-1);	
		list->elem[i].next = (i+1);
		i++;
	}
	
	while(i<=SIZE_LIST)
	{
		list->elem[i].data = -1;
		list->elem[i].prev = k - 1;	
		list->elem[i].next = k;
		k--;
		i++;
	}
	
	list->tail = 1;
	
	list->head = list->size;
	
	list->free = list->size + 1;
}
