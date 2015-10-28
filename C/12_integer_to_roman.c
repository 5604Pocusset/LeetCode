#include <stdio.h>
#include <stdlib.h>

char* intToRoman(int num) {
    char* result = malloc(sizeof(char)*20); 
    const char ROMAN_SYMBOL[5][2] = {
        {'I', 'V'},
        {'X', 'L'},
        {'C', 'D'},
        {'M', 0},
        {0, 0}
    };
    int i, j, k, r;
    int n = 0;
    for (i = 1000, j = 3; i > 0; i /= 10, j--)
    {
        r = (int) num % (i * 10) / i;
        // printf("r = %d\n", r);
        if (r >= 5)
        {
            if (r == 9)
            {
                result[n++] = ROMAN_SYMBOL[j][0];
                result[n++] = ROMAN_SYMBOL[j+1][0];
            }
            else
            {
                result[n++] = ROMAN_SYMBOL[j][1];
                for (k = 6; k <= r; k++)
                {
                    result[n++] = ROMAN_SYMBOL[j][0];
                }
            }
        }
        else
        {
            if (r == 4)
            {
                result[n++] = ROMAN_SYMBOL[j][0];
                result[n++] = ROMAN_SYMBOL[j][1];
            }
            else
            {
                for (k = 1; k <= r; k++)
                {
                    result[n++] = ROMAN_SYMBOL[j][0];
                }
            }
        }
    }
    result[n] = 0;
    return result;
}

int main()
{
    puts(intToRoman(2));
    puts(intToRoman(4));
    puts(intToRoman(9));
    puts(intToRoman(1954));
    puts(intToRoman(1990));
    puts(intToRoman(2014));
    return 0;
}