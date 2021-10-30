#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

const int n = 8;
typedef int checker_t;

typedef struct {
    wchar_t* name;
    checker_t hand[n + n/2];
    player_t* next;
} player_t;

typedef struct {
    player_t player1, player2;
    
} lobby_t;

lobby_t lobby = {
    .player1.name = "player1",
    .player2.name = "player2"
};