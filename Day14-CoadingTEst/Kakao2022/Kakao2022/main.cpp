// 커트라인 4.5문제
// 4번까지 풀고, 5번을 완전 탐색으로 풀어서 효율성을 가져온 사람들이 통과
// https://tech.kakao.com/2022/01/14/2022-kakao-recruitment-round-1/#%EB%AC%B8%EC%A0%9C-1-%EC%8B%A0%EA%B3%A0-%EA%B2%B0%EA%B3%BC-%EB%B0%9B%EA%B8%B0
 
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

/** 1번 문제
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    // report에서 중복되는 요소 제거
    set<string> report_set(report.begin(), report.end());
    report.assign(report_set.begin(), report_set.end());
    
    // report를 vector<pair<string, string>> 으로 수정
    vector<pair<string, string>> upgrade_report;
    for (int i = 0; i < report.size(); i++)
    {
        // 공백으로 자르기
        string text = report[i];
        size_t pos = text.find(" ");
        string user = text.substr(0, pos);
        text.erase(0, pos + 1);
        string report_id = text;
        upgrade_report.push_back({user, report_id});
        
    }
    
    // 각 유저별로 신고당한 횟수 카운트
    vector<string> stopped_id;
    for (int i = 0; i < id_list.size(); i++) // id_list의 유저 한 명씩
    {
        int count = 0;
        string id = id_list[i];
        for (int j = 0; j < upgrade_report.size(); j++) // upgrade_report에 id가 있는지 확인
        {
            if (id.compare(upgrade_report[j].second) == 0) count++;
            if (count >= k)
            {
                stopped_id.push_back(id); // k번 이상 report라면 따로 기록하고 다음 id 확인
                break;
            }
        }
    }
    
    // 매일 개수 카운트
    vector<int> answer(id_list.size(), 0);
    for (int i = 0; i < id_list.size(); i++)
    {
        for (int j = 0; j < upgrade_report.size(); j++)
        {
            if (upgrade_report[j].first == id_list[i] &&
                find(stopped_id.begin(), stopped_id.end(), upgrade_report[j].second) != stopped_id.end())
            {
                answer[i]++;
            }
        }
    }
    
    return answer;
}
 */

// 2번 문제
int solution(int n, int k) {
    
    // 1. n을 k진수로 변경
    vector<int> k_decimal;
    int quotient = n;
    int remainder = 0;
    while (quotient > k)
    {
        remainder = quotient % k;
        quotient = quotient / k;
        k_decimal.push_back(remainder);
    }
    k_decimal.push_back(quotient);
    reverse(k_decimal.begin(), k_decimal.end());
    
    // 2. 0을 기준으로 쪼갠 수들을 벡터로 저장
    vector<int> numbers;
    int s = 0;
    int e = 0;
    while (e != k_decimal.size() + 2)
    {
        int new_number = 0;
        // e가 멈출 곳 찾기
        while (k_decimal[e] != 0 & e != k_decimal.size()) e++;
        int num_size = e - s;
        for (int i = 0; i < num_size; i++)
        {
            new_number += k_decimal[s+i] * pow(10, num_size-i-1);
        }
        s = e + 1;
        e += 2;
        numbers.push_back(new_number);
    }
    
    // 3. numbers 요소에 대해 소수 판별 & count
    int answer = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        bool is_prime = true;
        int num = numbers[i];
        if (num == 1) continue;
        
        for (int divisor = 1; divisor < sqrt(num); divisor++)
        {
            if (num / divisor == 0)
            {
                is_prime = false;
                break;
            }
        }
        
        if (is_prime)
        {
            answer++;
        }
    }
    
    return answer;
}

int main(void)
{
    /**
    vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
    vector<string> report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    int k = 2;
    
    vector<int> result = solution(id_list, report, k);
    for (int i=0; i<result.size(); i++)
    {
        cout << result[i] << '\n';
    }
     */
    
    int n = 110011;
    int k = 10;
    int result = solution(n, k);
    cout << result << '\n';
    
    return 0;
}
