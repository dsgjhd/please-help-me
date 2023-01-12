#pragma once
//using namespace std;
//#include<fstream>;
#include"worker.h";
class manager :public worker
{public:
	
	manager(string a, int b, string c);
	~manager();
	void show();
};

