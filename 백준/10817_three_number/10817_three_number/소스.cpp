/*
1. ���� ���� ���� ��쵵 �����ؾ��Ѵ�!
(e. g. 10 10 10 => 10 ���)
2. 20 20 10 ���� ���� end���� �߰����� �ȴ�!
3. set�� map�� �޸� key�� �����ϰ� �ڵ� ������ �ȴ�
(set�� ������ tree�̴�!)
4. set�� ���� �� ���� ū ���� ������ ���� �����϶�!
5. �� �������� set�� �ڵ����� �ߺ��� �����ϱ� ������
   ���������� �ʴ�..... ������ �������� �������� ��
   ������ STL����� ���� �ʿ�

// set�� ����� ��û�� ����....
#include <iostream>
#include <set>
using namespace std;

int main()
{
	int a, b, c;
	int mid, count = 0;
	set<int> s;
	set<int>::iterator it;

	cin >> a >> b >> c;

	s.insert(a);
	s.insert(b);
	s.insert(c);

	if (s.size() < 3)
	{
		it = s.end();
		--it;
		mid = *it;
	}

	else
	{
		it = s.begin();
		++it;
		mid = *it;
	}

	cout << mid << endl;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	vector<int> vec;

	cin >> a >> b >> c;

	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);

	sort(vec.begin(), vec.end());

	cout << vec[1] << endl;
}