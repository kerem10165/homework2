#include "complex.h"

#include <iostream>


complexNum::complexNum()//eðer kullanýcý veri girmeden yollarsa default constructor'umuz a ve b deðerlerine 0 atayacak
{
	this->a = 0;
	this->b = 0;
}

/*
conversion constructors
verilen deðerlere göre iþlem yaparlar
*/
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
	deleteSpace();
}

//2 parametreli constructor
complexNum::complexNum(const double& a, const double& b)
{
	this->a = a;
	this->b = b;
}

void complexNum::deleteSpace()
{
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == ' ');
		
		else
		{
			kopyala += text[i];
		}
	}
}

void complexNum::textDivide()
{
	for (int i = 0; i < kopyala.length; i++)
	{
		if (kopyala[i+1] == '+' || kopyala[i + 1] == '-')
		{
			if (kopyala[i] == 'i')
			{
				if (i == 0)
				{
					b = 1;
				}
				
				else if (i == 1)
				{
					if (kopyala[0] == '+')
					{
						arti_eksi_B = true;
					}
					else if (kopyala[0] == '-')
					{
						arti_eksi_B = false;
					}
				}
				
				else
				{
					if (kopyala[0] == '+')
					{
						arti_eksi_B = true;
						for (int j = 1; j < i; i++)
						{
							bTut += kopyala[j];
						}
					}

					else if(kopyala[0] == '-')
					{
						arti_eksi_B = false;
						for (int j = 1; j < i; i++)
						{
							bTut += kopyala[j];
						}
					}
				}
			}
			
			else
			{


			}

		}
	}
}

void complexNum::print()
{
	if (b >= 0)
	{
		std::cout << "karmasik sayi: " << a << "+" << b << "i" << std::endl;
	}
	else
	{
		std::cout << "karmasik sayi: " << a << b << "i" << std::endl;
	}
}






