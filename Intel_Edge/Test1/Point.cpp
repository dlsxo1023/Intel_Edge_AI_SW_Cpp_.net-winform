#include "Point.h"
double Point::Dist(Point p)
{	
	int w = x - p.x;
	int h = y - p.y;
	return sqrt(w * w + h * h);
}
Point& Point::SetP(Point p)
{
	x = p.x; y = p.y; 
	return *this;
}
Point& Point::SetP(int x, int y)
{
	this->x = x; this->y = y; 
	return *this;
}
void Point::viewP(const char *s)  // 디폴트 값은 프로토타입에만 지정 
{
	printf("%s(%d, %d)\n", s, x, y);
}
Point& Point::MoveP(int xo, int yo)
{
	this -> x += xo; this-> y += yo;
	return *this;
}
Point& Point::operator+(Point p)  // 두 점 Cur p와 p의 + 연산결과를 (새로운 point로) 반환
{
	Point *p1 = new Point(x + p.x, y + p.y);  // new(메모리 동적할당 Heap영역 새로운 공간 생성) 는 포인터로 받아야함
	return *p1;
}
Point& Point::operator++()  //객체 선행 연산자 오버로딩
{
	++x; ++y;
	return *this;
}
Point& Point::operator++(int) //객체 후행 연산자 오버로딩
{
	Point* p1 = new Point(x++, y++);
	return *p1;
}
double Point::operator*(Point p)
{
	double w = x - p.x;
	double h = y - p.y;
	double area = w * h; 
	return ABS(area);
}

Point3D& Point3D::SetP(Point3D p)
{
	X() = p.X(); Y() = p.Y(); z = p.z;
	return *this;
}
