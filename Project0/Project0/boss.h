#pragma once
#include<iostream>
using namespace std;
#include<fstream>;
#include"worker.h";
class boss :public worker
{public:
	boss(string a, int b, string c);
	~boss();
	 void show() ;
};

