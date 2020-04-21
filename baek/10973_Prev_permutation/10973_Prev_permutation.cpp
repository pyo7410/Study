#include <iostream>
#include <vector>
using namespace std;

bool next_permutation(int *a, int n)
{
    int i = n - 1;
    while (i > 0 && a[i - 1] <= a[i])
    {
        i -= 1;
    }
    if (i <= 0)
    {
        return false;
    }
    int j = n - 1;
    while (a[j] >= a[i - 1])
    {
        j -= 1;
    }
    swap(a[i - 1], a[j]); 
    j = n - 1; 
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

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    if (next_permutation(a, n))
    {
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
