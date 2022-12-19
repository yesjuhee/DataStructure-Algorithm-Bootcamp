// 점 연산자로 구조체 접근

#include <stdio.h>
#include <string.h>

struct employee
{
    char name[20];
    int year;
    int pay;
};

int main()
{
    int i;
    struct employee MCSL[3] = {
        {"Jong-Beom Jeong", 2018, 4000},
        {"Soonbin Lee", 2019, 4200},
        {"YiHyun Choi", 2022, 3000}};

    for (i = 0; i < 3; i++)
    {
        printf("Name : %s\n", MCSL[i].name);
        printf("Year : %d\n", MCSL[i].year);
        printf("Pay : %d\n\n", MCSL[i].pay);
    }
}