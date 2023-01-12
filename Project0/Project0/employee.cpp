#include "employee.h"
#include "manager.h"
#include<iostream>
using namespace std;
#include<fstream>;
employee::employee(string a,int b,string c)
{
	this->m_name = a;
	this->number = b;
	this->department = c;
}
void employee::show()
{
	cout << "worker'name:   " << this->m_name << endl;
	cout << "worker'code:   " << this->number << endl;
	cout << "worker'department:   " << this->department << endl;


}