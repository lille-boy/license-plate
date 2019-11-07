/**************************************************************************************************
 *
 * Number of possibilities of a license plate format
 * This module calculates how many license plates you can generate using a specific format
 *
 * For example, the French license plate format is: AA-123-AA
 *
 *      A A - 1 2 3 - A A
 *      A A - 0 0 0 - A A
 *      . .   . . .   . .
 *      . .   . . .   . .
 *      Z Z   9 9 9   Z Z
 *     26x26 10x10x10 26x26 = ‭456,976,000‬
 *
 *************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include "license.h"

#define ALPHABET_SIZE   (26u)
#define NUMERIC_SIZE    (10u)

/******************************************************************************
 * Checks if the input character is alphabetical
 * Returns 1 if alphabetical, 0 otherwise
 *****************************************************************************/
static int is_alphabetical(char letter)
{
    if (((letter >= 'a') && (letter <= 'z')) ||
        ((letter >= 'A') && (letter <= 'Z'))) {
        return 1;
    }

    return 0;
}

/******************************************************************************
 * Checks if the input character is numerical
 * Returns 1 if numerical, 0 otherwise
 *****************************************************************************/
static int is_numerical(char number)
{
    if ((number >= '0') && (number <= '9')) {
        return 1;
    }

    return 0;
}

/******************************************************************************
 * Power function
 * Calculates base to the power of exp
 *****************************************************************************/
 static int power(int base, int exp)
 {
     int result = 1;
     while(exp) {
         result *= base;
         exp--;
     }

     return result;
 }

/******************************************************************************
 * Calculates the number of possibilities of a license plate license_format
 * based on the user entry
 *****************************************************************************/
void license_plate(char *license_format)
{
    int alpha = 0;
    int num = 0;

    for (int i = 0; i < strlen(license_format); i++) {
        alpha += is_alphabetical(license_format[i]);
    }

    for (int i = 0; i < strlen(license_format); i++) {
        num += is_numerical(license_format[i]);
    }

    unsigned long possibilities = power(ALPHABET_SIZE, alpha) * power(NUMERIC_SIZE, num);

    printf("possibilities: %lu\n", possibilities);
}
