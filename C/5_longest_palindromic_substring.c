#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Answer begin
#define MAX_SIZE 1000
#define TRUE 1
#define FALSE 0
#define max(a, b) ((a) > (b) ? (a) : (b))
int f[MAX_SIZE][MAX_SIZE];

char* longestPalindromeV1(char* s) {
    int len = strlen(s);
    int i, j, k;
    int start_index = 0;
    char* ans_str = NULL;
    int ans_len = 1;

    if (len == 0)
        return NULL;

    // printf("len = %d\n", len);
    memset(f, 0, sizeof(int) * MAX_SIZE * MAX_SIZE);
    for (i = 0; i < len; i++)
        f[i][i] = TRUE;
    for (i = 2; i <= len; i++)
    {
        // printf("i = %d\n", i);
        for (j = 0; j <= len - i; j++)
        {
            k = j + i - 1;
            if (s[j] == s[k] && (i == 2 || f[j+1][k-1] == TRUE))
            {
                f[j][k] = TRUE;
                ans_len = i;
                start_index = j;
                // printf("%d %d\n", i, j);
            }
        }
    }
    // printf("ans_len = %d\n", ans_len);
    ans_str = malloc(sizeof(char) * (ans_len+1));
    strncpy(ans_str, s+start_index, ans_len);
    ans_str[ans_len] = 0; // end of string
    return ans_str;
}

char* longestPalindrome(char* s)
{
    int len = strlen(s);
    int i, j, k;
    int ans_len = 0, start_index;
    char* ans_str = NULL;

    if (len == 0)
        return NULL;

    for (i = 0; i < len; i++)
    {
        // odd
        for (j = i - 1, k = i + 1; j >= 0 && k < len && s[j] == s[k]; j--, k++)
            ;
        if (k - j - 1 > ans_len)
        {
            ans_len = k - j - 1;
            start_index = j + 1;
        }
        for (j = i, k = i + 1; j >= 0 && k < len && s[j] == s[k]; j--, k++)
            ;
        if (k - j - 1 > ans_len)
        {
            ans_len = k - j - 1;
            start_index = j + 1;
        }
    }
    // printf("ans_len = %d\n", ans_len);
    ans_str = malloc(sizeof(char) * (ans_len+1));
    strncpy(ans_str, s+start_index, ans_len);
    ans_str[ans_len] = 0; // end of string
    return ans_str;
}
// Answer end

int main()
{
    // char* s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // char* s = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
    // char* s = "a";
    // char* s = "aa";
    char* s = "aabbaabbcc";
    printf("longestPalindrome = %s\n", longestPalindrome(s));
    return 0;
}