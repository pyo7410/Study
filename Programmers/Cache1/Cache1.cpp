#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) 
{
    int answer = 0;
    int cnt_cities = cities.size();

    // 시간과 도시이름 저장
    map<int, string> m;

    // cities의 각 원소들을 전부 대문자로 바꾸어준다.
    for (int i = 0; i < cnt_cities; ++i)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
    }

    // cacheSize가 0일 경우 전체 도시의 수 * 5가 정답이 되므로
    // 전체 도시의 수 * 5를 반환하면 된다.
    if (cacheSize == 0)
    {
        return cnt_cities * 5;
    }

    for (int i = 0; i < cnt_cities; ++i)
    {
        // 도시가 cache에 있는지 검사하는 flag
        bool flag = false;

        // map 안에 도시가 있는지 전체 조사
        for (auto iter : m)
        {
            // 해당 도시가 있다면
            if (cities[i] == iter.second)
            {
                // 다시 값을 넣기 위해 도시이름을 저장
                string city = iter.second;
                // map의 해당위치 값을 지운다.
                m.erase(iter.first);

                // hit 이므로 +1 해주고
                answer += 1;
                // 다시 map에 삽입
                m[answer] = city;
                // 도시가 cache에 있으므로
                flag = true;
                // 도시를 찾았으므로 더이상 반복문을 안돌아도 된다.
                break;
            }
        }

        // cache에서 도시를 찾아 hit 했으므로
        // 다음 도시 조사
        if (flag)
        {
            continue;
        }

        // 반복문을 전부 돌았는데도 cache에서 도시를 찾지 못했다면 miss이므로
        // map의 크기가 cacheSize와 같다면 cache가 다 찼다는 의미이므로
        if (m.size() == cacheSize)
        {
            // map은 삽입할때 정렬이 되므로
            // map의 맨 앞의 값이 LRU가 된다.
            m.erase(m.begin());
        }

        // miss 이므로 +5
        answer += 5;
        // cache에서 이미 LRU를 뺏거나 cacheSize보다 적은 수의 도시가
        // map에 있으므로 맵에 새로운 값을 삽입
        m[answer] = cities[i];
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cacheSize;
    cin >> cacheSize;
    
    int n;
    cin >> n;
    vector<string> cities(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> cities[i];
    }

    cout << solution(cacheSize, cities) << "\n";

    return 0;
}