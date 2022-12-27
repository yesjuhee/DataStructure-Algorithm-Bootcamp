#include <stdio.h>

int main(void)
{
    int n;
    int i = 2;
    int fibonacci_arr[46] = {0};
    fibonacci_arr[0] = 0;
    fibonacci_arr[1] = 1;

    scanf("%d", &n);

    if (n == 1)
    {
        printf("1\n");
        return 0;
    }

    while (fibonacci_arr[n] == 0)
    {
        fibonacci_arr[i] = fibonacci_arr[i - 1] + fibonacci_arr[i - 2];
        i++;
    }
    printf("%d\n", fibonacci_arr[n]);

    return 0;
}