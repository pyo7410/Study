#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int A_idx = A.size() - 1;
    int B_idx = A_idx;

    // 어차피 질 패라면
    // 오름차순 이기에 나머지 수들도 전부
    // 지는 패이고 어차피 질 현재패가 그나마 가장 큰 수이므로
    // A에서 이길 수 있는 패를 끝까지 찾아보고
    // 찾게 되면 A를 찾은만큼 패들도 졌다는 의미이므로
    // 뒤에있는 패들을 버리면 된다.
    while (A_idx >= 0)
    {
        int a = A[A_idx];
        int b = B[B_idx];

        if (b > a)
        {
            B_idx--;
            answer++;
        }
        A_idx--;
    }

    return answer;   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    vector<int> B(m);

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> B[i];
    }

    cout << solution(A, B) << "\n";

    return 0;
}