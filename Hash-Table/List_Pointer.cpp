#include "Hash_Table.h"

List_Struct* List_Insert(List_Main *story, const char* str)
{
	List_Struct* list_new = new List_Struct;//Создаем новую структуру элементов
	List_Struct* list_old = story->head;// Создаем структуру предыдущих элементов
	
	if(story->size == 0)
	{
		list_new->data = str;
		
		story->size++;
		
		story->tail = list_new;//Присваиваем tail указатель на первый элемент
		story->head = list_new;//Присваивем head указатель на первый элемент
		
		list_new->next = 0;
		
		return list_new;
	}
	
	list_old->next = list_new;//Присваиваем next предыдущей структуры указатель на новую
	story->head = list_new;//Присваиваем head указатель на последний элемент 
	
	story->size++;
	
	list_new->data = str;
	list_new->next = 0;
	
	return list_new;
}
    
void List_Dump(List_Main story)
{
	List_Struct* list = story.tail;
	size_t i = 0;
	
	std::cout << "hash : " << story.hash << "  size : " << story.size << std::endl;
	
	std::cout << "|";
	
	while(i < story.size)
	{
		std::cout << list->data << "|";
	
		list = list->next;
		i++;	
	}
}

void List_Graf(List_Main story)
{
	List_Struct* list = story.tail;
	size_t i = 0;
	
	std::ofstream GRAF;
	GRAF.open("List_Graphviz.dot"); 
	
	GRAF << "graph graphname \n {" << std::endl;
	GRAF << "node [shape=record, color = \"red\"]; //Описание блоков графа"<< std::endl;
	
	while(i < story.size)
	{ 
		GRAF << "		" << i <<"[label=\"{" << i << "}|{Addres = " << i << "| Data = " << list->data << "|Next = " << list->next << "}\"];" << std::endl;
	
		list = list->next;
		
		i++; 
	} 
	
	i = 0;
	
	while(i < (story.size - 1))
	{
		GRAF << "		" << i << " -- " << i+1 << " [arrowhead = diamond];" << std::endl;
		
		i++;
	} 
	GRAF <<"}"<< std::endl;
	
	GRAF.close();
}
