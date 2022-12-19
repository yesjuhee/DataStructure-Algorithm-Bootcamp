// 화살표 연산자로 구조체 접근

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
    struct employee Jeong;
    struct employee *Sptr = &Jeong;
    strcpy(Sptr->name, "Jong-Beom Jeong");
    Sptr->year = 2018;
    Sptr->pay = 4000;

    printf("Name : %s\n", Sptr->name);
    printf("Year : %d\n", Sptr->year);
    printf("Pay : %d\n", Sptr->pay);
}