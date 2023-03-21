#include "main.h"

/**
 * print_tabsum - prints the sum of all multiples of 3 or 5
 * below 1024 (excluded) using tabs instead of spaces
 */
void print_tabsum(void)
{
    int sum = 0;
    int i;
    for (i = 0; i < 1024; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    /* Print the sum using tabs instead of spaces */
    if (sum == 0) {
        _putchar('0');
    } else {
        int digits = 0;
        int temp = sum;
        while (temp > 0) {
            digits++;
            temp /= 10;
        }

        int tabs_needed = digits / 4;
        int spaces_needed = digits % 4;

        int j;
        for (j = 0; j < tabs_needed; j++) {
            _putchar('\t');
        }
        for (j = 0; j < spaces_needed; j++) {
            _putchar(' ');
        }

        /* Print the sum as a string */
        char str[digits+1];
        temp = sum;
        str[digits] = '\0';
        while (temp > 0) {
            str[--digits] = temp % 10 + '0';
            temp /= 10;
        }
        int k;
        for (k = 0; k < digits; k++) {
            _putchar(str[k]);
        }
    }

    _putchar('\n');
}
