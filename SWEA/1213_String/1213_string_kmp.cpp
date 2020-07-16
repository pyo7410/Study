#include <iostream>
#include <string>
using namespace std;

int skip[11];

void kmpMatch(string str)
{
    int j = 0;
    for (int i = 1; i < str.length(); ++i)
    {
        while (j > 0 && str[i] != str[j])
        {
            j = skip[j - 1];
        }

        if (str[i] == str[j])
        {
            skip[i] = ++j;
        }    
    }
}

int kmp(string str, string target)
{
    int j = 0;
    int cnt = 0;
    
    for (int i = 0; i < str.length(); ++i)
    {
        while (j > 0 && str[i] != target[j])
        {
            j = skip[j - 1];
        }
        if (str[i] == target[j])
        {
            if (j == target.length() - 1)
            {
                cnt += 1;
                j = skip[j];
            }
            else
            {
                j += 1;
            }            
        }
    }
    return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);    

    for (int i = 1; i <= 10; ++i)
    {
        int n;
        string str;
        string target;

        cin >> n >> target >> str;

        kmpMatch(target);
        cout << "#" << i << " " << kmp(str, target) << "\n";
    }

    return 0;
}
