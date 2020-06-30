#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char alpha[256];

int calc(vector<string> &a, vector<char> &letters, vector<int> &d)
{
    int m = letters.size();
    int sum = 0;

    for (int i = 0; i < m; ++i)
    {
        // alpha 배열에는 각 알파벳의 아스키코드에 맞추어 알파벳의 값이 저장된다..
        // unique와 sort를 썻기 때문에
        alpha[letters[i]] = d[i];
    }

    for (string s : a)
    {
        int now = 0;
        for (char x : s)
        {
            now = now * 10 + alpha[x];
        }
        sum += now;
    }
    return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    vector<string> a(n);
    vector<char> letters;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        for (char x : a[i])
        {
            letters.push_back(x);
        }
    }

    sort(letters.begin(), letters.end());
    letters.erase(unique(letters.begin(), letters.end()), letters.end());
    // unique는 연속된 중복원소를 벡터의 맨 뒤로 보내버린다! -> 중복된 원소가 아닌 연속된 중복 원소임을 주의!
    // unique는 반환값으로 벡터에서 중복원소의 첫번째 위치를 반환한다.
    // sort했으므로 중복된 원소는 연속으로 쓰이게 된다!

    int m = letters.size();
    vector<int> d;

    for(int i = 9; i > 9 - m; i--)
    {
        d.push_back(i);
    }

    sort(d.begin(), d.end());

    int ans = 0;
    do
    {
        int now = calc(a, letters, d);
        if (ans < now)
        {
            ans = now;
        }
    } while (next_permutation(d.begin(), d.end()));
    cout << ans << "\n";

    return 0;
}
