#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int i, num;
	bool asc = false, des = false;

	vector<int> vec(8);

	for (i = 0; i < 8; ++i)
	{
		cin >> vec[i];
	}

	num = vec[0];

	for (i = 1; i < 8; ++i)
	{
		if (num > vec[i])
		{
			des = true;
		}
		if (num < vec[i])
		{
			asc = true;
		}
		num = vec[i];
	}

	if (des && asc)
	{
		printf("mixed\n");
	}

	else if (asc)
	{
		printf("ascending\n");
	}

	else if (des)
	{
		printf("descending\n");
	}
}