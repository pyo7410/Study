#include <iostream>
using namespace std;


// arr이 일차원 배열인 이유는 i에 해당하는 열을 저장한것이다.
// 즉, arr[i] = 퀸을 놓을 j의 위치 가 된다.
int arr[16];
int n;
int result = 0;

bool promising(int i)
{
    // 대각선비교의 경우 arr[i] - arr[j] 가 음수이면 오른쪽, 양수이면 왼쪽 대각선 이고
    // abs(arr[i] - arr[j])의 값과 i - j의 값이 같으면 같은 대각선에 위치함을 의미한다.
    // 즉, 행번호 차이가 열번호 차이와 같다면 대각선상에 위치한 것이다.

    // 만약 열의 값이 같다면 직선상에 이미 퀸이 위치한 것이다.

    for (int j = 0; j < i; ++j)
    {
        if (arr[i] == arr[j] || abs(arr[i] - arr[j]) == i - j)
        {
            return false;
        }
    }
    return true;
}

void dfs(int i)
{
    if (i == n)
    {
        result += 1;
        return;
    }

    // 모든 열에 대해 퀸을 놓는다.
    for (int j = 0; j < n; ++j)
    {
        arr[i] = j;

        if (promising(i))
        {
            dfs(i + 1);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;

    dfs(0);

    cout << result << "\n";
    
    return 0;
}
