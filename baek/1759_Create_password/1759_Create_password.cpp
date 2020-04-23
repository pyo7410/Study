#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string password)
{
    int vowels = 0;
    int consonants = 0;

    for (char c : password)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            vowels++;
        }
        else
        {
            consonants++;
        }
    }

    return (vowels >= 1 && consonants >= 2);
}

void go(int n, vector<char>& alpha, string password, int index)
{
    if (password.length() == n)
    {
        if(check(password))
        {
            cout << password << "\n";
        }
        return;
    }
    if (index >= alpha.size())
    {
        return;
    }

    go(n, alpha, password + alpha[index], index + 1);
    go(n, alpha, password, index + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int l, c;
    cin >> l >> c;

    vector<char> alpha(c);

    for (int i = 0; i < c; ++i)
    {
        cin >> alpha[i];
    }

    sort(alpha.begin(), alpha.end());

    go(l, alpha, "", 0);

    return 0;
}
