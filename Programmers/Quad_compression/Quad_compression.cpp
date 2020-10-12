#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ans_0;
int ans_1;

// solve의 매개변수로 arr을 넘기게되면
// 시간초과가 뜰 수 있음을 주의하자.
vector<vector<int>> Arr;

void solve(int x, int y, int n)
{
    if (n <= 0)
    {
        return;
    }

    int cnt_0 = 0;

    for (int i = y; i < y + n; ++i)
    {
        for (int j = x; j < x + n; ++j)
        {
            if (Arr[i][j] == 0)
            {
                cnt_0++;
            }
        }
    }

    if (cnt_0 == n * n)
    {
        ans_0++;
    }
    else if (cnt_0 == 0)
    {
        ans_1++;
    }
    else if (n * n == 4)
    {
        ans_0 += cnt_0;
        ans_1 += 4 - cnt_0;
    }
    else
    {
        solve(x, y, n / 2);
        solve(x + (n / 2), y, n / 2);
        solve(x, y + (n / 2), n / 2);
        solve(x + (n / 2), y + (n / 2), n / 2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    Arr = arr;

    solve(0, 0, arr.size());

    answer.push_back(ans_0);
    answer.push_back(ans_1);

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }

    solution(arr);

    return 0;
}