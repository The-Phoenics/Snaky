#include <Windows.h>
#include <iostream>

int main()
{
	while (true)
	{
		Sleep(50);
		if (GetAsyncKeyState(0x41))
		{
			std::cout << "A clicked\n";
			//break;
		}
		if (GetAsyncKeyState(0x57))
		{
			std::cout << "W clicked\n";
			//break;
		}
		if (GetAsyncKeyState(0x53))
		{
			std::cout << "S clicked\n";
			//break;
		}
		if (GetAsyncKeyState(0x44))
		{
			std::cout << "D clicked\n";
			//break;
		}

		int a = 10;
		std::cout << a << std::endl;
	}
}