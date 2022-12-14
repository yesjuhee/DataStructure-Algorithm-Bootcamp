// strcmp() 함수 사용

#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[10] = "Hello";
    char *s2 = "Hello";
    char *s3 = "World";

    int ret1 = strcmp(s1, s2);
    int ret2 = strcmp(s1, s3);

    printf("ret1: %d\n", ret1);
    printf("ret2: %d\n", ret2);

    return 0;
}