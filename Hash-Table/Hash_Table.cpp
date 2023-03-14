#include "Hash_Table.h"

Hash_Table::Hash_Table()
{	
	size_t i = 0;
	
	table_ = new List_Main[size_];
	
	std::cout << "Hash table constructor work! Like" << std::endl; 
	
	while(i <= size_)
	{	
		table_[i].hash = i;
		i++;
	}
}

Hash_Table::~Hash_Table()
{
	if(size_ == 0)
	{
			std::cout << "Class named \"Hash\" empty" << std::endl; 
	}
	
	size_t i = 0; 
	
	std::cout << "Hash table destructor work! Like!" << std::endl;
	
	while(i < size_)
	{
		List_Struct* list_new = table_[i].tail;		
		
		List_Struct* list_old;
		i++;
		
		while(list_new != 0)
		{
			list_old  =  list_new->next;
			
			delete list_new;
			
			list_new = list_old;
		} 
	}
	size_ = 0;
}

int Search_Hash(const char* word)
{
	size_t i = 0;
	int hash = 0;
	
	while(word[i] != '\0')
	{
		hash =(int)(word[i])  + hash; 
		i++;
	}
	
	
	hash = hash % 100;
	
	return hash;
}

bool Hash_Table::setPush(const char *word)
{	
	int hash = Search_Hash(word);
	bool push = false;
	
	if(table_[hash].size == 0)//Если список ещё пуст добавляем новый элемент 
	{			  //Можно избавиться, если заполнить нулевой элемент списка
		List_Insert(&table_[hash], word);
		
		push = true;
		return push;
	}
	
	List_Struct* list = table_[hash].tail;
	
	do
	{	
		if(strcmp(word, list->data) == 0)//Такой элемент уже существует в хеш-таблице
		{
			
			push = false;
			return push; 	
		}
		
		if(list->next != 0)
		{
			list = list->next;
		}
	}while(list->next != 0);
	
	List_Insert(&table_[hash], word);// Добавляем элемент в хеш-таблицу

	push = true;


	return push;
}

bool Hash_Table::getSearch(const char* word)
{
	int hash = Search_Hash(word);
	
	if(table_[hash].size == 0)//Если список ещё пуст добавляем новый элемент 
	{
		printf("Слова нет в таблице\n");
		return false;
	}
	
	List_Struct* list = table_[hash].tail;
	
	do
	{	
		if(strcmp(word, list->data) == 0)//Такой элемент уже существует в хеш-таблице
		{
			printf("Слово есть в таблице\n");
			return true; 	
		}
		
		if(list->next != 0)
		{
			list = list->next;
		}
		
	}while(list->next != 0);
	
	printf("Слова нет в таблице\n");
	return false;
}

void Hash_Table::getDump()
{
	size_t i = 0;
	
	while(i < size_)
	{	
		List_Dump(table_[i]);
		i++;
		
		std::cout<<std::endl;
	}	
}

void Hash_Table::getGraf_Dump(int hash)
{
	if(hash < 0)
	{
		exit(hash);
	} 
	
	if(table_[hash].size > 0)
	{
		List_Graf(table_[hash]);	
	} 
}
