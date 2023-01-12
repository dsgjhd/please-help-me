#pragma once
#include"worker.h";
class employee:public worker
{public:
	employee(string a, int b, string c);
	~employee();
	void show();
};

