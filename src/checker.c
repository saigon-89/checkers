#include <stdio.h>
#include <stdint.h>

/*
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
*/
void swap(void* a, void* b)
{
    void* tmp = a;
    a = b;
    b = tmp;
}

typedef struct {
    uint8_t position;
    uint8_t color;
} checker_t;

uint8_t** map;


int main()
{
    int a = 4, b = 66;
    printf("PRINT: %d | %d\n", a, b);
    swap(&a, &b);
    printf("PRINT: %d | %d\n", a, b);
    return 0;
}