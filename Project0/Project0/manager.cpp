#include "manager.h"
#include<iostream>
using namespace std;
#include<fstream>;
manager::manager(string a, int b, string c)
{
	this->m_name = a;
	this->number = b;
	this->department = c;
}
void manager::show()
{
	cout << "worker'name:   " << this->m_name << endl;
	cout << "worker'code:   " << this->number << endl;
	cout << "worker'department:   " << this->department << endl;

}