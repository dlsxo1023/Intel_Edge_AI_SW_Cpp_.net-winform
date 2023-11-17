#include <iostream>
#include "haksang.h"
int main()
{
	haksang p1("JamesLee", 17, "전자공학", 3);
	p1.Show(); // haksang 클래스 Show 함수
	p1.setSub("국어", 90); p1.Show();
	p1.setSub("영어", 90); p1.Show();
	p1.setSub("수학", 90); p1.Show();
	p1.setSub("미술", 90); p1.Show();
}