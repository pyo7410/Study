#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, i;
	int min, max;
	vector<int> vec;

	cin >> n;

	vec.assign(n, 0);

	for (i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	min = vec[0];
	max = vec[0];

	for (i = 1; i < n; ++i)
	{
		if (min > vec[i])
		{
			min = vec[i];
		}
		if (max < vec[i])
		{
			max = vec[i];
		}
	}
	printf("%d %d\n", min, max);
}