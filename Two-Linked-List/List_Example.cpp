#include "List_Headers.h"

int main()
{
	List_Struct list;
	
	List_Construct(&list);
	
	int i  = 1;
	
	int val = 20;
	
	List_Push_Front(&list, 18);

	while(i!= 20)// Заполняем список рандомными значениями
	{
		List_Insert(&list, i, val);
		
		val = val + 10;
		i++;
	}
	
	List_Insert(&list, 6, 61);
	
	List_Insert(&list, 7, 75);
	
	List_Insert(&list, 5, 56);
	
	List_Delete(&list, 18);
	
	List_Insert(&list, 16, 666);
	
	List_Insert(&list, 3, 34);
	
	List_Dump(list);
	
	Graphviz_List(list);
	
	List_Linear(&list);
	
	List_Dump(list);
	
	List_Free(&list);
	
	return 0;
}
