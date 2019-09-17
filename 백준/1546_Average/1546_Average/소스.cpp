#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int max, num, i;
	int count = 0;
	long avg = 0;
	vector<int> vec;

	scanf("%d", &num);

	vec.assign(num, 0);

	for (i = 0; i < num; ++i)
	{
		scanf("%d", &vec[i]);
		if (vec[i] > 0)
		{
			count++;
		}
	}

	max = vec[0];

	for (i = 1; i < num; ++i)
	{
		if (max < vec[i])
		{
			max = vec[i];
		}
	}
	
	for (i = 0; i < num; ++i)
	{
		if (vec[i] > 0)
		{
			avg += vec[i] / max * 100;
			cout << avg <<"?" << endl;
		}
	}

	avg = avg / (long)num;

	printf("%.2f\n", avg);
}