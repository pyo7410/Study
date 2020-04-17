#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool next_permutation(int *a, int n)
{
    // ���ʿ� n - 1�� i �� ���Ƿ� �迭�� �ε����� ������ ��
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
    swap(a[i - 1], a[j]); // ������ a[i - 1]���� ũ�鼭 ���� ���� �� ��
    j = n - 1; // �� �ʱ�ȭ ���� �� ��
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

    // �迭�� �ε��� ����
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    if (next_permutation(a, n))
    {
        // �迭�� �ε��� ����
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
