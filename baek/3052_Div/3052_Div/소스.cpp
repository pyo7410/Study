#include <iostream>
#include <set>
using namespace std;

int main()
{
	int i, num;
	set<int> s;

	for (i = 0; i < 10; ++i)
	{
		cin >> num;
		s.insert(num % 42);
	}
	
	printf("%d\n", s.size());
}