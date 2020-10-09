#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<bool> primeArr;

// 에라토스테네스의 체
void isPrime(int num)
{
    primeArr.resize(num + 1);
    
    fill(primeArr.begin(), primeArr.end(), true);
    
    primeArr[0] = false;
    primeArr[1] = false;
    
    for (int i = 2; i <= num; ++i)
    {
        if (primeArr[i])
        {
            for (int j = i * 2; j <= num; j += i)
            {
                primeArr[j] = false;
            }
        }
    }
}

// 7자리 이하의 숫자이므로
bool visit[10000000];
// 7이하 길이인 문자열 이므로
bool check[10];
int answer;

void dfs(string numbers, string number)
{
    if (!number.empty() && !visit[stoi(number)])
    {
        cout << stoi(number) << "\n";
        visit[stoi(number)] = true;
        if (primeArr[stoi(number)])
        {
            cout << "This is Prime : " << stoi(number) << "\n";
            answer++;
        }
    }
    
    for (int i = 0; i < numbers.length(); ++i)
    {
        if (check[i])
        {
            continue;
        }
        
        check[i] = true;
        dfs(numbers, number + numbers[i]);
        check[i] = false;
    }
}

int solution(string numbers) {
    memset(check, false, sizeof(check));
    memset(visit, false, sizeof(visit));
    
    // 내림차순 정렬을 해주어야 numbers로 만들 수 있는 가장 큰 수까지
    // 소수를 만들 수 있다.
    sort(numbers.begin(), numbers.end(), greater<>());
    
    isPrime(stoi(numbers));
    dfs(numbers, "");
    return answer;
}