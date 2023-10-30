// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#define SQUARE(x) ((x)*(x)) // 매크로 함수 // 제곱
#define ABS(x)  (x < 0) ? -(x) : (x) // 매크로 함수 // 삼항 연산자 // 모든 인수에 반드시 괄호 //절대값
// 전역변수/데이터 타잎 선언

/*typedef struct Point   // 구조체 선언
{
    int x;
    int y;
}point2D;
double Dist(point2D p1, point2D p2);*/

class point   //class 선언
{
public:
    int x;
    int y;
    //point() {}    // null argument 허용
    point(int x1 = 0, int y1 = 0) // 생성자에 derault 값 설정 하여  null argument도 사용 가능하게 만듬
    {                             //   오버로딩도 가능 함 
        x = x1; y = y1;
    }
    double Dist(point p);  //맴버 함수
    double area(point p);  //맴버 함수 
};
double point::Dist(point p) //맴버 함수 두 점간의 거리
{
    int w = (x - p.x);
    int h = (y - p.y);
    double d = sqrt(w * w + h * h);
    return d;
}
double point::area(point p) // 맴버 함수 두 점으로 만든 사각형의 넓이
{
    int w = ABS(x - p.x);
    int h = ABS(y - p.y);
    double a = w * h;
    return a;
}
//double point::Dist(point p)
//{
//    int w = (x - p.x);
//    int h = (y - p.y);
//    double d = sqrt(w * w + h * h);   //sqrt = 루트 
//    return d;
//}
int main()
{
    printf("안녕하세요. C++ 의 세계에 오신것을 환영합니다!\n\n"); 
    
    printf("2의 제곱 : %d\n", SQUARE(2));
    printf("5의 제곱 : %d\n", SQUARE(5));
    int x = -2;
    printf("%d의 절대값 : %d\n",x , ABS(x));
    printf("-4의 절대값 : %d\n", ABS(-4));

    point p1(10, 10), p2(20, 30), p3;
   /* p1.x = 10; p1.y = 10;
    p2.x = 20; p2.y = 30;*/

    double d = p1.Dist(p2);
    printf("두 점 p1(%d, %d) p2(%d, %d) 점의 거리는 : %.2f 입니다.\n", p1.x, p1.y, p2.x, p2.y, d);

    double a = p1.area(p2);
    printf("두 점 p1(%d, %d) p2(%d, %d) 면적은 : %.2f 입니다.\n",p1.x, p1.y, p2.x, p2.y, a);

    printf("null argument p3는 p(%d, %d)로 설정되었습니다.",p3.x, p3.y);
}
   

//double Dist(point2D p1, point2D p2) //두 점간의 거리
//{
//    int w = ABS(p1.x - p2.x);
//    int h = ABS(p1.y - p2.y);
//    int w1 = w * w;
//    int h1 = h * h;
//    double d = sqrt(w1 + h1);   //sqrt = 루트 
//    return d;
//}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
