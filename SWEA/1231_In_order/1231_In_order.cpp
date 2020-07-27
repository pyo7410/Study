#include <iostream>
#include <cstring>
using namespace std;

char tree[101];

void inorder(int node)
{
    int next_node = node * 2;
    if (tree[node] != 0)
    {
        inorder(next_node);
        cout << tree[node];
        inorder(next_node + 1);
    }
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

        memset(tree, 0, sizeof(tree));

        int num, child_node;
        char alphabet;
        for (int i = 1; i <= n; ++i)
        {
            cin >> num >> alphabet;
            tree[num] = alphabet;

            if (num * 2 <= n)
            {
                cin >> child_node;
            }
            if (num * 2 < n)
            {
                cin >> child_node;
            }
        }

        cout << "#" << test_case << " ";
        inorder(1);
        cout << "\n";
    }
    
    return 0;
}
