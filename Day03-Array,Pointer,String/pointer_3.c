// 2차원 배열 값 할당, for문 1번만 써서 모든 원소 접근

int main()
{
    int arr[3][5];
    int *ptr;
    int i, j, x, y;
    ptr = arr;

    // for문 두 번 써서 입력
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            // arr[i][j] = i*5 + j; ==> 배열로 접근
            // ptr[i][j] = i*5 + j; ==> ptr은 배열이 아닌 포인터 변수이기 때문에 이런식으로 접근은 불가능
            // *(arr + i * 5 + j) = i * 5 + j; ==> 이것도 안되는데,, arr는 int[5]의 포인터? 이중 포인터 개념인가?
            // *(arr[i] + j) = i * 5 + j; ==> 정상 작동
            *(ptr + i * 5 + j) = i * 5 + j;
        }
    }

    // for문 한 번 써서 출력
    for (i = 0; i < 15; i++)
    {
        x = i / 5;
        y = i % 5;
        printf("arr[%d][%d] = %d\n", x, y, arr[x][y]);
    }
}