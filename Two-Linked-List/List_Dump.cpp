#include "List_Headers.h"

void List_Dump(List_Struct list)
{
	size_t i = 0;
	
	printf("\nThis is Dump List\n\n");
	
	printf("list.free = %d\nlist.tail = %d\nlist.head = %d\nlist.size = %ld\n\n", list.free, list.tail, list.head, list.size);
	
	printf("|DATA[%2ld] : %3X| NEXT : %3X| PREPOS : %3X\n", i, list.elem[i].data, list.elem[i].next, list.elem[i].prev);
	
	i++;
	
	while(i <= (list.size+1))
	{
		printf("|DATA[%2ld] : %3d| NEXT : %3d| PREPOS : %3d\n", i, list.elem[i].data, list.elem[i].next, list.elem[i].prev);
		
		i++;
	}
}

void Check_Open_File(FILE* file)
{
	if (file == NULL)
	{
		printf("<=====================>ERROR OPENING FILE<=====================>\n\n");
		printf("<============>CHECK THE AVAILABILITY OF YOUR FILE<=============>");
		exit(303);
	}
}

void Graphviz_List(List_Struct list)
{	
	FILE* GRAF = 0;
	
	GRAF = fopen("List_Graphviz.dot", "w"); 
	
	Check_Open_File(GRAF);  
	
	size_t i = 0;
	
	fprintf(GRAF, "graph graphname \n {\n");
	fprintf(GRAF, "node [shape=record, color = \"red\"];");
	fprintf(GRAF, "		//Описание блоков графа\n");
	
	
	while(i <= list.size)
	{ 
		
		fprintf(GRAF, "		%ld[label=\"{%ld}|{Addres = %ld| Data = %d|Next = %d| Prev = %d}\"];\n", i, i, i, list.elem[list.tail].data, list.elem[list.tail].next, list.elem[list.tail].prev);
	
		int next_tail = list.elem[list.tail].next;
	
		list.tail = next_tail;
		
		i++; 
	} 
	
	i = 0;
	
	fprintf(GRAF, "\n\n");
	
	fprintf(GRAF, "//Связь блоков\n");

	while(i <= (list.size))
	{
		fprintf(GRAF, "		%ld -- %ld [arrowhead = diamond]; \n", i, i+1) ;
		
		i++;
	} 
	fprintf(GRAF, "}");
	
	fclose(GRAF);
}
