
void Stack_Protect_Begin(Stack_Struct* stk)
{
    stk->data[0] = DATA_PTR;
    stk->size = 1;
}

void Stack_Protect_End(Stack_Struct* stk)
{
    stk->data[stk->capacity+PROTECTION_CELL] = DATA_PTR;
}

void Stack_Protect(Stack_Struct* stk)
{
    stk->protect_begin = STACK_PTR;

    stk->protect_end = STACK_PTR;
}

void Stack_Protect_Full(Stack_Struct* stk)
{
    Stack_Protect_End(stk);

    Stack_Protect_Begin(stk);

    Stack_Protect(stk);
    
}
