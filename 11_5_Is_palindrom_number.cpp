#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;
bool Is_palindrom_number(int num);



int main()
{
	cout << Is_palindrom_number(1321);


}

short count_digit_friqncy(int num, short digit)
{
	short counter = 0;
	while (num > 0)
	{
		if (num % 10 == digit)
			counter++;
		num = num / 10;
	}
	return counter;
}

int reverse_number(int num)
{
	int sum = 0;
	while (num > 0)
	{
		sum *= 10;
		sum += (num % 10);
		num = num / 10;
	}
	return sum;
}

bool Is_palindrom_number(int num)
{
	return num == reverse_number(num);
}