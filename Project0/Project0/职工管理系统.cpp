#pragma once
#include<iostream>
using namespace std;
#include<fstream>;
#include"worker.h";
#include"work.h";
#include"employee.h";
#include"boss.h";
#include"manager.h";
#define f "Ãûµ¥.txt";
int main()
{
	work*x=new work;
while (true)
{
	x->menu();
	int a=0;
	cin >> a;
	switch (a)
	{case 0:
	system("pause");
	system("cls")
		;break;
	case 1:
	x->Return();
	x->getnum();
	x->add();
	x->getback();
	system("pause");
	system("cls")
		; break;
	case 2:
		x->Return();
		x->test();
		x->getback();
		system("pause");
		system("cls") 
		; break;
	case 3:
		
		x->Return();
		x->Delete();
		x->stor();
		x->getback();
		system("pause");
		system("cls");
		break;
	case 4
	   :
		x->Return();
		x->change();
		x->stor();
		x->test();
		x->getback();
		system("pause");
		system("cls");  
		break;
	case 5:
		
		x->Return();
		x->ordre();
		x->getback();
		system("pause");
		system("cls");
		break;
	case 6:
		
		x->Return();
		x->destory();
		system("pause");
		system("cls");
		; break;
		
	default:
		cout << "There are only limited choices for you to choose" << endl;
		break;
	}


}

	system("pause");
	return 0;
}
