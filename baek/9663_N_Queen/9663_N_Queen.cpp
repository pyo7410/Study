#include <iostream>
using namespace std;


// arr�� ������ �迭�� ������ i�� �ش��ϴ� ���� �����Ѱ��̴�.
// ��, arr[i] = ���� ���� j�� ��ġ �� �ȴ�.
int arr[16];
int n;
int result = 0;

bool promising(int i)
{
    // �밢������ ��� arr[i] - arr[j] �� �����̸� ������, ����̸� ���� �밢�� �̰�
    // abs(arr[i] - arr[j])�� ���� i - j�� ���� ������ ���� �밢���� ��ġ���� �ǹ��Ѵ�.
    // ��, ���ȣ ���̰� ����ȣ ���̿� ���ٸ� �밢���� ��ġ�� ���̴�.

    // ���� ���� ���� ���ٸ� ������ �̹� ���� ��ġ�� ���̴�.

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

    // ��� ���� ���� ���� ���´�.
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
