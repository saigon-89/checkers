#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "board.h"

/**
 * \brief Функция создания указателя на игральную доску
 * \param[in] n размерность доски
 * \return Указатель на доску
 */
board_t* board_add(uint8_t n) {
    if((n%2 != 0) || (n < MIN_SIZE) && (n > MAX_SIZE)) {
        printf("Incorrect board size!\n");
        return NULL;
    }
    board_t* ptr = (board_t*)malloc(sizeof(board_t));
    ptr->size = n;
    ptr->arr = (uint8_t**)calloc(n, sizeof(uint8_t*));
    for(uint8_t i = 0; i < n; i++)
        ptr->arr[i] = (uint8_t*)calloc(n, sizeof(uint8_t));
    return ptr;
}

/**
 * \brief Функция начальной расстановки фигур
 * \param[in] ptr указатель на структуру доски
 */
errno_t board_init(board_t* ptr) {
    if(ptr == NULL) {
        printf("Empty pointer!\n");
        return 1;
    }
    uint8_t n = ptr->size;
    for(uint8_t i = 0; i < n/2 - 1; i++)
        for(uint8_t j = !(i%2); j < n; j+=2)
            ptr->arr[i][j] = BLACK;
    for(uint8_t i = n/2 + 1; i < n; i++)
        for(uint8_t j = !(i%2); j < n; j+=2)
            ptr->arr[i][j] = WHITE;
    return 0;
}

/**
 * \brief Функция удаления памяти, выделенной под доску
 * \param[in] n размерность доски
 * \param[in] ptr указатель на доску
 */
errno_t board_del(board_t* ptr) {
    if(ptr == NULL) {
        printf("Pointer already empty!\n");
        return 1;
    }
    uint8_t n = ptr->size;
    for(uint8_t i = 0; i < n; i++)
        free(ptr->arr[i]);
    free(ptr->arr);
    free(ptr);
    return 0;
}

/**
 * \brief Функция печати игральной доски в консоль
 * \param[in] n размерность доски
 * \param[in] ptr указатель на доску
 */
errno_t board_print(board_t* ptr) {
    if(ptr == NULL) {
        printf("Empty pointer!\n");
        return 1;
    }
    uint8_t n = ptr->size;
    for(uint8_t i = 0; i < n; i++) {
        int8_t c;
        for(uint8_t j = 0; j < n; j++) {
            if(ptr->arr[i][j] == BLACK) c = 'b';
            else if(ptr->arr[i][j] == WHITE) c = 'w';
            else c = ' ';
            printf("|%c", c);
        }
        printf("|\n");
    }
    return 0;
}

typedef struct {
    uint8_t x;
    uint8_t y;
} coord_t;

errno_t move(board_t* ptr, coord_t this, coord_t next) {
    if(ptr == NULL) {
        printf("Error!\n");
        return 1;
    }
    if(this.x < 0 || this.y > ptr->size || next.x < 0 || next.y > ptr->size) {
        printf("Error!\n");
        return 1;
    }
    if(this.x == next.x || this.y == next.y) {
        printf("Error!\n");
        return 1;
    }
    if(ptr->arr[this.x][this.y] == 0) printf("Error!\n");
    return 0;
}

int main() {
    int n = 8;
    board_t* board = board_add(n);
    board_init(board);
    board_print(board);
    board_del(board);
    return 0;
}