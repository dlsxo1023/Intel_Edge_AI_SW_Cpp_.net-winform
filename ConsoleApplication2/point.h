#pragma once
#include <iostream>
#define MIN(x, y)  (((x) > (y)) ? (y) : (x))
#define MAX(x, y)  (((x) < (y)) ? (y) : (x))

class point
{
private:     //접근지시자 ( 외부 참조 불가)

public:  //접근지시자  (외부 참조 가능)
    int x, y, z;  //맴버 변수 선언. //객체의 좌표
    point(int x = 0, int y = 0) : x(x), y(y)  // 이니셜라이져
        //생성자 정의 //아무런 타입이 없는 함수//외부접근이 필요하기에 public 접근지시자 전에 미리 사용
        //함수적 특성을 가지고 있음(default, overload 등)
    {
        z = 0;//x = x1; y = y1; 
    }
    void SetP(int x1 = 0, int y1 = 0) { x = x1; y = y1; }
    double Dist(point p)   // 맴버 함수 // 두 점간의 거리 계산.  // 리턴값은 Double 타입으로 return
    {
        int w = x - p.x;
        int h = y - p.y;
        return sqrt(w * w + h * h);   //sqrt 명령어 자체가 double 타입임 // 따로 타입을 기입안해도 됨
    }
    double Dist(point p1, point p2)   // 맴버 함수 // 두 점(자신을 제외한) 거리 계산.  // 리턴값은 Double 타입으로 return
    {
        int w = p1.x - p2.x;
        int h = p1.y - p2.y;
        return sqrt(w * w + h * h);   //sqrt 명령어 자체가 double 타입임 // 따로 타입을 기입안해도 됨
    }
};

class Rect
{

    point p11, p22;  // 클래스 맴버 변수 선언
    //point LL, LR, UL, UR;
public:
    Rect(point p1, point p2) : p11(p1), p22(p2)    // 이니셜라이져
    {
        /* int xl = MIN(p1.x, p2.x);
         int xr = MAX(p1.x, p2.x);
         int yl = MIN(p1.y, p2.y);
         int yu = MAX(p1.y, p2.y);
         LL = point(xl, yl);
         LR = point(xr, yl);
         UL = point(xl, yu);
         UR = point(xr, yu);*/

    }
    point GetLL();
    point GetLR();
    point GetUL();
    point GetUR();
};
point Rect::GetLL()
{
    return point(MIN(p11.x, p22.x), MIN(p11.y, p22.y));
}
point Rect::GetLR()
{
    return point(MAX(p11.x, p22.x), MIN(p11.y, p22.y));
}
point Rect::GetUL()
{
    return  point(MIN(p11.x, p22.x), MAX(p11.y, p22.y));
}
point Rect::GetUR()
{
    return  point(MAX(p11.x, p22.x), MAX(p11.y, p22.y));

}