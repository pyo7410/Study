/*#include <iostream>
#include <string>
using namespace std;

class WhatDay {
private:
	int month, day;

public :
	WhatDay(int m = 1, int d = 1) : month(m), day(d) { }
	string day(int m, int d) {
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)

	}
};

int main()
{
	int m, d;

	cin >> m >> d;

	WhatDay w(m, d);

	return 0;
}*/
#include <iostream>
using namespace std;

class A
{
public:
	void f() { cout << "A::f()" << endl; }
	virtual void g() { cout << "A::g()" << endl; }
	~A() { cout << "~A()" << endl; }
};
class B : public A
{
public:
	void f() { cout << "B::f()" << endl; }
	virtual void g() { cout << "B::g()" << endl; }
	~B() { cout << "~B()" << endl; }
};
int main(void)
{
	B *q = new B();
	A *p = q;
	p->f();
	p->g();
	q->f();
	q->g();
	delete p;
	delete q;
}