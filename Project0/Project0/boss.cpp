#include"boss.h"
#include<iostream>
using namespace std;
#include<fstream>;
boss:: boss(string a, int b, string c)
{
	this->m_name = a;
	this->number = b;
	this->department = c;

}
void boss::show()
{
	cout << "worker'name:   " << this->m_name << endl;
	cout << "worker'code:   " << this->number << endl;
	cout << "worker'department:   " << this->department << endl;

}
