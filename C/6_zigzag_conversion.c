// 6_zigzag_conversion.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG

/* Answer begin */
char* convert(char* s, int numRows) {
    int i, j;
    int cnt = 0;
    int n = strlen(s);
    int mid;
    char* s_zigzag = malloc(sizeof(char) * (n+1));
    memset(s_zigzag, 0, sizeof(char) * (n+1));
    for (i = 0; i < numRows; i++)
    {
#ifdef DEBUG
        printf("i = %d\n", i);
#endif
        for (j = i; j < n; j += (numRows == 1 ? 1 : 2 * (numRows - 1)))
        {
            // Add into string
#ifdef DEBUG
            printf("j = %d\n", j);
            printf("cnt = %d\n", cnt);
            puts(s_zigzag);
#endif
            s_zigzag[cnt] = s[j];
            cnt++;

            mid = numRows - i - 1;
            if (mid != 0 && mid != numRows - 1 && j + 2 * mid < n)
            {
#ifdef DEBUG
                printf("j + 2 * mid = %d\n", j + 2 * mid);
                printf("cnt = %d\n", cnt);
                puts(s_zigzag);
#endif
                s_zigzag[cnt] = s[j + 2 * mid];
                cnt++;
            }
        }
    }
    s_zigzag[cnt] = 0;
    return s_zigzag;
}
/* Answer end */

int main()
{
    // char* s = "1234567890";
    // char* s_zigzag = convert(s, 4);
    char* s_zigzag = convert("A", 1);
    puts(s_zigzag);
    return 0;
}