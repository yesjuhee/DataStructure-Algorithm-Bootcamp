// 배열의 크기를 계산하는 예

#include <stdio.h>

void main()
{
    int aa[] = {10, 20, 30, 40, 50};
    int count;

    count = sizeof(aa) / sizeof(int);

    printf("배열 aa[]의 요소의 개수는 %d개 입니다.\n", count);
}