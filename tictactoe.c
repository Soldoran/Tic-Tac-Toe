#include "tictactoe.h"

// Board wont update correct
// Still no logic, no winner / looser


void    draw_board(void)
{
    board.x = 0;
    while (board.x < 3)
    {
        board.y = 0;
        while (board.y < 3)
        {
            printf(" %c ", board.arr[board.x][board.y]);
            if (board.y != 2)
                printf("|");
            if (board.y == 2 && board.x != 2)
                printf("\n ---------\n");
            board.y++;
        }
        board.x++;
    }
    printf("\n");
}

void    init_board(void)
{
    board.field = 49;
    board.x = 0;
    while (board.x < 3)
    {
        board.y = 0;
        while (board.y < 3)
        {
            board.arr[board.x][board.y] = board.field;
            board.y++;
            board.field++;
        }
        board.x++;
    }
}

int    turn(int c, int play)
{
    board.x = 0;
    while (board.x < 3)
    {
        board.y = 0;
        while (board.y< 3)
        {
            if (board.arr[board.x][board.y] == play)
            {
                board.arr[board.x][board.y] = c;
                return (1);
            }
            board.y++;
        }
        board.x++;
    }
    return (0);
}

void    update_board(char c, int play)
{
    board.x = 0;
    while (board.x < 3)
    {
        board.y = 0;
        while (board.y < 3)
        {
            if (board.arr[board.x][board.y] == play)
                board.arr[board.x][board.y] = c;
            board.y++;
        }
        board.x++;
    }
    draw_board();
}

int    play()
{
    int play;

    play = 0;
    board.p1 = 'X';
    board.p2 = 'O';
    board.turn = 1;

    while (board.turn != 10)
    {
        if (board.turn % 2 != 0)
        {
            printf("It's Player 1's turn. Please choose your field: ");
            scanf("%d", &play);
            if (turn(board.p1, play) != 0)
            {
                printf("Your move is illegal. You loose!\n");
                return (1);
            }
            update_board(board.p1, play);
        }
        else
        {
            printf("It's Player 2's turn. Please choose your field: ");
            scanf("%d", &play);
            if (turn(board.p2, play) != 0)
            {
                printf("Your move is illegal. You loose!\n");
                return (1);
            }
            update_board(board.p2, play);
        }
        board.turn++;
    }
    return (1);
}

int main()
{
    char replay;

    replay = 'Y';
    while (replay == 'Y' || replay == 'y')
    {
        init_board();
        draw_board();
        if (play() == 1)
        {
            printf("Play Again? [Type 'Y' if yes] ");
            scanf("%c", &replay);
        }
    }
    printf("Thanks for Playing!\n");
    return (0);
}