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
	counter();
	tokenString();
	convertNum();
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
	if (kopyala.length() == 0)
	{
		throw(0);
	}
	for (int i = 0; i < kopyala.length(); i++)
	{
		if (!(kopyala[i] == '+' || kopyala[i] == '.' || kopyala[i] == '-'  || kopyala[i] == 'i' || (kopyala[i] >= '0' && kopyala[i] <= '9')))
		{
			throw(0);
		}
	}
}

void complexNum::counter()
{
	for  (int i = kopyala.length()-1; i >= 0 ; i--)
	{
		if (kopyala[i] == 'i')
		{
			i_var_mi = true;
			if (kopyala[i-1] >= '0' && kopyala[i - 1] <= '9')
			{
				i_onunde_sayi_var_mi = true;
			}
		}
		if ((kopyala[i] == '+' || kopyala[i] == '-') && i_var_mi == true)
		{
			if (kopyala[i - 1] >= '0' && kopyala[i - 1] <= '9')
			{
				sayi_var_mi = true;
			}
		}
	}
	if (i_var_mi == false)
	{
		if ((kopyala[0] >= '0' && kopyala[0] <= '9') || (kopyala[1] >= '0' && kopyala[1] <= '9'))
		{
			sayi_var_mi = true;
		}
	}

}

void complexNum::tokenString()
{
	int arti_eksi_tutucu = 0;

	if (i_var_mi == true)
	{
		if (i_onunde_sayi_var_mi == false)
		{
			int i_isaret = kopyala.find('i') - 1;
			if (kopyala[i_isaret] == '+')
			{
				b = 1;
			}
			else
			{
				b = -1;
			}
			
			if (sayi_var_mi == true)
			{
				if (kopyala[0] == '+' || kopyala[0] == '-')
				{
					for (int i = 1; i < kopyala.length() - 1; i++)
					{
						if (kopyala[i] == '+' || kopyala[i] == '-')
						{
							arti_eksi_tutucu = i;
							break;
						}
					}
				}
				else
				{
					for (int i = 0; i < kopyala.length() - 1; i++)
					{
						if (kopyala[i] == '+' || kopyala[i] == '-')
						{
							arti_eksi_tutucu = i;
							break;
						}
					}
				}

				for (int i = 0; i < arti_eksi_tutucu; i++)
				{
					aTut += kopyala[i];
				}
			}
			else
			{
				A = 0;
				kontrolIntDouble = true;
			}
		}

		
		else
		{
			if (sayi_var_mi == false)
			{
				for (int i = 0; i < kopyala.find('i'); i++)
				{
					bTut += kopyala[i];
				}
			}
			else
			{
				if (kopyala[0] == '+' || kopyala[0] == '-')
				{
					for (int i = 1; i < kopyala.length()-1; i++)
					{
						if (kopyala[i] == '+' || kopyala[i] == '-')
						{
							arti_eksi_tutucu = i;
							break;
						}
					}
				}
				
				else
				{
					for (int i = 0; i < kopyala.length() - 1; i++)
					{
						if (kopyala[i] == '+' || kopyala[i] == '-')
						{
							arti_eksi_tutucu = i;
							break;
						}
					}
				}

				for (int i = 0; i < arti_eksi_tutucu; i++)
				{
					aTut += kopyala[i];
				}

				for (int i = arti_eksi_tutucu; i < kopyala.find('i'); i++)
				{
					bTut += kopyala[i];
				}

			}
		}
		
		if (sayi_var_mi == false)
		{
			A = 0;
			kontrolIntDouble = true;
		}
	}

	else
	{
		if (sayi_var_mi == true)
		{
			for (int i = 0; i < kopyala.length(); i++)
			{
				aTut += kopyala[i];
			}
		}

		else
		{
			A = 0;
			kontrolIntDouble = true;
		}
	}
}

void complexNum::convertNum()
{
	if (i_var_mi == true && i_onunde_sayi_var_mi == true)
	{
		b = atoi(bTut.c_str());
	}
	
	bool doubleKontrol = false;

	for (int i = 0; i < aTut.length(); i++)
	{
		if (aTut[i] == '.')
		{
			doubleKontrol = true;
		}
	}

	if (doubleKontrol == true)
	{
		a = atof(aTut.c_str());
		kontrolIntDouble = false;
	}
	else
	{
		A = atoi(aTut.c_str());
		kontrolIntDouble = true;
	}
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






