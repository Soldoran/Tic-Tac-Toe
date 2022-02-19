#ifndef TICTACTOE_H
# define TICTACTOE_H

# include "stdio.h"

struct Game
{
    /*  Board   */
    int x;
    int y;
    int field;
    int arr[3][3];

    /*  Players */
    int     turn;
    char    p1;
    char    p2;
};

struct Game board;

#endif