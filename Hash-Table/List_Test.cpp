#include "Hash_Table.h"

int main()
{
	List_Main descrip;
	
	List_Insert(&descrip, "Hello world");
	List_Insert(&descrip, "This is test");
	List_Insert(&descrip, "Мне лень вводить");
	List_Insert(&descrip, "Писать сканф");
	List_Insert(&descrip, "Поэтому пишу тут");
	List_Insert(&descrip, "Главное");
	List_Insert(&descrip, "Чтобы заработал");
	List_Insert(&descrip, "Графиз");
	List_Insert(&descrip, "Все работает");
	List_Insert(&descrip, "Ура!");
	
	
	List_Dump(descrip);
	List_Graf(descrip);
	
	return 0;
}
