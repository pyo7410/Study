#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result(vector<int>& a)
{
    int sum = 0; // 0���� �ʱ�ȭ ��������... ���� ������ ���ѷ��� ���� ������ ����

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

    cin >> n; // �Է� �޾ƾ���... �ȹް� �ϴ� �迭�� 60����.... ��������!
    
    vector<int> a(n); // n�� �Է¹ް� �޸� Ȯ�� �ʱ�ȭ �ؾ���... ���ϴϱ� segmentation fault ����.... ��

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