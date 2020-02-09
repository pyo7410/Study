#include <iostream>
using namespace std;

int main()
{
	int count, i, a, b;

	scanf("%d", &count);

	for (i = 1; i <= count; ++i)
	{
		scanf("%d", &a);
		scanf("%d", &b);

		printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
	}
}