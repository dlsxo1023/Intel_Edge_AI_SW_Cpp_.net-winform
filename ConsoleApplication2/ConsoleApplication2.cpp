// ConsoleApplication2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#define MIN(x, y)  (((x) > (y)) ? (y) : (x))
#define MAX(x, y)  (((x) < (y)) ? (y) : (x))

class point
{
private:     //접근지시자 ( 외부 참조 불가)
      
public:  //접근지시자  (외부 참조 가능)
    int x, y;  //맴버 변수 선언. //객체의 좌표
    point(int x = 0, int y = 0) : x(x), y(y)  // 이니셜라이져
        //생성자 정의 //아무런 타입이 없는 함수//외부접근이 필요하기에 public 접근지시자 전에 미리 사용
        //함수적 특성을 가지고 있음(default, overload 등)
    {
        //x = x1; y = y1; 
    }
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

void swap_r(int &a, int &b)   // Call-by-Reference (using ref. variables) // 함수 매개변수 속 레퍼런스 변수 호출시 메인함수 변수로 초기화
{
    int t(a);
    printf("[swap_r]초기값 a = %d  b = %d\n", a, b);
    a = b; b = t;
    printf("[swap_r]결과값 a = %d  b = %d\n", a, b);
}

int main()
{
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

    int a(10), b(20);  //a = 10; b = 20;
    printf("초기값 a = %d  b = %d\n", a, b);
    swap_r(a, b);
    printf("결과값 a = %d  b = %d\n", a, b); // 이니셜라이져로 변수 초기화 하고 그 밑에 변수 값 바꿀시 고전적으로 대입

    //int n = 1234;
    //int& m = n;
    //printf("[레퍼런스 변수 테스트] n = %d, m = %d\n", n, m);
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
