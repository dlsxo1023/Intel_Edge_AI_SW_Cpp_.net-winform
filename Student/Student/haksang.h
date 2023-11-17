#pragma once
#include <iostream>
class Subject
{
private:
	char* name = NULL;
public:
	int score;
	Subject() {};
	Subject(const char *Nam, int s = 0) : score(s) 
	{
		reSub(Nam);
	}
	Subject& reSub(const char* Nam)
	{
		if (name) delete name;
		name = new char[strlen(Nam) + 1];
		strcpy(name, Nam);
		return *this;
	}
	char* NAME() { return (char*)name; }
};
class person
{
protected:
	char* name = NULL; // 한글 한글자는 2byte 체계
public:	
	int Age;
	person(int age = 0) : Age(age) {} // NULL 생성자
	person(const char* Nam, int age) : Age(age)
	{
		rename(Nam);
	}
	person& rename(const char *Nam)
	{
		if(name) delete name;
		name = new char[strlen(Nam) + 1];
        strcpy(name, Nam);
		return *this;
	}
	void Show()
	{
		printf("%s(%d)", name, Age);
	}
	~person()
	{
		if(name) delete name;
	}
};
class haksang : public person
{
private:
	char* Major = NULL;
public:
	int Grade;
	int SubNum = 0;   // 수강과목 수
	Subject sub[10];   // kor, eng;
	
	haksang(const char *Nam, int age, const char *major, int grade) : person(Nam, age), Grade(grade)
	{
		
		reMajor(major);
	}
	~haksang()
	{
		if (Major) delete Major;
	}
	void setSub(const char* Nam, int sco)
	{
		if (SubNum > 10) return;
		//sub[SubNum].reSub(Nam);
		//sub[SubNum].score = sco;
		//SubNum++;
		sub[SubNum++].reSub(Nam).score = sco;
	}
	haksang& reMajor(const char* major)
	{
		if (Major) delete Major;
		Major = new char[strlen(major) + 1];
		strcpy(Major, major);
		return *this;
	}
	void Show()
	{
		((person*)this)->Show(); //홍길서(19)
		printf(":%s %d학년\n", Major, Grade); // :전자공학과 1학년
		for (int i = 0; i < SubNum; i++)
		printf("%s : %d\n", sub[i].NAME(), sub[i].score);
	}
};