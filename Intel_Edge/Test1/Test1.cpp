#include <iostream>
#include "Point.h"
int main()
{
	Point p1(10, 10), p2, p3;
	p1.viewP("p1"); p2.viewP(); p3.viewP();
	Point p4 = p3, p5(p2);
	
	p2.SetP(Point(20, 30)).viewP("p2");
	p3.SetP(40, 70).viewP("p3");
	printf("두 점으로 정의되는 사각형의 넓이는 : %.2f 입니다\n", p2 * p3);

	//printf("Point Move Test.....\n");
	//p1.MoveP(1, 1).viewP("P1_1_1");
	//p1.MoveP(1, 1).viewP("P1_1_1"); 
	//p1.MoveP(1, 1).viewP("P1_1_1"); 
	//p1.MoveP(1, 1).viewP("P1_1_1"); 
	//printf("Point print Test..p1(%d, %d).\n\n", p1.X(), p1.Y());   
	//p1.X() = 10; p1.Y() = 10;
	//printf("Point Ref.Access print Test..."); p1.viewP("p1");
	Point p6 = p1 + p2;
	double p7 = p1 * p2;
	double p8 = p5 * p5;
	printf("Point [Operator+] Test..."); p6.viewP("_p6");
	printf("Point [Operator++] 후행연산 Test..."); p6++.viewP("_p6");
	printf("Point [Operator++] 선행연산 Test..."); (++p6).viewP("_p6");
	printf("Point [ Operator*] Test...%.2f\n", p7); 
	printf("Point [ Operator*] Test...%.2f\n", p8);

	

	//Point3D pp0, pp1(10, 20, 30);
	//double d3 = pp0.Dist3D(pp1);
	//double d2 = pp0.Dist(Point(10, 20));  // 하위 클래스인데 상위 클래스 상속을 통해서 거리계산이 가능하다 
	//printf("pp0(0, 0, 0) 과 pp1 (10, 20, 30)의 거리는 %f\n", d3);
	//printf("pp0(0, 0, 0) 과 p1 (10, 20) 의 거리는 %f\n", d2);
	//p1.x = 10;
	//p1.Y = 20;
	//p1.MoveP(50, 50).viewP("p1_O");
	//p1.viewP("p1"); p2.viewP("p2"); p3.viewP("p3");
}

