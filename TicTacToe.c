#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void clearBoard(char board[])
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = ' ';
    }
}

void printBoard(char board[])
{
    system("clear");

    for (int i = 0; i < 9; i++)
    {
        printf(" %c ", board[i]);
        if ((i + 1) % 3 == 0)
        {
            printf("\n---------\n");
        }
    }
}

int isEmpty(char board[], int index)
{
    if (board[index] == ' ')
    {
        return 1;
    }
    return 0;
}

void setSign(char board[], int index, char sign)
{
    board[index] = sign;
}

int userInput(int min, int max)
{
    char input[100];
    input[0] = ' ';
    input[1] = ' ';
    scanf("%s", input);
    getchar();

    while (true)
    {
        int choice = input[0] - '0';
        if ((input[1] == '\0') &&
            (choice <= max) &&
            (choice >= min))
        {
            if (max == 9)
            {
                choice--;
            }
            return choice;
        }

        fflush(stdin);
        printf("Invalid input.\nPlease enter a number between %d - %d:\n", min, max);
        scanf("%s", input);
    }
};

int haveWon(char board[], char sign)
{
    if ((board[0] == sign && board[1] == sign && board[2] == sign) || (board[3] == sign && board[4] == sign && board[5] == sign) || (board[6] == sign && board[7] == sign && board[8] == sign) || (board[0] == sign && board[3] == sign && board[6] == sign) || (board[1] == sign && board[4] == sign && board[7] == sign) || (board[2] == sign && board[5] == sign && board[8] == sign) || (board[0] == sign && board[4] == sign && board[8] == sign) || (board[2] == sign && board[4] == sign && board[6] == sign))
    {
        return 1;
    }
    return 0;
}

int main(void)
{

    int index, winner, count, playGame;
    char board[9], sign, player;

    do
    {
        winner = 0;
        count = 0;
        clearBoard(board);
        printBoard(board);

        while (count < 9 && winner == 0)
        {

            if (count % 2 == 0)
            {
                player = 1;
                sign = 'X';
            }
            else
            {
                player = 2;
                sign = 'O';
            }
            printf("Player %d moves. Type 1-9:\n", player);

            index = userInput(1, 9);

            while (isEmpty(board, index) != 1)
            {
                printf("Place isn't empty. try again.\n");
                index = userInput(1, 9);
            }
            setSign(board, index, sign);
            printBoard(board);
            count++;

            winner = haveWon(board, sign);
        }

        if (winner)
        {
            printf("Player %d has won!\n", player);
        }
        else
        {
            printf("No more moves!\n");
        }

        printf("Press 1 to play again or 0 to quit:\n");

        playGame = userInput(0, 1);

    } while (playGame == 1);

    printf("Thank you and good bye!\n");

    return 0;
}