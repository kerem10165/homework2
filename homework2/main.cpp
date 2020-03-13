#include <iostream>
#include "complex.h"

using namespace std;


int main()
{
	try
	{
		complexNum sayi("+8-5i");
	}
	catch (int &a)
	{
		if (a == 0)
		{
			cout << "Hatali giris!!" << endl;
		}
	}

	


	return 0;
}
