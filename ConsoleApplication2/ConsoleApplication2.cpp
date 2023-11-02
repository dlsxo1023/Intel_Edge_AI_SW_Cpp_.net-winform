// ConsoleApplication2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "point.h"
#define MIN(x, y)  (((x) > (y)) ? (y) : (x))
#define MAX(x, y)  (((x) < (y)) ? (y) : (x))

void printp(point p)
{
    printf("point(%d, %d)\n",p.x, p.y);
}

void swap_v(int a, int b)   // Call-by-value
{
    int t(a);
    printf("[swap]초기값 a = %d  b = %d\n", a, b);
    a = b; b = t;
    printf("[swap]결과값 a = %d  b = %d\n", a, b);
}

void swap_p(int *a, int *b)   // Call-by-pointer
{
    int t(*a);
    printf("[swap]초기값 a = %d  b = %d\n", *a, *b);
    *a = *b; *b = t;
    printf("[swap]결과값 a = %d  b = %d\n", *a, *b);
}

void swap_r(int &a, int &b)   // Call-by-Reference (using ref. variables) 
{
    int t(a);
    printf("[swap_r]초기값 a = %d  b = %d\n", a, b);
    a = b; b = t;
    printf("[swap_r]결과값 a = %d  b = %d\n", a, b);
}

int main()
{
    point arr[3];  //객체 배열  : 3개의 point 클래스 객체가 default 초기화 됨. 
    arr[0].SetP(10, 10); printp(arr[0]);
    arr[1].SetP(20, 30); printp(arr[1]);
    arr[2].SetP(40, 60); printp(arr[2]);
    printf("Class point 객체 크기 : %d\n", sizeof(arr)); // 객체의 크기는 맴버 변수의 크기에 결정 // 객체 배열의 크기는 X[n]

    point* parr[3]; // point 객체 포인터(*) 배열 : 객체화 되어 있지 않음
    printf("point 객체 포인터 배열 크기 : %d\n", sizeof(parr));
    parr[0] = new point(10, 10); printp(*parr[0]);
    parr[1] = new point(20, 30); printp(*parr[1]);
    parr[2] = new point(40, 50); printp(*parr[2]);

    //point p1, p2(10, 10), p3(20, 30), p4;
    //p4 = p3;
    //double d = p1.Dist(p2);
    //double d1 = p2.Dist(p3);
    //double d2 = p1.Dist(p2, p3);
    //printp(p1); printp(p2); printp(p3); printp(p4);
    //printf("점간의 거리 계산 : \nd(p1, p2) = %.2f d1(p2, p3) = %.2f d2(p2, p3) = %.2f\n", d, d1, d2);
    //printf("Hello World!\n");
    
    
    //Rect r(p2, p3);
    //printf("두 점 \n");
    //printp(p2);
    //printp(p3);
    //printf("에 의해 정의된 사각형의 꼭지점의 좌표는\n");
    //printp(r.GetLL());
    //printp(r.GetLR());
    //printp(r.GetUL());
    //printp(r.GetUR());

    //Reference 변수 테스트
    //int a(10), b(20);  //a = 10; b = 20;
    //printf("초기값 a = %d  b = %d\n", a, b);
    //swap_r(a, b);
    //printf("결과값 a = %d  b = %d\n", a, b); // 이니셜라이져로 변수 초기화 하고 그 밑에 변수 값 바꿀시 고전적으로 대입

    //int n = 1234, n1 = 1000;
    //int& m = n;  //레퍼런스 변수 선언과 동시에 초기화 과정 필수
    //printf("[레퍼런스 변수 테스트] n = %d, m = %d\n", n, m);
    //
    //m = 5678;
    //printf("[레퍼런스 변수 테스트] n = %d, m = %d\n", n, m);
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
