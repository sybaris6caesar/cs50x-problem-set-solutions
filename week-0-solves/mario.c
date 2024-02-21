#include <cs50.h>
#include <stdio.h>

int height; // Declare global variable height

void left(int row);  // Decalres left pyramid function prototype
void right(int row); // Declares right pyramid function prototype

int main(void)
{
    do
    {
        height = get_int("What's the height? \n"); // Receives input
    }
    while (height > 8 || height < 1); // Checks if height is between 1-8

    for (int k = 1; k <= height; k++)
    {
        left(k); // 1st level left

        printf("  "); // space between 1st levels

        right(k); // 1st level right

        printf("\n"); // break after 1st levels
    }
}

void left(int row) // Left pyramid fnction
{
    for (int i = 1; i <= height - row; i++)
    {
        printf(" "); // prints spaces
    }

    for (int j = 0; j < row; j++)
    {
        printf("#"); // prints hashes
    }
}

void right(int row) // Right pyramid function
{
    for (int i = 1; i <= row; i++)
    {
        printf("#"); // prints hashes
    }
}
