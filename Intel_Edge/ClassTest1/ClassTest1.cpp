#include <iostream>

class AAA
{
private:
	int a1 ;
protected:
	int a2 ;
public:
	int a3;
	AAA() { printf("A\n"); }
	~AAA() { printf("~A\n"); }
	
	virtual void name() { printf("class name = AAA\n"); }
};
class BBB : private AAA
{
public:
	int b1;
	int b2;
	int b3;
	BBB() { printf("B\n"); a2 = 20; a3 = 10; }
	~BBB() { printf("~B\n"); }

	//void Test() { printf("a1 = %d a2 = %d, a3 = %d\n",a2, a3); }
	void name() { printf("class name = BBB\n"); }
};
class C    // 순수 가상 함수가 있는 클래스를 곧 추상 클래스라고 함 // 추상 클래스 
{
public:
	C() { printf("_C_\n"); }
	virtual void func() = 0  // NULL 함수 껍대기모양만 함수이고 실제로는 함수가 아니다 // 순수 가상함수
	{}
};
class C1 : public C
{
public:
	C1() { printf("_C1_\n");  }
	virtual void func()
	{
		printf("func_in_C1_\n");
	}
};
//void func()
//{
//	printf("function start...\n");
//	BBB* b = new BBB();
//	b->name();
//	//printf("a1 = %d a2 = %d a3 = %d\n", b->);
//
//	AAA* a = (AAA*)b;
//	a->name();  // ((AAA*)b)->name();  //캐스팅
//	printf("a3 = %d\n", ((AAA*)b)->a3);
//	delete b;
//	//delete a;
//	printf("function end.\n");
//}
//
//void func1()
//{
//	printf("function start...\n");
//	AAA *a = new AAA();
//	a->name();
//	
//	BBB *b = (BBB*)a;
//	b->name(); 
//	printf("b1 = %d\n", ((BBB*)a)->b1);
//	delete a;
//	
//	printf("function end.\n");
//}
int main()
{
	printf("program start...\n");
	//C c;
	C1 c1;
	c1.func();
	//AAA a;
	//BBB b;
	//b.Test();
	//func();
	//func1();
	printf("program end.\n");
	//a.name();
	//b.name();
}

