// 얕은 복사

#include <stdio.h>

void func1(int a)
{
    a = a + 1;
    printf("전달받은 a ==> %d\n", a);
}

void main()
{
    int a = 10;

    func1(a);
    printf("func1() 실행 후의 a ==> %d\n", a);
}