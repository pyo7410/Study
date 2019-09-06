#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a, b, c, result, count;
	int i, j;
	string temp, temp2;

	scanf("%d %d %d", &a, &b, &c);

	result = a * b * c;

	temp = to_string(result);

	for (i = 0; i <= 9; ++i)
	{
		count = 0;
		temp2 = to_string(i);
		for (j = 0; j < temp.size(); ++j)
		{
			if (temp2[0] == temp[j])
			{
				count++;
			}
		}
		printf("%d\n", count);		
	}
}