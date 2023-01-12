#pragma once
#include<iostream>
using namespace std;
#include<fstream>;
#include"worker.h";
#include"work.h";
#include"employee.h";
#include"boss.h";
#include"manager.h";

class work
{
public:
	work();
	void menu();
	~work();
	int moment;
	worker** p_arr=new worker*[moment];
	void add();
	void stor();
	bool empty;
	int getnum();
	void test();
	void getback();
	void Return();
	void Delete();
	void change();
	void ordre();
	void destory();
};

