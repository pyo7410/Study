#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int nums_size = nums.size();
    unordered_set<int> s;

    for (int i = 0; i < nums_size; ++i)
    {
        s.insert(nums[i]);
    }

    // s에 들어간 폰켓몬이 전체사이즈 / 2 보다 크더라도
    // 전체사이즈 / 2 만 뽑을 수 있다.
    if (s.size() > nums_size / 2)
    {
        return nums_size / 2;
    }

    // 전체사이즈 / 2 보다 작다면
    // s에 들어간 폰켓몬의 수가 정답이다.
    return s.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    cout << solution(nums) << "\n";

    return 0;
}