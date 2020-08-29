#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define MAX 987654321;
using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> answer;

    // 전체 보석을 담을 map
    unordered_map<string, int> total_gem;
    // 구매할 보석을 담을 map
    unordered_map<string, int> buy_gems;

    int gems_size = gems.size();
    for (int i = 0; i < gems_size; ++i)
    {
        total_gem[gems[i]] += 1;
    }

    int total_gems_cnt = total_gem.size();

    // 시작지점과 끝지점을 기록할 변수
    // left -> 모든 보석이 포함되면 최소구간의 답을 찾기 위해 +1씩 증가해간다.
    // right -> 모든 보석이 포함안되면 새로운 구간을 추가해 모든 보석이 포함할때까지 +1씩 증가해간다.
    // 만약 최소문제가 아닌 최대문제라면 left를 줄일 필요가 없을 것...
    // 애초에 최대가 말이 안되기는 한다. gems의 전체범위가 최대일 것 이므로
    int left = 0, right = 0;

    // 초기화
    answer.push_back(left);
    answer.push_back(right);
    buy_gems[gems[0]] += 1;

    int min = MAX;
    while (left < gems_size && right < gems_size)
    {
        // 구매할 보석에 전체 보석이 포함되어있다면
        if (buy_gems.size() == total_gems_cnt)
        {
            int gem_cnt = 0;

            // 보석들의 전체 빈도수를 구한다.
            for (auto iter = buy_gems.begin(); iter != buy_gems.end(); ++iter)
            {
                gem_cnt += iter->second;
            }

            // 최소 구간을 정하는 것이므로
            if (min > gem_cnt)
            {
                min = gem_cnt;
                answer[0] = left + 1;
                answer[1] = right + 1;
            }

            // left의 위치를 +1 하기위해서 우선 기존 left 값의 보석의 빈도수를 1빼주어야한다.
            buy_gems[gems[left]] -= 1;
            // 만약 보석의 빈도수가 0이라면 map에서 빼주어야 한다.
            // 안그럴경우 if (buy_gems.size() == total_gems_cnt) 조건에 계속 걸리게되어
            // 이상한 답이 출력된다.
            if (buy_gems[gems[left]] == 0)
            {
                buy_gems.erase(gems[left]);
            }
            left += 1;
        }
        else // 만약 구매할 보석에 전체보석이 포함되어있지 않다면
        {
            right += 1;

            if (right < gems_size)
            {
                // 이동한 right의 보석 빈도수를 추가해준다.
                buy_gems[gems[right]] += 1;
            }
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }

    vector<int> ans = solution(s);

    return 0;
}
