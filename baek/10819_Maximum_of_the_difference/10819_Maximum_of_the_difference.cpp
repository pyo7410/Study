#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result(vector<int>& a)
{
    int sum = 0; // 0으로 초기화 잊지말자... 왠진 모르지만 무한루프 같은 오류에 빠짐

    for (int i = 1; i < a.size(); ++i)
    {
        sum += abs(a[i - 1] - a[i]);
    }

    return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    int ans = 0;
    int temp = 0;

    cin >> n; // 입력 받아야지... 안받고 하니 배열이 60개가.... 조심하자!
    
    vector<int> a(n); // n을 입력받고 메모리 확보 초기화 해야지... 안하니깐 segmentation fault 뜨지.... ㅜ

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    do
    {

        temp = result(a);
        ans = max(ans, temp);

    } while (next_permutation(a.begin(), a.end()));

    cout << ans << "\n";
    
    return 0;
}