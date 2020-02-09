#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s, temp, temp2, result;
	int a, b, sum;
	int i = 0;

	cin >> s;

	if (s.size() < 2)
	{
		s = "0" + s;
	}

	result = s;

	while (1)
	{
		if (result.size() < 2)
		{
			result = "0" + result;
		}
		
		temp = result[0];
		temp2 = result[1];
		
		a = stoi(temp, nullptr, 10);
		b = stoi(temp2, nullptr, 10);
		
		sum = a + b;
		
		result = to_string(b);
		temp = to_string(sum);

		if (temp.size() == 2)
		{
			temp = temp[1];
		}

		result.append(temp);

		++i;

		if (result == s)
		{
			break;
		}
	}
	printf("%d\n", i);
}