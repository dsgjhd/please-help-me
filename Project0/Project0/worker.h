#pragma once

#include<iostream>
using namespace std;
#include<fstream>;
#define f "����.txt";
class worker
{
public:
	string m_name;
	int number;
	string department;
	virtual void show() = 0;

};

