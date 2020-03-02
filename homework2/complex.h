#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
#include <string>

class complexNum
{
public:
	
	complexNum();
	complexNum(const int& a);
	complexNum(const double& a);
	complexNum(const std::string& text);
	complexNum(const double &a , const double &b);
	void print();
	
private:
	double a;
	int b;
	std::string text = " ";
	bool c = false;
};





#endif // !COMPLEX_H_
