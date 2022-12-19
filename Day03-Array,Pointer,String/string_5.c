// strtok() 함수 사용 문자열 분할

#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[30] = "There is no free lunch";

    char *ptr = strtok(s1, " ");

    while (ptr != NULL)
    {
        printf("%s\n", ptr);
        ptr = strtok(NULL, " ");
    }

    return 0;
}