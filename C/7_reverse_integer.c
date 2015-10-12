#include <stdio.h>

#define MAX_INT 2147483647

int reverse(int x) {
    int sign = (x >= 0 ? 1 : -1);
    int rx = 0;
    x = x * sign;
    for (; x > 0; x /= 10)
    {
        if (rx > 214748364 || (rx == 214748364 && x > 7))
            return 0;
        rx = rx * 10 + x % 10;
    }
    return rx*sign;
}

int main()
{
    printf("%d\n", reverse(123));
    printf("%d\n", reverse(-123));
    printf("%d\n", reverse(1534236469));
    return 0;
}