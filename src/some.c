#include <stdint.h>
#include <stdlib.h>

typedef struct {
    uint8_t** arr;
    uint8_t size;
} board_t;

board_t* board_add(uint8_t n)
{
    board_t* ptr;
    ptr->size = n;
    ptr->arr = (uint8_t**)calloc(n, sizeof(uint8_t*));
    for(uint8_t i = 0; i < n; i++)
        ptr->arr[i] = (uint8_t*)calloc(n, sizeof(uint8_t));
    return ptr;
}

int main() {
    int n = 8;
    board_t* board = (board_t*)malloc(sizeof(board_t));
    uint8_t** ptr = (uint8_t**)calloc(n, sizeof(uint8_t*));
    for(uint8_t i = 0; i < n; i++)
        ptr[i] = (uint8_t*)calloc(n, sizeof(uint8_t));
    uint8_t** arr = ptr;
    board->arr = ptr;
    return 0;
}