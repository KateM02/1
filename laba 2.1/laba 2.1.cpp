
#include "matrix.h"
#include <iostream>
#include <stdio.h>
#include<conio.h>


int get_key()
{
	int key = _getch();
	if ((key == 0) || (key == 224))
		key = _getch();
	return key;
}

//void examination(int value)
//{
//	
//	std::cout << "Please enter value: " << std::endl;
//	while (!(std::cin >> value)) 
//	{ //Поскольку значение является int, (cin >> value) будет истинным только в том случае, если пользователь введет допустимое значение, которое может быть помещено в int
//		//std::cin.clear();
//		std::cout << "Please enter a valid value:" << std::endl;
//		std::cin >> value;
//	}
//}
matrix input_values()
{
	int n = 0, m = 0;
	do
	{
		std::cout << "Input N:";
		//examination(n);
		std::cin >> n;
	} while (n <= 0);
	do
	{
		std::cout << "Input M:";
		std::cin >> m;
		//examination(m);
	} while (m <= 0);
	std::cout << "Input values:\n";
	matrix a(n, m);
	std::cin >> a;
	std::cout << a;
	return a;
}
int menu()
{
	std::cout << "\n1.Input matrix" << std::endl << "2.Perform math operations" << std::endl << "3.Exit\n";
	int key = get_key();
	if (key == 27 || key >= 49 && key <= 54 || key == 75 || key == 77 || key == 13)
		return key;
}
int menu_matematical_operation()
{
	std::cout << "\n1.matrix addition\n" << "2.subtraction of matrices\n" << "3.matrix multiplication\n" << "4.multiplication by a number\n" << "5.division by number\n" << "6.comparison of matrices\n" << "7.index appeal\n" << "8.finding the trace of a matrix\n";
	int key = get_key();
	if (key == 27 || key >= 49 && key <= 54 || key == 75 || key == 77 || key == 13)//if (key >= '1' && key <= '8')
		return key;
}

void matematical_operation(matrix a)
{
	try
	{
		matrix b;
		int choose = menu_matematical_operation();
		switch (choose)
		{
		case '1':
		{
			b = input_values();
			std::cout << "Result:" << std::endl << a + b;
		}
		break;
		case '2':
		{
			b = input_values();
			std::cout << "Result:" << std::endl << a - b;

		}
		break;
		case '3':
		{
			b = input_values();
			std::cout << "Result:" << std::endl << a * b;
		}
		break;
		case '4':
		{
			double c;
			std::cout << "Input the number:";
			std::cin >> c;
			std::cout << "Result:" << std::endl << a * c << std::endl;
		}
		break;
		case '5':
		{
			double c;
			std::cout << "Input the number:";
			std::cin >> c;
			std::cout << "Result:" << std::endl << a / c << std::endl;
		}
		break;
		case '6':
		{
			b = input_values();
			if (a == b)
			{

				std::cout << "Matrices are equal";
			}
			if (a != b)
			{
				std::cout << "Matrices are not equal";
			}
		}
		break;
		case '7':
		{
			std::cout << "Enter which element of the matrix you want to find\n";
			int x, y;
			std::cout << "Input x";
			std::cin >> x;
			std::cout << "Input y";
			std::cin >> y;
			std::cout << "Result:" << a(x, y) << std::endl;

		}
		break;
		case '8':
		{
			double c = a.finding_a_trace();
			std::cout << "Result:" << c << std::endl;
		}
		break;
		default:
			break;
		}
	}
	catch (std::exception err)
	{
		std::cerr << "error: " << err.what() << std::endl;
	}
}

int main()
{
	matrix a;
	bool f = true;
	while (f)
	{
		int choose = menu();
		switch (choose)
		{
		case '1':
		{
			a = input_values();
		}
		break;
		case '2':
		{
			matematical_operation(a);
		}
		break;
		case '3':
		{
			f = false;
		}
		default:
			break;
		}
	}
	return 0;
}