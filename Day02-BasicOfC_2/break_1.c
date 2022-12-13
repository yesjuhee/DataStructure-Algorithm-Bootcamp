// for문에서 break문으로 조건 만족시 탈출

void main()
{
    int sum = 0;
    int i;

    for (i = 1; i <= 100; i++)
    {
        sum = sum + i;

        if (sum >= 1000)
            break;
    }

    printf("1~100의 합에서 최초로 100이 넘는 위치는? : %d\n", i);
}