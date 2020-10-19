#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    vector<int> answer(2, 0);
    int word_cnt = words.size();
    map<string, int> m;

    m[words[0]] += 1;
    for (int i = 1; i < word_cnt; ++i)
    {
        if (m[words[i]] > 0 || words[i].front() != words[i - 1].back() || words[i].length() <= 1)
        {
            if ((i + 1) % n == 0)
            {
                answer[0] = n;
                answer[1] = (i + 1) / n;
            }
            else
            {
                answer[0] = (i + 1) % n;
                answer[1] = ((i + 1) / n) + 1;
            }

            return answer;
        }
        else
        {
            m[words[i]] += 1;
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
    
    int m;
    cin >> m;
    vector<string> words(m);

    for (int i = 0; i < m; ++i)
    {
        cin >> words[i];
    }

    solution(n, words);

    return 0;
}