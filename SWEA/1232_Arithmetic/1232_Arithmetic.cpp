#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

string tree[1001];
int left_child[1001];
int right_child[1001];

queue<string> q;
int n;

// 트리가 완전 이진트리가 아니다!!!!
// 즉 왼쪽 오른쪽 자식트리에 유의해야함을 주의하자!!

void postorder(int node)
{
    if (left_child[node] != 0)
    {
        postorder(left_child[node]);
    }
    if (right_child[node] != 0)
    {
        postorder(right_child[node]);
    }
    q.push(tree[node]);
}

int calc(queue<string> &q)
{
    stack<double> s;

    while (!q.empty())
    {
        string alpha = q.front();
        q.pop();

        if (alpha.compare("+") == 0 || alpha.compare("-") == 0 || alpha.compare("*") == 0 || alpha.compare("/") == 0)
        {
            double x, y;
            y = s.top();
            s.pop();

            x = s.top();
            s.pop();

            if (alpha == "+")
            {
                s.push(x + y);
            }
            else if (alpha == "-")
            {
                s.push(x - y);
            }
            else if (alpha == "*")
            {
                s.push(x * y);
            }
            else if (alpha == "/")
            {
                s.push(x / y);
            }
        }
        else
        {
            s.push(stod(alpha));
        }
    }

    int ans = s.top();
    s.pop();

    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    FILE* fp = freopen("C:\\Users\\pyo74\\Desktop\\git-project\\Study\\SWEA\\input_output\\1232_input.txt", "r", stdin);

    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        memset(left_child, 0, sizeof(left_child));
        memset(right_child, 0, sizeof(right_child));

        cin >> n;

        int num;
        string alphabet;

        for (int i = 1; i <= n; ++i)
        {
            cin >> num;
            cin >> tree[num];

            if (tree[num].compare("+") == 0 || tree[num].compare("-") == 0 || tree[num].compare("*") == 0 || tree[num].compare("/") == 0) 
            {
                cin >> left_child[num] >> right_child[num];
            }
        }

        postorder(1);
        cout << "#" << test_case << " " << calc(q) << "\n";
    }
    
    return 0;
}
