#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

int main(void)
{
	bitset<8> bit;

//	bit.set();

	bit = 255;

	cout << bit << endl;

	int num1 = 5;
	int num2 = 32;

	bitset<6> temp;

	temp = num1 ^ num2;
	cout << temp.count() << endl;

	return 0;
}
