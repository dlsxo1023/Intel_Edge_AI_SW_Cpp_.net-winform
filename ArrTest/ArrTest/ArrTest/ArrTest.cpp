#include <iostream>

class ArrTest
{
private:
	int* arr;
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
	ArrTest& append(ArrTest& brr);
};
ArrTest& ArrTest::append(int size)  // size : total ? 추가로 배열을 추가하는 함수 
{
	int *arr1 = new int[Len + size];  //확장된 메모리
	memcpy(arr1, arr, Len * sizeof(int));
	delete arr;
	arr = arr1; 
	Len += size;
	return *this;
}
ArrTest& ArrTest::append(ArrTest& brr) // size : total
{
	int* arr1 = new int[Len + brr.length()];
	memcpy(arr1, arr, Len * sizeof(int));
	memcpy(arr1 + Len, brr.arr, brr.length() * sizeof(int));
	delete arr;
	arr = arr1;
	Len += brr.length();
	return *this;
}
int main()
{
	int a1[] = { 11, 22, 33, 44, 55 };
	ArrTest arr(7);
	
	for (int i = 0; i < 5; i++)            arr[i] = a1[i];
	for (int i = 0; i < arr.length(); i++) printf("ArrTest[%d] = %d\n",i, arr[i]);
	
	int a2[] = { 21, 22, 23, 24, 25 };
	ArrTest brr(7);
	for (int i = 0; i < 5; i++)    brr[i] = a2[i];
	
	int n = arr.length();
	printf("배열 확장 %d --> %d\n",n , arr.append(brr).length());
	
	for (int i = 0; i < arr.length(); i++) printf("ArrTest[%d] = %d\n", i, arr[i]);


}

