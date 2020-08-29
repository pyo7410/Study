#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool row[102][102], col[102][102];

bool isBuildRow(int x, int y) {
	return col[x][y - 1] || col[x + 1][y - 1] || (row[x - 1][y] && row[x + 1][y]);
}

bool isBuildCol(int x, int y) {
	return y == 1 || col[x][y - 1] || row[x - 1][y] || row[x][y];
}

bool isRemove(int n) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (row[i][j] && !isBuildRow(i, j))
				return false;
			if (col[i][j] && !isBuildCol( i, j))
				return false;
		}
	return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	for (int i = 1; i <= 101; i++)
		for (int j = 1; j <= 101; j++)
			row[i][j] = col[i][j] = 0;

	for (int i = 0; i < build_frame.size(); i++) {
		int x = build_frame[i][0], y = build_frame[i][1], a = build_frame[i][2], b = build_frame[i][3];
		x++, y++;
		if (b == 0) { // »èÁ¦
			if (a == 0) { // ±âµÕ
				col[x][y] = 0;
				if (isRemove(n + 1))
					continue;
				col[x][y] = 1;
			}
			else {
				row[x][y] = 0;
				if (isRemove(n + 1))
					continue;
				row[x][y] = 1;
			}
		}
		else { // ¼³Ä¡
			if (a == 0) { // ±âµÕ
				if (isBuildCol( x, y))
					col[x][y] = 1;
			}
			else { // º¸
				if (isBuildRow( x, y))
					row[x][y] = 1;
			}
		}
	}

	vector<vector<int>> answer;
	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= n + 1; j++) {
			if (row[i][j])
				answer.push_back({ i - 1, j - 1, 1 });
			if (col[i][j])
				answer.push_back({ i - 1, j - 1, 0 });
		}
	sort(answer.begin(), answer.end());
	return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> build_frame(m, vector<int>(4));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin >> build_frame[i][j];
        }
    }

    vector<vector<int>> s = solution(n, build_frame);
    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
