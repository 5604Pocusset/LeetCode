#include <stdio.h>
#include <string.h>

/* Answer begin */
#define TRUE 1
#define FALSE 0

int isMatch(char* s, char* p) {
    int condition_star = (strlen(p) > 1 && p[1] == '*');
    int condition_match = (strlen(s) > 0 && (p[0] == '.' || s[0] == p[0]));

    // puts(s);
    // puts(p);
    // puts("");
    if (strlen(p) > 4 && p[0] == p[2] && p[1] == '*' && p[3] == '*')
        return isMatch(s, p + 2);
    if (strlen(s) == 0 && strlen(p) == 0)
        return TRUE;
    if (strlen(s) != strlen(p) && strchr(p, '*') == NULL)
        return FALSE;

    if (condition_star)
    {
        if (isMatch(s, p + 2))
            return TRUE;
        if (condition_match && isMatch(s + 1, p))
            return TRUE;
    }
    else
    {
        if (condition_match && isMatch(s + 1, p + 1))
            return TRUE;
    }
    return FALSE;
}
/* Answer end */

int main()
{
    // int answer1 = isMatch("aa", "a");
    // int answer2 = isMatch("aa","aa");
    // int answer3 = isMatch("aaa","aa");
    // int answer4 = isMatch("aa", "a*");
    // int answer5 = isMatch("aa", ".*");
    // int answer6 = isMatch("ab", ".*");
    // int answer7 = isMatch("aab", "c*a*b");
    // int answer8 = isMatch("", "c*c*");
    int answer9 = isMatch("c", ".*b");
    int answer10 = isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c");
    // puts(answer1 ? "TRUE" : "FALSE");
    // puts(answer2 ? "TRUE" : "FALSE");
    // puts(answer3 ? "TRUE" : "FALSE");
    // puts(answer4 ? "TRUE" : "FALSE");
    // puts(answer5 ? "TRUE" : "FALSE");
    // puts(answer6 ? "TRUE" : "FALSE");
    // puts(answer7 ? "TRUE" : "FALSE");
    // puts(answer8 ? "TRUE" : "FALSE");
    puts(answer9 ? "TRUE" : "FALSE");
    puts(answer10 ? "TRUE" : "FALSE");
    return 0;
}