#include <iostream>
using namespace std;

/*
반복문 문제인데(While문) 끝이 주어지지않았다면
EOF를 처리할 수 있는지 알아보기 위한 문제이다!
각 언어마다 EOF처리 법이 다르므로 잘 조사할것!
*/

int main()
{
	int a, b;

	while (1)
	{
		cin >> a >> b;

		if (cin.eof())
		{
			break;
		}

		printf("%d\n", a + b);
	}
}