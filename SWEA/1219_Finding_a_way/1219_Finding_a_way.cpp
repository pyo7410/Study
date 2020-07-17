#include <iostream>
#include <cstring>
using namespace std;

int arr[100][2];
int visited[100];

void dfs(int node)
{
    visited[node] = 1;
    
    if (node == 99)
    {
        return;
    }

    for (int i = 0; i < 2; ++i)
    {
        // 경로가 있고 한번도 방문 안했다면 dfs
        if (arr[node][i] && !visited[arr[node][i]])
        {
            dfs(arr[node][i]);
        }    
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    FILE* fp = freopen("C:\\Users\\pyo74\\Desktop\\git-project\\Study\\SWEA\\input_output\\1219_input.txt", "r", stdin);

    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        int n;
        cin >> n;

        int len;
        cin >> len;

        int start, end;
        for (int i = 0; i < len; ++i)
        {
            cin >> start >> end;
            
            if (arr[start][0] == 0)
            {
                arr[start][0] = end;
            }
            else
            {
                arr[start][1] = end;
            }
            
        }

        dfs(0);

        cout << "#" << test_case << " " << visited[99] << "\n";
    }
    
    return 0;
}
