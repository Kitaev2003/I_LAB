
void Check_Open_File(FILE* file)
{
	if (file == NULL)
	{
		printf("<=====================>ERROR OPENING FILE<=====================>\n\n");	
		printf("<============>CHECK THE AVAILABILITY OF YOUR FILE<=============>");
		exit(ERROR_PTR);
	}
}

void Print_In_File_Protect(Stack_Struct stk)
{
	fprintf(LOG_FILE, "Protecting the beginning of the array: %X\n", stk.data[0]);	
	
	fprintf(LOG_FILE, "Protecting the end of the array: %X\n", stk.data[stk.capacity+PROTECTION_CELL]);	
	
	fprintf(LOG_FILE, "Protecting the beginning of the stack: %X\n", stk.protect_begin);	
	
	fprintf(LOG_FILE, "Protecting the end of the stack: %X\n", stk.protect_end);
}

void Check_Protect(Stack_Struct* stk)
{
	Check_Open_File(LOG_FILE);
	
	if(stk->data[0] != DATA_PTR)
	{
		fprintf(LOG_FILE, "Damage to the beginning of the array");
		exit(STACK_UNDERFLOW); 
	}
	
	if(stk->data[stk->capacity+PROTECTION_CELL] != DATA_PTR)
	{
		fprintf(LOG_FILE, "Damage to the end of the array");
		exit(STACK_OVERFLOW); 
	} 
	
	if(stk->protect_begin != STACK_PTR)
	{
		fprintf(LOG_FILE, "Damage to the beginning of the stack");
		exit(STACK_UNDERFLOW); 
	} 
	
	if(stk->protect_end != STACK_PTR)
	{	
		fprintf(LOG_FILE, "Damage to the end of the stack");
		exit(STACK_OVERFLOW); 
	} 
}


