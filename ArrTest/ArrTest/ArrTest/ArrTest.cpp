#include <iostream>

class ArrTest
{
private:
	int *arr;
	int Len;
public:
	ArrTest(int size) : Len(size) 
	{
		arr = new int[size];
	}
	~ArrTest()
	{
		delete arr;
	}
	int length()
	{
		return Len;
	}
	int& operator[](int idx) // calling sequence : arr[n]
	{
		if (idx < 0 || idx > Len - 1)
		{
			std::cout << "Out of bound\n"; exit(1);
		}
		//return *(arr + idx);
		return arr[idx];
	}
	ArrTest& append(int size);
};
ArrTest& ArrTest::append(int size)
{

}

int main()
{
	int a1[] = { 11, 22, 33, 44, 55 };
	ArrTest arr(7);
	for (int i = 0; i < 5; i++)
		arr[i] = a1[i];
	for (int i = 0; i < arr.length(); i++)
		printf("ArrTest[%d] = %d\n",i, arr[i]);
	int a2[] = { 21, 22, 23, 24, 25 };
}

