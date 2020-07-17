#include <iostream>
using namespace std;

int power(int num, int pwr)
{
    if (pwr == 0)
    {
        return 1;
    }

    return num * power(num, pwr - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        int n;
        cin >> n;

        int num, pwr;
        cin >> num >> pwr;

        cout << "#" << test_case << " " << power(num, pwr) << "\n";
    }
    
    return 0;
}
