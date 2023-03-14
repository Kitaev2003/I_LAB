#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define PROTECTION_CELL 1
#define NUM_RESIZE 5
#define STACK_MAX_SIZE 20
#define DATA_PTR 0xDEDF00D
#define STACK_PTR 0xBADDCAFE
#define STACK_OVERFLOW 401
#define STACK_UNDERFLOW 402
#define ERROR_PTR 403

FILE* LOG_FILE = fopen("log.txt", "w");

typedef struct Stack
{
    int protect_begin = 0;
    int* data = 0;
    int size = 0;
    int capacity = 0;
    int protect_end = 0;

}Stack_Struct;
#include "Stack_Protect.cpp"
#include "Stack_ Verifier.cpp"
#include "Stack_Function.cpp"

//Stack_Function 
void Stack_Order(Stack_Struct* stk);
void Stack_Push(Stack_Struct* stk, int value);
void Stack_Resize(Stack_Struct* stk);
int Stack_Pop(Stack_Struct* stk);
void Stack_Print(Stack_Struct* stk);
void Stack_Free(Stack_Struct* stk);
//Stack_Protect
void Stack_Protect_Begin(Stack_Struct* stk);
void Stack_Protect_End(Stack_Struct* stk);
void Stack_Protect(Stack_Struct* stk);
void Stack_Protect_Full(Stack_Struct* stk);
//Stack_Verifier 
void Check_Open_File(FILE* file);
void Check_Protect(Stack_Struct* stk);
void Print_In_File_Protect(Stack_Struct stk);
