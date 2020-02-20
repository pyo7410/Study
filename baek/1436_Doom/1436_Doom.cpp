#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, tmp, i;
    int check = 0;
    cin >> n;

    for (i = 0; ;++i)
    {
        tmp = i;
        while (tmp)
        {
            if (tmp % 1000 == 666)
            {
                check++;
                break;
            }            
            tmp /= 10;
        }
        if (check == n)
        {
            break;
        }
    }

    cout << i << "\n";
}
