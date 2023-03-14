
void Stack_Order(Stack_Struct* stk)
{	   
    assert(stk->capacity != 0);

    stk->data = (int*) malloc((stk->capacity + 1) * sizeof(*stk->data));
}

void Stack_Resize(Stack_Struct* stk)
{
    assert(stk->capacity != 0);

    stk->capacity = stk->capacity + NUM_RESIZE;

    if (stk->size > stk->capacity)
    {
        exit(STACK_OVERFLOW);
    }

   stk->data =(int*)realloc(stk->data, (stk->capacity+2) * sizeof(*stk->data));

    Stack_Protect_End(stk);

    Check_Protect(stk);
}

void Stack_Push(Stack_Struct* stk, const int value)
{
    assert(stk);

    if (stk->size == stk->capacity)
    {
        Stack_Resize(stk);
    }

    stk->data[stk->size] = value;

    stk->size = stk->size + 1;

    Check_Protect(stk);
}

int Stack_Pop(Stack_Struct* stk)
{
    if(stk->size == PROTECTION_CELL)
    {
    	printf("STACK_UNDERFLOW");
        exit(STACK_UNDERFLOW);
    }

    stk->size--;

    Check_Protect(stk);

    return stk->data[stk->size];
}

void Stack_Print(Stack_Struct* stk)
{
	while(stk->size != 1)
	{
		printf("%d\n", Stack_Pop(stk)); 
	}
	
	printf("Stack free");
} 

void Stack_Free(Stack_Struct* stk)
{
    assert(stk);
    
    if(stk->size > PROTECTION_CELL)
    {
        printf("STACK_STILL_FULL\n");
    }

    free(stk->data);
}
