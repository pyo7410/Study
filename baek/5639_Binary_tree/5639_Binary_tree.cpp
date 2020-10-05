#include <iostream>
#include <algorithm>
using namespace std;

int adj[10001];

void printTree(int left_node, int right_node)
{
    // 왼쪽 노드의 인덱스가 오른쪽 노드의 인덱스보다 크다면
    if (left_node > right_node)
    {
        return;
    }
    
    int root = adj[left_node];
    int last = right_node;

    // 오른쪽 노드가 root의 값보다 크다면
    // adj 배열에서 root보다 작은 값이 나올때 까지
    // last를 줄여준다.

    // 입력이 전위 순회 이므로
    // adj의 앞 부분에는 root보다 작은 값이
    // 뒤 부분에는 root보다 큰 값이 들어가게 된다.
    while (adj[last] > root)
    {
        last--;
    }

    // 왼쪽 노드가 된다.
    // left_node 위치가 현재 root이므로 +1
    printTree(left_node + 1, last);

    // 오른쪽 노드가 된다.
    // last의 위치가 adj에서 root보다 작은 마지막 위치이므로 +1
    printTree(last + 1, right_node);

    // 현재 root를 출력
    printf("%d\n", root);
}

int main()
{
    int n = 0;
    int v;

    while (scanf("%d", &v) != -1)
    {
        adj[n++] = v;
    }

    // 0 ~ n - 1, 총 n 개의 node를 출력
    printTree(0, n - 1);

    return 0;
}