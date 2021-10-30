#ifndef BOARD_H
#define BOARD_H

#define BLACK 1
#define WHITE 2
#define BLACK_KING 3
#define WHITE_KING 4

#define MIN_SIZE 8
#define MAX_SIZE 12

typedef int errno_t;
typedef struct {
    uint8_t** arr;
    uint8_t size;
} board_t;

#endif