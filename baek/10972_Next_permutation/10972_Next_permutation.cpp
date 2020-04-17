#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool next_permutation(int *a, int n)
{
    // 애초에 n - 1이 i 로 들어가므로 배열의 인덱스를 주의할 것
    int i = n - 1;
    while (i > 0 && a[i - 1] >= a[i])
    {
        i -= 1;
    }
    if (i <= 0)
    {
        return false;
    }
    int j = n - 1;
    while (a[j] <= a[i - 1])
    {
        j -= 1;
    }
    swap(a[i - 1], a[j]); // 어차피 a[i - 1]보다 크면서 제일 작은 수 임
    j = n - 1; // 꼭 초기화 잊지 말 것
    while (i < j)
    {
        swap(a[i], a[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    int a[10000];
    cin >> n;

    // 배열의 인덱스 주의
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    if (next_permutation(a, n))
    {
        // 배열의 인덱스 주의
        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << " ";
        }
    }
    else
    {
        cout << "-1";
    }
    
    cout << "\n";

}
