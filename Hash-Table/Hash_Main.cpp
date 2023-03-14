#include "Hash_Table.h"

int main(const int argc, const char *argv[]) 
{	
	Hash_Table table_str;
	std::cout << "Hash table is empty" << std::endl; 
	
	table_str.setPush("Hello");
	table_str.setPush("A");
	table_str.setPush("A");
	table_str.setPush("A");
	table_str.setPush("A");
	table_str.setPush("A");
	table_str.setPush("B");
	table_str.setPush("C");
	table_str.setPush("Hash");
	table_str.setPush("Table");
	table_str.setPush("I");
	table_str.setPush("am");
	table_str.setPush("Fine");
	
	table_str.getSearch("A");
	
	table_str.getDump();
	table_str.getGraf_Dump(88);
	
	return 0;
}
