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
	int operator[](int idx) // calling sequence : arr[n]
	{
		return *(arr + idx);
		return arr[idx];
	}
};

int main()
{
   
}

