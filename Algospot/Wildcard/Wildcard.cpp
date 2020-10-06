#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// W, S의 인덱스가 이미 조사한 부분인지 아닌지를 저장
int dp[101][101];

string W, S;

bool solve(int w, int s)
{
    int& ret = dp[w][s];
    if (ret != -1)
    {
        return ret;
    }

    while (w < W.length() && s < S.length() && (W[w] == '?' || W[w] == S[s]))
    {
        ++w;
        ++s;
    }

    // 만약 와일드카드 끝이면
    if (w == W.length())
    {
        return ret = (s == S.length());
    }
    
    if (W[w] == '*') // * 가 나왔다면
    {
        // S의 길이까지 나가더라도
        // 와일드카드의 끝과 비교해야하므로 <= 이 된다.
        for (int skip = 0; skip + s <= S.length(); ++skip)
        {
            // *의 다음 위치 부터 문자열 끝 까지
            // 다음 * 가 나오던가 대응할 글자를 찾는다 
            if (solve(w + 1, s + skip))
            {
                // ret이 가리키는 dp[w][s]의 값을 1로 변경
                return ret = 1;
            }
        }
    }

    return ret = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int c;
    cin >> c;

    vector<string> ans;

    while (c--)
    {
        cin >> W;

        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            cin >> S;
            memset(dp, -1, sizeof(dp));

            if (solve(0, 0))
            {
                ans.push_back(S);
            }
        }

        sort(ans.begin(), ans.end());
        for (string str : ans)
        {
            cout << str << "\n";
        }

        ans.clear();
    }

    return 0;
}
