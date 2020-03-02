#include "complex.h"

complexNum::complexNum()//eðer kullanýcý veri girmeden yollarsa default constructor'umuz a ve b deðerlerine 0 atayacak
{
	this->a = 0;
	this->b = 0;
}

complexNum::complexNum(const double& a)
{
	this->a = a;
	this->b = 0;
}

complexNum::complexNum(const int& a)
{
	this->a = a;
	this->b = 0;
}

complexNum::complexNum(const std::string& text)
{
	a = 0;
	b = 0;
	this->text = text;
}

complexNum::complexNum(const double& a, const double& b)
{
	this->a = a;
	this->b = b;
}

void complexNum::print()
{

}

