#include <iostream>
#include <string>
#include <vector>
#define INF 987654321
using namespace std;

int result = INF;
string t;
vector<string> w;

void dfs(int cnt, string word, vector<bool> check)
{
    for (int i = 0; i < w.size(); ++i)
    {
        int count = 0;
        for (int j = 0; j < w[i].size(); ++j)
        {
            // words에서 사용하지 않은 단어이고
            // 단어에서 알파벳이 다르다면
            if (!check[i] && word[j] != w[i][j])
            {
                count++;
            }
        }

        // 한글자만 다르다면
        if (count == 1)
        {
            // 한 글자만 다른 단어가 target이고
            // 기존의 result 보다 cnt + 1이 더 작다면
            if (t == w[i] && result > cnt + 1)
            {
                // 한글자를 바꾸어야 하므로
                result = cnt + 1;
                return;
            }

            // words에서 해당 단어를 사용했으므로
            check[i] = true;
            
            dfs(cnt + 1, w[i], check);

            // dfs를 위해 다시 false로 변경
            check[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) 
{
    int answer = 0;
    w = words;
    t = target;

    vector<bool> check(words.size(), false);
    dfs(0, begin, check);

    if (result == INF)
    {
        return 0;
    }
    else
    {
        answer = result;
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

    string begin;
    string target;

    cin >> begin >> target;

    vector<string> words(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    cout << solution(begin, target, words);

    return 0;
}