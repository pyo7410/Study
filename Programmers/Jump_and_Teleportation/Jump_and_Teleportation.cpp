#include <iostream>
using namespace std;

int solution(int N)
{
    int ans = 0;
    
    while (N != 0)
    {
        if (N % 2 == 1)
        {
            ans++;
            N -= 1;
        }
        else
        {
            N /= 2;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    cout << solution(n) << "\n";

    return 0;
}