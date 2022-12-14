// 지역/전역 변수 구분

#include <stdio.h>

void func1()
{
    int a = 200;
    printf("func1()에서 a의 값 ==> %d\n", a);
}

void main()
{
    int a = 10;

    func1();
    printf("main()에서 a의 값 ==> %d\n", a);
}