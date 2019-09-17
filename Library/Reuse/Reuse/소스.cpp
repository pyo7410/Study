#include <iostream>
#include <vector>
using namespace std;

void max(vector<int>& vec, int num, int &max)
{
	int i;
	max = vec[0];

	for (i = 1; i < num; ++i)
	{
		if (max < vec[i])
		{
			max = vec[i];
		}
	}
}

void input_vec(vector<int>& vec, int num)
{
	int i;

	for (i = 0; i < num; ++i)
	{
		scanf("%d", &vec[i]);
	}
}