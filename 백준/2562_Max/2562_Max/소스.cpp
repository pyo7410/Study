#include <iostream>
#include <vector>
using namespace std;

/*
index�� �ʱ�ȭ ���ϸ� ������ �߻�
��, max���� ù��° �����ϰ�쵵 ó���� ���־�� �Ѵ�!
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