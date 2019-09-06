/*
1. 같은 수가 들어갔을 경우도 생각해야한다!
(e. g. 10 10 10 => 10 등등)
2. 20 20 10 같은 경우는 end값이 중간값이 된다!
3. set은 map과 달리 key만 존재하고 자동 정렬이 된다
(set은 일종의 tree이다!)
4. set은 작은 수 에서 큰 수로 정렬이 됨을 주의하라!
5. 이 문제에서 set은 자동으로 중복을 삭제하기 때문에
   적합하지가 않다..... 나무만 보지말고 숲을보자 ㅜ
   적절한 STL사용방법 숙지 필요

// set을 사용한 엄청난 오답....
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