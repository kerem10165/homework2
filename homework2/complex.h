#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <string>

class complexNum
{
public:
	
	complexNum();
	complexNum(const int& a);
	complexNum(const double& a);
	complexNum(const std::string& text);
	complexNum(const int& a, const int& b);
	complexNum(const double &a , const int &b);
	void print();

private:
	
	int A;
	double a;
	int b;

	bool kontrolIntDouble = false;//eðer int deðer girilirse true double girilirse false olur ve bunu print fonksiyonunda kullanýrýz
	
	std::string text = " ";
	std::string kopyala;
	std::string aTut;
	std::string bTut;
	
	void deleteSpace();
	void textDivide();
	void control();
};





#endif // !COMPLEX_H_
