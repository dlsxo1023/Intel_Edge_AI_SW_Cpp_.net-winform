#pragma once
#include <iostream>
#define ABS(x)  (((x) < 0) ? ((-x)) : (x)) 
class Point
{
private:
	

public:
	int x; int y;
	Point(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}

	double Dist(Point p);  // Distance
	void Show(const char* s = NULL); // View Current Point , s : Point name
	Point& operator+(Point p);
};

class Rect
{
private:

public:
	Point p1, p2;
	
	Rect(Point pp1 , Point pp2) : p1(PP1), p2(pp2) {}
	Rect(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) // 함수의 오버로드
	{
		p1 = Point(x1, y1);
		P2 = Point(x2, y2);
	}  
};