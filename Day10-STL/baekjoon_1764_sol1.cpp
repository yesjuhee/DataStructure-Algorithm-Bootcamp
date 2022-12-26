// 1764번 듣보잡
// Solution 1. cin, cout, vector를 이용
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int d, b, cnt = 0;
    vector<string> dbj;
    vector<int> overlap;

    cin >> d >> b;
    dbj.resize(d + b);

    for (int i = 0; i < d + b; i++)
    {
        cin >> dbj[i];
    }

    sort(dbj.begin(), dbj.end());

    for (int i = 0; i < (d + b - 1); i++)
    {
        if (dbj[i] == dbj[i + 1])
        {
            cnt++;
            overlap.push_back(i);
        }
    }
    cout << cnt << '\n';

    for (int i = 0; i < overlap.size(); i++)
    {
        cout << dbj.at(overlap[i]) << '\n';
    }
}