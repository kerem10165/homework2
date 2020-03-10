#include <iostream>
#include "complex.h"

using namespace std;


int main()
{
	try
	{
		complexNum sayi("+2i");
	}
	catch (int &a)
	{
		if (a == 0)
		{
			cout << "Hata!!" << endl;
		}
	}
	

	return 0;
}
