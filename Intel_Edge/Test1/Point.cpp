#include "Point.h"

using namespace std;

template <typename T>
double Point<T>::Dist(Point<T>& p)
{	
	T w =  x - p. x;
	T h =  y - p. y;
	return sqrt(w * w + h * h);
}
template <typename T>
Point<T>& Point<T>::SetP(Point<T>& p)
{
	T x = p.x; T y = p. y; 
	return *this;
}
template <typename T>
Point<T>& Point<T>::SetP(T x, T y)
{
	this->x = x; this-> y =  y; 
	return *this;
}
template <typename T>
void Point<T>::viewP(const char *s)  // 디폴트 값은 프로토타입에만 지정 
{
	//printf("%s(%d, %d)\n", s, x, y);
	cout << s << "(" << x << "," << y << ")\n";
}
template <typename T>
Point<T>& Point<T>::MoveP(T xo, T yo)
{
	this -> x += xo; this-> y += yo;
	return *this;
}
template <typename T>
Point<T>& Point<T>::operator+(Point<T> p)  // 두 점 Cur p와 p의 + 연산결과를 (새로운 point로) 반환
{
	Point<T>*p1 = new Point<T>(x + p.x,  y + p.y);  // new(메모리 동적할당 Heap영역 새로운 공간 생성) 는 포인터로 받아야함
	return *p1;
}
template <typename T>
Point<T>& Point<T>::operator++()  //객체 선행 연산자 오버로딩
{
	++x; ++y;
	return *this;
}
template <typename T>
Point<T>& Point<T>::operator++(int) //객체 후행 연산자 오버로딩
{
	Point* p1 = new Point<T>(x++, y++);
	return *p1;
}
template <typename T>
double Point<T>::operator*(Point<T> p)
{
	T w = x - p.x;
	T h = y - p.y;
	T area = w * h; 
	return ABS(area);
}

//Point3D& Point3D::SetP(Point3D p)
//{
//	X() = p.X(); Y() = p.Y(); z = p.z;
//	return *this;
//}
