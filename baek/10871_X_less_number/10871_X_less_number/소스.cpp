#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int size, num, i, temp;
	vector<int> resultVec;
	vector<int>::iterator iter;

	scanf("%d %d", &size, &num);

	for (i = 0; i < size; ++i)
	{
		scanf("%d", &temp);
		
		if (temp < num)
		{
			resultVec.push_back(temp);
		}
	}

	for (iter = resultVec.begin(); iter != resultVec.end(); ++iter)
	{
		printf("%d ", *iter);
	}
	printf("\n");
}