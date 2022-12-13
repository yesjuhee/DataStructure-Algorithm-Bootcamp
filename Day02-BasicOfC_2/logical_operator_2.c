// 비트 연산으로 if문 대체

#include <stdio.h>

int main()
{
    char a = 3;
    a > 2 && a++; // 앞이 참이면 뒤 문장 실행
    a > 2 || a++; // 앞이 거짓이면 뒤 문장 실행
    printf("a = %d\n", a);

    return 0;
}