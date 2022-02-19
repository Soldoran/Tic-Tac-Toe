#include "tictactoe.h"

// Board wont update correct
// Still no logic, no winner / looser

struct Game board =
{
	.arr = "123456789\0",
	.p1 = 'X',
	.p2 = 'O'
};

int		draw_board()
{
	int	x;

	x = 0;
	printf("\n");
	while (x < 9)
	{
		while (x < 3)
		{
			printf(" %c ", board.arr[x]);
			if (x < 2)
				printf("|");
			x++;
		}
		printf("\n ---------\n");
		while (x < 6)
		{
			printf(" %c ", board.arr[x]);
			if (x < 5)
				printf("|");
			x++;
		}
		printf("\n ---------\n");
		while (x < 9)
		{
			printf(" %c ", board.arr[x]);
			if (x < 8)
				printf("|");
			x++;
		}
	}
	printf("\n");
	return (0);
}

int		update_board(char c, char play)
{
	for (int x = 0; x < 9; x++)
	{
		if (board.arr[x] == play)
			board.arr[x] = c;
	}
	return (0);
}

int		check_move(char play)
{
	int	x;

	if (play == 'X' || play == 'O')
		return (0);
	x = 0;
	while (x < 9)
	{
		if (board.arr[x] == play)
			return (0);
		x++;
	}
	return (-1);
}

int		check_win()
{
	/*	Rows	*/
	if (board.arr[0] == board.arr[1] && board.arr[0] == board.arr[2])
	{
		if (board.arr[0] == 'X')
			return (1);	/*	Player 1 won	*/
		else
			return (2);	/*	Player 2 won	*/
	}
	if (board.arr[3] == board.arr[4] && board.arr[3] == board.arr[5])
	{
		if (board.arr[3] == 'X')
			return (1);
		else
			return (2);
	}
	if (board.arr[6] == board.arr[7] && board.arr[6] == board.arr[8])
	{
		if (board.arr[6] == 'X')
			return (1);
		else
			return (2);
	}
	/*	Columns	*/
	if (board.arr[0] == board.arr[3] && board.arr[0] == board.arr[6])
	{
		if (board.arr[0] == 'X')
			return (1);
		else
			return (2);
	}
	if (board.arr[1] == board.arr[4] && board.arr[1] == board.arr[7])
	{
		if (board.arr[1] == 'X')
			return (1);
		else
			return (2);
	}
	if (board.arr[2] == board.arr[5] && board.arr[2] == board.arr[8])
	{
		if (board.arr[2] == 'X')
			return (1);
		else
			return (2);
	}
	/*	Diagonals	*/
	if (board.arr[0] == board.arr[4] && board.arr[0] == board.arr[8])
	{
		if (board.arr[0] == 'X')
			return (1);
		else
			return (2);
	}
	if (board.arr[6] == board.arr[4] && board.arr[6] == board.arr[2])
	{
		if (board.arr[6] == 'X')
			return (1);
		else
			return (2);
	}
	/*	Tie	*/
	return (3);
}

int		play()
{
	char	play;

	play = ' ';
	for (int turn = 1; turn < 10; turn++)
	{
		if (turn % 2 != 0)
		{
			printf("\nIt's Player 1's turn! Please select your next field: ");
			scanf(" %c", &play);
			if (check_move(play) < 0)
			{
				printf("Illegal Turn! You Lose!\n");
				return (0);
			}
			update_board(board.p1, play);
			draw_board();
		}
		else if (turn % 2 == 0)
		{
			printf("\nIt's Player 2's turn! Please select your next field: ");
			scanf(" %c", &play);
			if (check_move(play) != 0)
			{
				printf("Illegal Turn! You Lose!\n");
				return (0);
			}
			update_board(board.p2, play);
			draw_board();
		}
		if (check_win() == 1)
			return (1);
		if (check_win() == 2)
			return (2);
	}
	return (3);
}

int		main()
{
	int		won;
	draw_board();
	won = play();
	if (won == 3)
		printf("It's a tie!\n");
	else if (won == 2)
		printf("Player 2 won!\n");
	else if (won == 1)
		printf("Player 1 won!\n");
	else
		printf("An error occured!\n");
	printf("Thanks for playing!\nThis window will close in 5 seconds");
	sleep(5);
	return (0);
}