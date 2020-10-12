#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) 
{
    int answer = 0;
    int citations_size = citations.size();
    
    sort(citations.begin(), citations.end(), greater<int>());

    int h = 0;

    for (int i = 0; i < citations_size; ++i)
    {
        // 조건에 부합하여 citations의 끝까지 갔을 경우의 값
        ++h;

        // h 편 이상이라면
        if (i + 1 >= citations[i])
        {
            if (i + 1 > citations[i])
            {
                h = i;
            }
            else
            {
                h = i + 1;
            }

            break;
        }
    }

    answer = h;

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> citations(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> citations[i];
    }

    cout << solution(citations) << "\n";

    return 0;
}