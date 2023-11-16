#include "Classes.h"
double Point::Dist(Point p)
{
	int w = x - p.x;
	int h = y - p.y;
	return sqrt(w * w + h * h);
}
void Point::Show(const char* s)  // 디폴트 값은 프로토타입에만 지정 
{
	printf("%s(%d, %d)\n", s, x, y);
}
void Point::ShowEX(const char* s)  // 디폴트 값은 프로토타입에만 지정 
{
	printf("%s(%d, %d)", s, x, y);
}
void Rect::Show(const char* s)  // Rect(p1(x1, y1), p2(x2, y2))
{
	printf("%s(", s);
	p1.ShowEX("p1");
	p2.SHowEX("p2");
	printf(")\n");
}
Point& Point::operator+(Point p)  // 두 점 Cur p와 p의 + 연산결과를 (새로운 point로) 반환
{
	Point* p1 = new Point(x + p.x, y + p.y);  // new(메모리 동적할당 Heap영역 새로운 공간 생성) 는 포인터로 받아야함
	return *p1;
}
