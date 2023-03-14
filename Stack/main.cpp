#include "Stack_Lib.h"

int main()
{
    Stack_Struct stk = {};

    stk.capacity = 10;
    
    Stack_Order(&stk);
    
    Stack_Protect_Full(&stk);
    
    Stack_Push (&stk, 10);
    Stack_Push (&stk, 20);
    Stack_Push (&stk, 30);
    Stack_Push (&stk, 40);
    Stack_Push (&stk, 50);
    Stack_Push (&stk, 60);
    Stack_Push (&stk, 70);
    Stack_Push (&stk, 80);
    Stack_Push (&stk, 90);
    Stack_Push (&stk, 100);
    Stack_Push (&stk, 110);

    Print_In_File_Protect(stk);
    
    Stack_Print(&stk);

    Stack_Free(&stk);

    return 0;
}
