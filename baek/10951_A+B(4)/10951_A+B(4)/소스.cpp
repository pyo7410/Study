#include <iostream>
using namespace std;

/*
�ݺ��� �����ε�(While��) ���� �־������ʾҴٸ�
EOF�� ó���� �� �ִ��� �˾ƺ��� ���� �����̴�!
�� ���� EOFó�� ���� �ٸ��Ƿ� �� �����Ұ�!
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