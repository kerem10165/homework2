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
	complexNum(const double &a , const double &b);
	void deleteSpace();
	void textDivide();
	void print();

private:
	double a;
	int b;
	std::string aTut = " ";
	std::string bTut = " ";
	std::string text = " ";
	std::string kopyala;
	bool kontrol = false;
	bool arti_eksi_A = true;
	bool arti_eksi_B = true;//artý ise true eksi ise false döner
};





#endif // !COMPLEX_H_
