#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// W, S�� �ε����� �̹� ������ �κ����� �ƴ����� ����
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

    // ���� ���ϵ�ī�� ���̸�
    if (w == W.length())
    {
        return ret = (s == S.length());
    }
    
    if (W[w] == '*') // * �� ���Դٸ�
    {
        // S�� ���̱��� ��������
        // ���ϵ�ī���� ���� ���ؾ��ϹǷ� <= �� �ȴ�.
        for (int skip = 0; skip + s <= S.length(); ++skip)
        {
            // *�� ���� ��ġ ���� ���ڿ� �� ����
            // ���� * �� �������� ������ ���ڸ� ã�´� 
            if (solve(w + 1, s + skip))
            {
                // ret�� ����Ű�� dp[w][s]�� ���� 1�� ����
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
