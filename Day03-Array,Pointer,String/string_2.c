// 문자형 배열 선언, 복사, 출력

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[10];
    char str2[10];
    char str3[10] = "CookBook";

    strcpy(str1, "Basic-C");
    strcpy(str2, str3);

    printf("str1 ==> %s\n", str1);
    printf("str2 ==> %s\n", str2);
    printf("str3 ==> %s\n", str3);
}