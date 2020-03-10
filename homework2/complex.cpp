#include "complex.h"

 #include <iostream>


complexNum::complexNum()//eðer kullanýcý veri girmeden yollarsa default constructor'umuz a ve b deðerlerine 0 atayacak
{
	this->A = 0;
	this->b = 0;
	this->a = 0;
	kontrolIntDouble = true;
}

/*
conversion constructors
verilen deðerlere göre iþlem yaparlar
*/
complexNum::complexNum(const double& a)
{
	this->a = a;
	this->b = 0;
	this->A = 0;
}

complexNum::complexNum(const int& a)
{
	this->A = a;
	this->b = 0;
	this->a = 0;
	kontrolIntDouble = true;
}

complexNum::complexNum(const std::string& text)
{
	a = 0;
	b = 0;
	A = 0;
	this->text = text;
	deleteSpace();
	control();
	textDivide();
}

//2 parametreli constructors
complexNum::complexNum(const double& a, const int& b)
{
	this->a = a;
	this->b = b;
	this->A = 0;
}

complexNum::complexNum(const int& a, const int& b)
{
	this->A = a;
	this->b = b;
	this->a = 0;
	kontrolIntDouble = true;
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

void complexNum::control()
{
	for (int i = 0; i < kopyala.length(); i++)
	{
		if (!(kopyala[i] == '+' || kopyala[i] == '-'  || kopyala[i] == 'i' || (kopyala[i] >= '0' && kopyala[i] <= '9')))
		{
			throw(0);
		}
	}
}

void complexNum::textDivide()
{
	int arti_eksi_sira;
	int i_sira;
	
	
	if ((kopyala[0] == '+' || kopyala[0] == '-') && (kopyala[1] >= '0' && kopyala[1] <= '9'))
	{
		std::string isaretsiz_string;
		isaretsiz_string = &kopyala[1];
		arti_eksi_sira = isaretsiz_string.find('+');
		if (arti_eksi_sira == std::string::npos)
		{
			arti_eksi_sira = isaretsiz_string.find('-');
			if (arti_eksi_sira == std::string::npos)
			{
				A = 0;
				b = 0;
				a = 0;
				std::cout << "Hatali giris" << std::endl;
				kontrolIntDouble = true;
				return;
			}
		}

		for (int i = 0; i < arti_eksi_sira+1; i++)
		{
			aTut += kopyala[i];
		}
		arti_eksi_sira += 1;
	}

	else if(kopyala[1] >= '0' && kopyala[1] <= '9')
	{
		arti_eksi_sira = kopyala.find('+');
		if (arti_eksi_sira == std::string::npos)
		{
			arti_eksi_sira = kopyala.find('-');
			if (arti_eksi_sira == std::string::npos)
			{
				A = 0;
				b = 0;
				a = 0;
				std::cout << "Hatali giris" << std::endl;
				kontrolIntDouble = true;
				return;
			}
		}


		for (int i = 0; i < arti_eksi_sira; i++)
		{
			aTut += kopyala[i];
		}
	}



	i_sira = kopyala.find('i');
	if (i_sira == std::string::npos)
	{
		A = 0;
		b = 0;
		a = 0;
		std::cout << "Hatali giris" << std::endl;
		kontrolIntDouble = true;
		return;
	}


	for (int i = arti_eksi_sira ; i < i_sira; i++)
	{
		bTut += kopyala[i];
	}
	

	

	std::cout << aTut << std::endl;
	std::cout << bTut << std::endl;

}


void complexNum::print()
{
	if (kontrolIntDouble == false)
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
	else
	{
		if (b >= 0)
		{
			std::cout << "karmasik sayi: " << A << "+" << b << "i" << std::endl;
		}
		else
		{
			std::cout << "karmasik sayi: " << A << b << "i" << std::endl;
		}
	}
	
}






