#include <iostream>
#include "Classes.h"
int main()
{
    Rect r1;
    Rect r2(10, 10, 30, 30);
    Rect r3(Point(20, 20), Point(40, 40));
    r1.Show("r1");
    r2.Show("r2");
    r3.Show("r3");
    double d1 = (r2 + r3).Show("[r2 + r3]").Area(); printf("면적은 %.2f 입니다\n", d1);
    double d2 = (r2 - r3).Show("[r2 - r3]").Area(); printf("면적은 %.2f 입니다\n", d2);
    double d3 = (r3 - r2).Show("[r3 - r2]").Area(); printf("면적은 %.2f 입니다\n", d3);
    double d4 = (r2 * r3); printf("(r2 * r3)의 면적은 %.2f 입니다\n", d4);
}

