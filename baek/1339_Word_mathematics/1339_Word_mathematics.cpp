#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

// char?? 1??? ??? 2^8 = 256
// ???? ???? ?????? ???? ?? ?? ???? ??
char alpha[256];

int calc(vector<string> &str, vector<char> &letters, vector<int> &d)
{
    int sum = 0;
    int m = letters.size();    

    // ??? ??? ?? ??? ???? ???? ???? ??
    for (int i = 0; i < m; ++i)
    {
        alpha[letters[i]] = d[i];
    }

    for (string s : str)
    {
        int now = 0;
        for (char ch : s)
        {
            // for?? ?? 0?? ????? ??
            // ????? 0?? ???? ? ? ???
            // ?? 10? ???? ??.
            now = now * 10 + alpha[ch];
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

    int n ;
    cin >> n;

    vector<string> str(n);
    vector<char> letters;

    for (int i = 0; i < n; ++i)
    {
        cin >> str[i];

        for (char ch : str[i])
        {
            letters.push_back(ch);
        }
    }

    sort(letters.begin(), letters.end());

    // unique? ??? ??? ????? ???? ??? ??? ???? ????.
    letters.erase(unique(letters.begin(), letters.end()), letters.end());

    int ans = 0;
    int m = letters.size();
    vector<int> d;

    // ?? ??? ? ??? ???? ??? ???.
    for (int i = 9; i > 9 - m; i--)
    {
        d.push_back(i);
    }

    sort(d.begin(), d.end());

    do {
        int now = calc(str, letters, d);
        if (ans < now)
        {
            ans = now;
        }
    } while (next_permutation(d.begin(), d.end()));

    cout << ans << "\n";

    return 0;    
}
