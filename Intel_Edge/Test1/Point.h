#pragma once
//#include <corecrt_math.h>
//extern double sqrt(double);
#include <iostream>

#define ABS(x)  (((x) < 0) ? ((-x)) : (x)) 

template <typename T>
class Point
{
private:
	T x; T y;

public:
	Point(T x1 = 0, T y1 = 0) : x(x1), y(y1) {}

	T &X() { return x; }; // 프라이빗 접근자 맴버 변수 에서 퍼블릭 접근자로 바꾸는 함수
	T &Y() { return y; }; //프라이빗 접근자 맴버 변수 에서 퍼블릭 접근자로 바꾸는 함수
	Point<T>& SetP(Point<T>& P);   // Self-Reference
	Point<T>& SetP(T x, T y);
	double Dist(Point<T>& p);  // Distance
	void viewP(const char *s = NULL); // View Current Point
	Point<T>& MoveP(T xo, T yo);
	Point<T>& operator+(Point<T> p);
	Point<T>& operator++();  //선행 연산자
	Point<T>& operator++(int);  //후행 연산자
	double operator*(Point<T> p); // 두 점이 이루는 사각형의 넓이  
};

//class Point3D : public Point    // 클래스 상속 정의
//{
//private:	
//	int z;
//public:
//	Point3D(int x = 0 , int y = 0, int z = 0) : Point(x , y), z(z)
//	{}
//	Point3D& SetP(Point3D p);
//	double Dist3D(Point3D p)    // Distance 3D
//	{
//		int w = X() - p.X();
//		int h = Y() - p.Y(); // 상위클래스 protected 접근 가능
//		int d = z - p.z; //하위클래스 내부이기에 프라이빗 int z 접근가능
//		return sqrt((w * w) + (h * h) + (d * d));
//	}
//};

