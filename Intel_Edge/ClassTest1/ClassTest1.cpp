#include <iostream>

class AAA
{
public:
	int a1;
	int a2;
	int a3;
	AAA() { printf("A\n"); }
	~AAA() { printf("~A\n"); }
	void name() { printf("class name = AAA\n"); }
};
class BBB
{
public:
	int b1;
	int b2;
	int b3;
	BBB() { printf("B\n"); }
	~BBB() { printf("~B\n"); }
	void name() { printf("class name = BBB\n"); }
};

void func()
{
	printf("function start...\n");
	AAA *a = new AAA();
	BBB *b = new BBB();
	printf("function end.\n");
	delete b;
	delete a;
}
int main()
{
	printf("program start...\n");
	AAA a;
	BBB b;
	func();
	printf("program end.\n");
	//a.name();
	//b.name();
}

