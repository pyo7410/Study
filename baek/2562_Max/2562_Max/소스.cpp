#include <iostream>
#include <vector>
using namespace std;

/*
index를 초기화 안하면 문제가 발생
즉, max값이 첫번째 원소일경우도 처리를 해주어야 한다!
*/

int main()
{
	int i, max;
	int index = 1;
	vector<int> vec(9);

	for (i = 0; i < 9; ++i)
	{
		cin >> vec[i];
	}

	max = vec[0];

	for (i = 1; i < 9; ++i)
	{
		if (max < vec[i])
		{
			max = vec[i];
			index = i + 1;
		}
	}

	printf("%d\n%d\n", max, index);
}