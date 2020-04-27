#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

char a[10];
bool check[10];
int k;
vector<string> ans;

bool ok(char x, char y, char op)
{
    if (op == '<')
    {
        if (x > y)
        {
            return false;
        }
    }
    if (op == '>')
    {
        if (x < y)
        {
            return false;
        }
    }
    return true;
}

void go(int index, string num)
{
    if (index == k + 1) // index == k 라면 맨 마지막을 처리하지 못한다!
    {
        ans.push_back(num);
        return;
    }
    for (int i = 0; i <= 9; ++i)
    {
        if (check[i])
        {
            continue;
        }
        if (index == 0 || ok(num[index - 1], i + '0', a[index - 1]))
        {
            check[i] = true;
            go(index + 1, num + to_string(i));
            check[i] = false;
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
    cin >> k;

    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
    }

    go(0, "");

    auto p = minmax_element(ans.begin(), ans.end());

    cout << *p.second << "\n";
    cout << *p.first << "\n";

    return 0;
}
