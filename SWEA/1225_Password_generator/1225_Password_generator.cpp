#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        int n;
        cin >> n;

        int num;
        queue<int> generator;
        for (int i = 0; i < 8; ++i)
        {
            cin >> num;
            generator.push(num);
        }

        int cnt = 1;
        while (generator.front() - cnt > 0)
        {
            generator.push(generator.front() - cnt);
            generator.pop();
            if (cnt == 5)
            {
                cnt = 1;
            }
            else
            {
                cnt += 1;
            }    
        }

        generator.push(0);
        generator.pop();

        cout << "#" << test_case;
        while (!generator.empty())
        {
            cout << " " << generator.front();
            generator.pop();
        }
        cout << "\n";
    }

    return 0;
}
