#include "work.h"
#include"boss.h"
#include<iostream>
using namespace std;
#include<fstream>;
#define fx "名单.txt";
void work::menu()
{
	cout << "0.退出管理程序" << endl;
	cout << "1.添加员工" << endl;
	cout << "2.显示职工信息" << endl;
	cout << "3.删除职工信息" << endl;
	cout << "4.修改职工信息" << endl;
	cout << "5.按编号排序" << endl;
	cout << "6.清空所有文档" << endl;

}

 work::work()
{
	
	 ifstream ofs;
	 ofs.open("名单.txt", ios::in);
	 if (!ofs.is_open())
	 {
		 cout << "The file does not exist！" << endl;
		 this->moment = 0;
		 this->p_arr = NULL;
		 this->empty = true;
		 ofs.close();
		 return;
	 }
	 
	 //this->getnum();
	 char ch;
	 ofs >> ch;
	 if (ofs.eof())
	 {
		 cout << "The file is empty" << endl;
		 this->moment = 0;
		 this->p_arr = NULL;
		 this->empty = true;
		 return;
	 }
	 this->moment = this->getnum();
 }

 int work::getnum()
 {
	 ifstream ifs;
	 ifs.open("名单.txt", ios::in);
	
	 string name;
	 int num=0;
	 string department;
	 int counting = 0;
	 while (ifs >> name && ifs >> num && ifs >> department)
	 {
		 counting++;
	 }
	 ifs.close();
	 return counting;
 }


 void  work::add()
 {
	 worker** newspace = NULL;

	 int addnum = 0; 
		 cout << "How many workers would you like to add? "<< endl;
	 cin >> addnum;
	 int newsize = this->moment + addnum;
	 if (addnum > 0)
	 {
		 
		 worker** newspace = new worker * [newsize];
		 if (this->p_arr != NULL)
		 {
			 for (int i=0; i < this->moment; i++)
			 {
				 newspace[i] = p_arr[i];
			 }


		 }
		 for (int i=0;i<addnum ;i++)
		 {
			 string name;
			 int num;
			 string department;
			 cout << "piease write the" << i +1<< "'s name" << endl;
			 cin >> name;
			 cout << "piease write the" << i+1 << "'s number" << endl;
			 cin >> num;
			 cout << "piease write the" << i+1 << "'s department" << endl;
			 cin >> department;
			 cout << "choose the position" << endl;
			 int choice = 0;
			
			 worker* k = NULL;
			 cout << "1.empioyee" << endl;
			 cout << "2.manager" << endl;
			 cout << "3.boss" << endl;
			 cin >> choice;
			 switch (choice)
			 {
				
			 case 1:
				 k = new employee(name, num, department);
				 break;
			 case 2:
				 k = new manager(name, num, department);
				 break;
			 case 3:;
				 k = new boss(name, num, department);
				 break;
			 default:
				 cout << "Are you fucking blind" << endl;
				 break;
			 }
			 newspace[moment + i]=k;
			 
		 }
		 delete[]p_arr;
		 this->p_arr = newspace;
		 this->moment = newsize;
		 this->stor();
		 this->empty = false;
	 }
	 
	 else
	 {
		cout << "you just write a wrong number" << endl;
	 }
 }
 void work::stor()
 {
	 ofstream ofs;
	 ofs.open("名单.txt", ios::out);
	 for (int i = 0; i < this->moment;i++)
	 {
		 ofs << this->p_arr[i]->m_name<<" "
			 << this->p_arr[i]->number <<" "
			 << this->p_arr[i]->department 
			 << endl;

	 }

	 ofs.close();
 }
 void work::test()
 {
	 if (this->p_arr == NULL)
	 {
		 cout << "The file is empty " << endl;
	 }
	 else 
	 {
		 for (int i = 0; i < this->moment; i++)
		 {
			 p_arr[i]->show();
		 };
	 }
	
 }
 void work::getback()
 {

	 if (p_arr != NULL)
	 {
		 delete[] p_arr;
	 }

 }


 void work::Return()
 {
	 if (!this->empty)
	 {
		 this->p_arr = new worker * [moment];

		 string name;
		 int num = 0;
		 string department;
		 worker* w = NULL;
		 int marker = 0;
		 ifstream ofs;
		 ofs.open("名单.txt", ios::in);
		 while (ofs >> name && ofs >> num && ofs >> department)
		 {
			 if (0 < num < 10)
			 {
				 w = new employee(name, num, department);
			 }
			 if (10 < num < 20)
			 {
				 w = new manager(name, num, department);
			 }
			 if (20 < num < 30)
			 {
				 w = new boss(name, num, department);
			 }

			 this->p_arr[marker] = w;
			 marker++;

		 }
		 ofs.close();
		 this->empty = false;
	 }


 }
 void work::Delete()
 {
	 if (this->empty)
	 {
		 cout << "The file is empty" << endl;
		 return;
	 }
	 int a;
	 cout << "Please write the worker's code" << endl;
	 cin >> a;
	 string name;
	 int num = 0;
	 string department;
	 int b = 0;
	 ifstream ifs;
	 ifs.open("名单.txt", ios::in);
	 while (ifs >> name && ifs >> num && ifs >> department)
	 {
		 if (num == a)
		 {
			 for (int i = b; i++; i < this->moment)
			 {
				 this->p_arr[i] = this->p_arr[i + 1];
			 }
			 this->moment--;
		 }
		 b++;
	 }
	 if (b > this->moment)
	 {
		 cout << "The person is not on the file." << endl;
	 }
 }
 void work::change()
 {
	 if (this->empty)
	 {
		 cout << "The file is empty" << endl;
		 return;
	 }
	 int a;
	 cout << "Please write the worker's code if you want to change his infornation " << endl;
	 cin >> a;
	 string name=" ";
	 int num = 0;
	 string department=" ";
	 int b = 0;
	 ifstream ifs;
	 ifs.open("名单.txt", ios::in);
	 while (ifs >> name && ifs >> num && ifs >> department)
	 {
		 if (num == a)
		 {
			 cout << "Please rewrite the worker's name" << endl;
			 string N;
			 cin >> N;
			 this->p_arr[b]->m_name = N;
			 cout << "Please rewrite the worker's code" << endl;
			 int Num = 0;
			 cin >> Num;
			 this->p_arr[b]->number = Num;
			 cout << "Please rewrite the worker's department" << endl;
			 string D;
			 cin >> D;
			 this->p_arr[b]->department = D;
		 }
		 b++;
	 }
	 if (b > this->moment+1)
	 {
		 cout << "The person is not on the file." << endl;
	 }
 }
 void work::ordre()
 {
	 if (this->empty)
	 {
		 cout << "The file is empty" << endl;
		 return;
	 }
	 int slection = 0;
	 cin >> slection;
	 cout << "In which kind of way would you like to chose to permute them" << endl;
	 cout << "1.up" << endl;
	 cout << "2.down" << endl;
	 
	 for (int i = 0; i < this->moment; i++)
	 {
		 int m = i;
		 if (slection == 1)
		 {
			 for (int j = i + 1; j < this->moment; j++)
			 {
				 if (this->p_arr[m] > this->p_arr[j])
				 {
					 m = j;
				 }
			 }
		 }
		 else
		 {
			 for (int j = i + 1; j < this->moment; j++)
			 {
				 if (this->p_arr[m] < this->p_arr[j])
				 {
					 m = j;
				 }
			 }
		 }
		 if (i!= m)
		 {
			 worker* temp = NULL;
			 p_arr[m] = temp;
			 p_arr[m] = p_arr[i];
			 p_arr[i] = temp;
		 }
	 }
 }
 void work::destory()
 {
	 cout << "Are you sure you want to empty the file?" << endl;
	 cout << "1.Yes" << endl;
	 cout << "2.No" << endl;
	 int c = 0;
	 cin >> c;
	 if (c == 1)
	 {
		 ofstream ofs("名单.txt", ios::trunc);
		 ofs.close();


		 if(this->p_arr!=NULL)
		 {
			 for (int i = 0; i < this->moment; i++)
			 {
				 this->p_arr[i] = NULL;
				 delete this->p_arr[i];
			 }
			 delete[]this->p_arr;
			 this->p_arr = NULL;
			 this->moment = 0;
			 this->empty = true;
			 cout << "The file is empty now" << endl;
		 }
		 
	 }
	 else
	 {
		 return;
	 }

 }

