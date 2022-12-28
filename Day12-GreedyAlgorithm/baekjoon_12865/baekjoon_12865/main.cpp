// 평범한 배낭

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, w, v;
    vector<pair<int, int>> products; //물건의 (무게, 가치) 저장

    // 입력
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> w >> v;
        products.push_back({w, v});
    }

    // 가치 테이블 초기화
    //int value_table[101][100001] = {0}; -> 메모리 관련 오류(너무큼?)
    vector<vector<int>> value_table(101, vector<int>(100001, 0)); // 2차원 벡터 이용

    // 가치 테이블 채우기
    for (int product_num = 1; product_num <= n; product_num++)
    {
        // 물건 하나 선택
        int product_weight = products.back().first;
        int product_value = products.back().second;
        products.pop_back();
        for (int max_weight = 1; max_weight <= k; max_weight++)
        {
            int old_value = value_table[product_num-1][max_weight];
            // 물건 무게가 max_weight를 초과하는지 확인
            if (product_weight > max_weight)
            {
                value_table[product_num][max_weight] = old_value;
            }
            else
            {
                int new_value = product_value + value_table[product_num-1][max_weight-product_weight];
                value_table[product_num][max_weight] = max(old_value, new_value);
            }
        }
    }

    // 출력
    cout << value_table[n][k] << "\n";

    return 0;
}
