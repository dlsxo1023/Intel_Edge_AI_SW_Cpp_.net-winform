#include <iostream>

template <typename T>
class ArrTest
{
private:
	T* arr;
	int Len;  // 배열 요소의 수 
public:
	ArrTest(int size) : Len(size)
	{
		arr = new T[size];
	}
	~ArrTest()
	{
		delete arr;
	}
	int length()
	{
		return Len;
	}
	T& operator[](int idx) // calling sequence : arr[n]
	{
		if (idx < 0 || idx > Len - 1)
		{
			std::cout << "Out of bound\n"; exit(1);
		}
		//return *(arr + idx);
		return arr[idx];
	}
	void Show()
	{
		int i;
		printf("{ ");
		for (i = 0; i < Len - 1; i++) 
			std::cout << arr[i] << ", "; std::cout << arr[i];
		printf(" }\n");
	}
	ArrTest& append(int size)
	{
		T* arr1 = new T[Len + size];  //확장된 메모리
		memcpy(arr1, arr, Len * sizeof(T));
		delete arr;
		arr = arr1;
		Len += size;
		return *this;
	}
	ArrTest& append(ArrTest& brr)
	{
		T* arr1 = new T[Len + brr.length()];
		memcpy(arr1, arr, Len * sizeof(T));
		memcpy(arr1 + Len, brr.arr, brr.length() * sizeof(T));
		delete arr;
		arr = arr1;
		Len += brr.length();
		return *this;
	}
};
//ArrTest& ArrTest::append(int size)  // size : total ? 추가로 배열을 추가하는 함수 
//{
//	int *arr1 = new int[Len + size];  //확장된 메모리
//	memcpy(arr1, arr, Len * sizeof(int));
//	delete arr;
//	arr = arr1; 
//	Len += size;
//	return *this;
//}
//ArrTest& ArrTest::append(ArrTest& brr) // size : total
//{
//	int* arr1 = new int[Len + brr.length()];
//	memcpy(arr1, arr, Len * sizeof(int));
//	memcpy(arr1 + Len, brr.arr, brr.length() * sizeof(int));
//	delete arr;
//	arr = arr1;
//	Len += brr.length();
//	return *this;
//}
//void ArrTest::Show()
//{
//	int i;
//	printf("{");
//	for (i = 0; i < Len - 1; i++) printf(" %d, ", arr[i]); printf(" %d ", arr[i]);
//	printf("}\n");
//}

class Func
{
private:

public:
	int operator()(int a, int b)  // 함수의 오버로딩 가능 ex) 같은 방식으로 다른 타입 또는 다른 연산도 가능
	{
		return a * b;
	}
	double operator()(double a, double b)
	{
		return a * b;
	}
	ArrTest<int>& operator()(ArrTest<int>& b1, ArrTest<int>& b2)
	{
		return  b1.append(b2);
	}
	ArrTest<double>& operator()(ArrTest<double>& b1, ArrTest<double>& b2)
	{
		return  b1.append(b2);
	}
};

int main()
{
	double a1[] = { 11.1, 22.1, 33.1, 44.1, 55.1 };
	ArrTest<double> arr(5);
	for (int i = 0; i < 5; i++)            arr[i] = a1[i];
	//for (int i = 0; i < arr.length(); i++) printf("ArrTest[%d] = %d\n",i, arr[i]);
	//
	double a2[] = { 21.1, 22.1, 23.1, 24.1, 25.1 };
	ArrTest<double> brr(5);
	for (int i = 0; i < 5; i++)    brr[i] = a2[i];
	//
	//int n = arr.length();
	//printf("배열 확장 %d --> %d\n",n , arr.append(brr).length());
	//
	//for (int i = 0; i < arr.length(); i++) printf("ArrTest[%d] = %d\n", i, arr[i]);

	Func mul;
	std::cout << mul(2, 3)<<"\n";
	std::cout << mul(2.3, 3.6)<<"\n";
	mul(arr, brr).Show();
}

