#include"add.h"
#include<stdio.h>

int add(int a, int b){
#ifdef _DEBUG_
    printf("target_compile_definitions() test success\n");
#endif
    return a+b;
}