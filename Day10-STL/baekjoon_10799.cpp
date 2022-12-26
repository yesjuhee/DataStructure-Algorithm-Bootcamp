#include <stdio.h>
#include <stack>

using namespace std;

int main(void)
{
    int count = 0;
    char input_brackets[100001];
    stack<char> count_stack;

    // cin >> input_brackets;
    scanf("%s", input_brackets);

    for (int i = 0; input_brackets[i]; i++)
    {
        if (input_brackets[i] == '(')
        {
            count_stack.push('(');
        }
        else if (input_brackets[i - 1] == '(')
        {
            // 레이저 등장
            count_stack.pop();
            count += count_stack.size();
        }
        else
        {
            // 막대기 끝
            count_stack.pop();
            count += 1;
        }
    }

    // cout << count << '\n';
    printf("%d\n", count);

    return 0;
}