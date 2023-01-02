// 카카오 2020 신입 채용 코딩테스트 1차
// https://tech.kakao.com/2019/10/02/kakao-blind-recruitment-2020-round1/

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;


// 1번 문제
int solution1(string s)
{
    int answer = 0, str_len = 0, unit = 0;
    
    str_len = (int)s.size();
    answer = str_len;
    
    for (unit = 1; unit <= str_len/2; unit++)
    {
        int result_len = 0;
        int abstract_array[10001] = {0};
        abstract_array[0] = 1;
        int abstract_array_len = str_len/unit;
        
        // 뒤에 남는 애들 먼저 카운트
        result_len += str_len % unit;
        
        for (int i = 0; i < abstract_array_len; i++)
        {
            int str1_index = i * unit;
            int str2_index = str1_index + unit;
            bool is_same = true;
            // 두 문자열 비교
            for (int j = 0; j < unit; j++)
            {
                if (s[str1_index+j] == s[str2_index+j]) continue;
                else
                {
                    is_same = false;
                    break;
                }
            }
            // 같으면 그대로, 다르면 +1
            if (is_same)
            {
                abstract_array[i+1] = abstract_array[i];
            }
            else
            {
                abstract_array[i+1] = abstract_array[i] + 1;
            }
        }
        // 문자열 배열을 정수형 배열로 변경
        int iteration_number = 1;
        for (int i = 0; i < abstract_array_len; i++)
        {
            if (abstract_array[i] == abstract_array[i+1])
            {
                iteration_number++;
                continue;
            }
            
            // abstract_array[i] != abstract_array[i+1];
            if (iteration_number > 1)
            {
                // 앞에 반복되는게 있었다면 -> 압축된 버전 추가 -> iteration_number의 크기에 따라서!!
                
                // iteration_number 자리수 구하기
                int count = 1;
                while (iteration_number >= 10)
                {
                    iteration_number = iteration_number / 10;
                    count++;
                }
                
                result_len += unit + count;
                iteration_number = 1;
            }
            else
            {
                // 앞에 반복되는게 없었다면 -> 그냥 앞에 있는 것 길이만큼 추가
                result_len += unit;
            }
        }
        
        if (result_len < answer) answer = result_len;
    }
    
    return answer;
}


// 2번 문제
bool is_valanced(string u)
{
    int left = 0, right = 0;
    int str_length = (int)u.size();
    
    for (int i = 0; i < str_length; i++)
    {
        if (u[i] == '(') left++; else right++;
    }
    
    if (left == right) return true;
    else return false;
}

bool is_correct(string u)
{
    stack<char> check_stack;
    
    for (int i = 0; i < u.size(); i++)
    {
        if (u[i] == '(') check_stack.push('(');
        else // u[i] == ')'
        {
            if (check_stack.empty()) return false;
            else check_stack.pop();
        }
    }
    
    if (check_stack.empty()) return true;
    else return false;
}

string solution2(string p)
{
        
    // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
    if (p.empty()) return "";
    
    // 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다.
    // 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며,
    // v는 빈 문자열이 될 수 있습니다.
    int str_length = (int)p.size();
    string u = "", v = "";
    
    for (int i = 1; i <= str_length; i++)
    {
        u = p.substr(0, i);
        if (i == str_length) v = "";
        else v = p.substr(i, str_length-i);
        if (is_valanced(u)) break;
    }
    
    // 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
        // 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
    if (is_correct(u))
    {
        return u + solution2(v);
    }
    
    // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
      // 4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
      // 4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
      // 4-3. ')'를 다시 붙입니다.
      // 4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
      // 4-5. 생성된 문자열을 반환합니다.
    string new_str = "";
    new_str += '('; // 4-1
    new_str += solution2(v); // 4-2
    new_str += ')'; // 4-3
    for (int i = 1; i < u.size() - 1; i++) // 4-4
    {
        if (u[i] == '(') new_str += ')';
        else new_str += '(';
    }
    
    return new_str;
}



int main()
{
    string p = ")(";
    cout << solution2(p) << "\n";
    
    return 0;
}
