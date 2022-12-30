#include <iostream>
#include "Header.h"
//#include"Source.cpp"
using namespace std;
int main() {
	int m1 = 3; // Размеры стеков
	int m2 = 5;
	int m3 = 10;
	dmassiv massiv{ m1,m2,m3 };
	alloc(&massiv);
	for (int i = 0; i < m1; i++)
	{
		add(1, i, &massiv);


	}
	print(1, &massiv);
	for (int i = 0; i < m2; i++)
	{
		add(2, i, &massiv);
	}
	print(2, &massiv);
	for (int i = 0; i < m3; i++)
	{
		add(3, i, &massiv);

	}
	print(3, &massiv);

	pop(1, &massiv);
	pop(1, &massiv);
	pop(1, &massiv);
	pop(1, &massiv);
	add(1, 1, &massiv);
	add(1, 1, &massiv);
	add(1, 1, &massiv);
	print(1, &massiv);


	for (int i = 0; i < (m1 + m2 + m3); i++) cout << massiv.massiv[i] << "-";


	return 0;

}