#include <cs50.h>   // Importing cs50 library
#include <stdio.h>  // Importing standard IO library
#include <string.h> // Importing string library

int validity(long numero); // Declaring CC_number size validity function prototype
int luhn(long numri);      // Declaring luhn algorithm function prototype
void scheme(long nombre);  // Declaring CC scheme function prototype

int main(void) // Main function
{
    long number = get_long("CC Number: "); // CC_number input

    if (validity(number) == 1) // If valid
    {
        if (luhn(number) == 1) // If luhn valid
        {
            scheme(number); // Find out CC scheme
        }
        else
        {
            printf("INVALID\n"); // If not luhn valid
        }
    }
    else
    {
        printf("INVALID\n"); // If not valid
    }
}

int validity(long numero) // CC_number size validity function
{
    char numero_str[20]; // a CC_number_char that can take 20 strings max

    sprintf(numero_str, "%ld", numero); // convert input CC_number to CC_number_char

    int length = strlen(numero_str); // output CC_number_char length

    if (length < 13 || length > 16) // conditional to check if CC_number_char is 13 to 16 digits long. Returns 1 if valid, 0 if not
    {
        return 0;
    }
    else
        return 1;
}

int luhn(long numri) // Luhn algorithm function
{
    int pos = 0;  // Position starts at 0
    long sum = 0; // Sum starts at 0

    while (numri > 0) // Loop runs forver until CC_number is greater than 0
    {
        int digit = numri % 10; // Digits starts from the first quotient of CC_number and continues for manipulated CC_number

        if (pos == 1) // Even numbered digit from right
        {
            digit = digit * 2; // Odd numbered digit from right gets doubled

            if (digit > 9) // If doubled digit becomes double digit
            {
                digit = (digit / 10) + (digit % 10); // The digits are summed
            }
            pos = 0; // Position resets to 0
        }
        else
        {
            pos = 1; // Position resets to 1
        }

        sum = sum + digit;  // Digits are summed
        numri = numri / 10; // CC_number gets smaller
    }

    return (sum % 10 == 0); // Checks if sum is multiple of 10. Returns 1 if valid, 0 if not
}

void scheme(long nombre) // CC scheme function
{
    char nombre_str[20]; // CC_number_char with max 20 strings

    sprintf(nombre_str, "%ld", nombre); // Convrts input to CC_number_char

    if (nombre_str[0] == '4') // If CC_number_char starts with 4, VISA
    {
        printf("VISA\n");
    }
    else if (nombre_str[0] == '5' &&
             (nombre_str[1] == '1' || nombre_str[1] == '2' || nombre_str[1] == '3' || nombre_str[1] == '4' ||
              nombre_str[1] == '5')) // If CC_number_char starts with 51 to 55, MASTERCARD
    {
        printf("MASTERCARD\n");
    }
    else if (nombre_str[0] == '3' && (nombre_str[1] == '4' || nombre_str[1] == '7')) // If CC_number_char starts with 34 or 37, AMEX
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
