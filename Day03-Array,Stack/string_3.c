// strcat() 함수 사용

#include <stdio.h>
#include <string.h>

int main(void)
{
    char ss[7] = "XYZ";

    strcat(ss, "ABC");

    printf("이어진 문자열 ss의 내용 ==> %s\n", ss);
}