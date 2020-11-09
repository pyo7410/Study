#include <iostream>
#include <string>
using namespace std;

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string input;
    cin >> input;

    int y = input[1] - '0';
    int x = input[0] - 'a' + 1;

    int answer = 0;

    for (int i = 0; i < 8; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 1 && ny >= 1 && nx <= 8 && ny <= 8)
        {
            answer++;
        }
    }

    cout << answer << "\n";

    return 0;
}