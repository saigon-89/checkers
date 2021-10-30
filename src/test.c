#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

typedef struct {
    int n;
    int* arr;
    void (*chang)(func_t*);
    int (*sum)(int, int);
    int (*mul)(int, int);
} func_t;

void change(func_t* ptr)
{
    ptr->n = 999;
}

int summary(int a, int b)
{
    printf("SUMMARY: %d", a+b);
    return a+b;
}

int multiplication(int a, int b)
{
    printf("MUL: %d", a*b);
    return a*b;
}


func_t* init(int n)
{
    func_t* ptr;
    ptr->n = n;
    ptr->arr = NULL;
    ptr->mul = multiplication;
    ptr->sum = summary;
    ptr->chang = change;
    return ptr;
}
func_t func = { .mul = multiplication, .sum = summary };

int main()
{
    int n = 8;
    //while((clock()/CLOCKS_PER_SEC) != 10) {}
    /*
    printf("TIME\n");
    int* A = (int*)malloc(8*sizeof(int));
    for(char i = 0; i < n; i++)
        A[i] = i;
    
    for(char i = 0; i < n; i++)
        printf("%d\t", A[i]);
    
   func_t* fff = init(1);
   printf("TEST %d\n", fff->n);
   fff->chang(fff);
   printf("TEST %d\n", fff->n);
   */
        
    return 0;
}