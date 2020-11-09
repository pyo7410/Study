#include <iostream>
#include <string>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
char moveType[] = {'U', 'D', 'R', 'L'};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    cin.ignore();
    string plan;
    getline(cin, plan);

    int x = 1, y = 1;

    for (int i = 0; i < plan.length(); ++i)
    {
        int nx, ny;
        for (int j = 0; j < 4; ++j)
        {
            if (moveType[j] == plan[i])
            {
                nx = x + dx[j];
                ny = y + dy[j];
            }
        }

        if (nx >= 1 && ny >= 1 && nx <= n && ny <= n)
        {
            x = nx;
            y = ny;
        }
    }

    cout << y << ' ' << x << "\n";

    return 0;
}